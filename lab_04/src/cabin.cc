#include <QDebug>

#include "cabin.h"

Cabin::Cabin(QObject *parent)
{
    this->status_ = FREE;
    this->current_floor_ = 1;
    this->desired_floor_ = 1;
    this->direction_ = STOP;

    QObject::connect(&move_timer_, SIGNAL(timeout()), this, SLOT(CabinMoving()));

    QObject::connect(this, SIGNAL(MovingSignal()), this, SLOT(CabinMoving()));
    QObject::connect(this, SIGNAL(StoppedSignal(bool, ssize_t)), this, SLOT(CabinStopped(bool, ssize_t)));
    QObject::connect(this, SIGNAL(OpenDoorsSignal()), &door_, SLOT(Opening()));
    QObject::connect(&door_, SIGNAL(ClosedSignal()), this, SLOT(CabinMoving()));
}

void Cabin::CabinMoving()
{
    if (status_ == MOVING || status_ == GET)
    {
        this->status_ = MOVING;
        move_timer_.start(MOVING_TIME);

        qDebug() << "Elevator is riding. Current floor is: " << this->current_floor_;
        emit FloorPassed(current_floor_, this->direction_);

        if (current_floor_ != desired_floor_)
        {
            this->direction_ = current_floor_ > desired_floor_ ? DOWN : UP;
            this->current_floor_ = current_floor_ > desired_floor_ ? current_floor_ - 1 : current_floor_ + 1;
        }
    }
}

void Cabin::CabinStopped(bool is_last, ssize_t new_floor)
{
    if (is_last)
    {
        this->status_ = FREE;
    } else
    {
        this->status_ = GET;
        this->desired_floor_ = new_floor;
    }

    this->move_timer_.stop();
    emit OpenDoorsSignal();
}

void Cabin::CabinGetsTarget(ssize_t floor)
{
    this->status_ = GET;
    this->desired_floor_ = floor;

    if (this->current_floor_ == this->desired_floor_)
    {
        emit FloorPassed(current_floor_, this->direction_);
    }
    else
    {
        this->direction_ = desired_floor_ > current_floor_ ? UP : DOWN;
        emit MovingSignal();
    }
}
