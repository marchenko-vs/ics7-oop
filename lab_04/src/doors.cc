#include "doors.h"
#include "controller.h"

Door::Door()
{
    status_ = CLOSED;

    QObject::connect(&opening_timer_, SIGNAL(timeout()),
                     this, SLOT(OpenSlot()));
    QObject::connect(&open_timer_,  SIGNAL(timeout()),
                     this, SLOT(ClosingSlot()));
    QObject::connect(&closing_timer_, SIGNAL(timeout()),
                     this, SLOT(ClosedSlot()));
}

void Door::OpeningSlot()
{
    if (status_ == CLOSED || status_ == CLOSING)
    {
        qDebug() << "Doors are opening.";

        if (status_ == CLOSED)
        {
            status_ = OPENING;
            opening_timer_.start(DOORS_TIME);
        }
        else
        {
            status_ = OPENING;
            auto timer = closing_timer_.remainingTime();
            closing_timer_.stop();
            opening_timer_.start(DOORS_TIME - timer);
        }
    }
}

void Door::OpenSlot()
{
    if (status_ == OPENING)
    {
        status_ = OPEN;

        qDebug() << "Doors are open!";

        open_timer_.start(DOORS_TIME);
    }
}

void Door::ClosingSlot()
{
    if (status_ == OPEN)
    {
        status_ = CLOSING;

        qDebug() << "Doors are closing.";

        closing_timer_.start(DOORS_TIME);
    }
}

void Door::ClosedSlot()
{
    if (status_ == CLOSING)
    {
        status_ = CLOSED;

        qDebug() << "Doors are closed!";

        emit ClosedSignal();
    }
}
