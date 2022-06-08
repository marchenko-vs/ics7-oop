#include <QDebug>

#include "cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    status_ = STANDING;
    target_exists_ = false;

    QObject::connect(this, SIGNAL(RidingSignal()),
                     this, SLOT(RidingSlot()));
    QObject::connect(&riding_timer_, SIGNAL(timeout()),
                     this, SLOT(RidingSlot()));
    QObject::connect(this, SIGNAL(OpenDoorsSignal()),
                     &doors_, SLOT(OpeningSlot()));
    QObject::connect(&doors_, SIGNAL(ClosedSignal()),
                     this, SLOT(RidingSlot()));
}

void Cabin::RidingSlot()
{
    if (target_exists_)
    {
        if (status_ == GOT_TARGET || status_ == STANDING)
            status_ = RIDING;
        else
            current_floor_ += direction_;

        qDebug() << "The elevator is on floor " << current_floor_;

        if (current_floor_ != needed_floor_)
            riding_timer_.start(RIDING_TIME);

        emit FloorPassedSignal(current_floor_, direction_);
    }
}

void Cabin::GotTargetSlot(ssize_t& needed_floor, ssize_t& current_floor)
{
    if (status_ == STANDING)
    {
        status_ = GOT_TARGET;
        target_exists_ = true;
        SaveState(needed_floor, current_floor);
        emit RidingSignal();
    }
}

void Cabin::StoppedSlot(bool is_last, ssize_t current_floor, ssize_t needed_floor)
{
    if (status_ == RIDING || status_ == STANDING)
    {
        status_ = STANDING;
        SaveState(needed_floor, current_floor);

        qDebug() << "The elevator stopped on floor" << current_floor_;

        if (is_last)
            target_exists_ = false;

        riding_timer_.stop();
        emit OpenDoorsSignal();
    }
}

void Cabin::SaveState(const ssize_t& needed_floor, const ssize_t& current_floor)
{
    needed_floor_ = needed_floor;
    current_floor_ = current_floor;
    direction_ = current_floor_ > needed_floor_ ? DOWN : UP;
}
