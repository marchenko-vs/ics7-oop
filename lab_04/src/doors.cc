#include <QDebug>

#include "doors.h"
#include "controller.h"

Doors::Doors()
{
    this->status_ = CLOSED;

    QObject::connect(&opening_timer_, SIGNAL(timeout()), this, SLOT(Opened()));
    QObject::connect(&opened_timer_,  SIGNAL(timeout()), this, SLOT(Closing()));
    QObject::connect(&closing_timer_, SIGNAL(timeout()), this, SLOT(Closed()));
}

void Doors::Opening()
{
    if (status_ == CLOSED || status_ == CLOSING)
    {
        qDebug() << "Doors are opening.";

        if (this->status_ == CLOSED)
        {
            this->status_ = OPENING;
            this->opening_timer_.start(DOORS_TIME);
        }
        else
        {
            this->status_ = OPENING;
            auto timer = closing_timer_.remainingTime();
            closing_timer_.stop();
            this->opening_timer_.start(DOORS_TIME - timer);
        }
    }
}

void Doors::Opened()
{
    if (status_ == OPENING)
    {
        this->status_ = OPEN;
        qDebug() << "Doors have been opened!";
        this->opened_timer_.start(DOORS_TIME);
    }
}

void Doors::Closing()
{
    if (status_ == OPEN)
    {
        this->status_ = CLOSING;
        qDebug() << "Doors are closing.";
        this->closing_timer_.start(DOORS_TIME);
    }
}

void Doors::Closed()
{
    if (status_ == CLOSING)
    {
        this->status_ = CLOSED;
        qDebug() << "Doors have been closed!";
        emit ClosedSignal();
    }
}
