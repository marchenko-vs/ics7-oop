#include <QPalette>

#include "elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    controller_.setStyleSheet("background-color:skyblue;");

    QObject::connect(&cabin_, SIGNAL(FloorPassedSignal(ssize_t,Direction)),
                     &controller_, SLOT(FloorPassedSlot(ssize_t,Direction)));
    QObject::connect(&controller_, SIGNAL(GotTargetSignal(ssize_t&,ssize_t&)),
                     &cabin_, SLOT(GotTargetSlot(ssize_t&,ssize_t&)));
    QObject::connect(&controller_, SIGNAL(CabinStoppedSignal(bool,ssize_t,ssize_t)),
                     &cabin_, SLOT(StoppedSlot(bool,ssize_t,ssize_t)));
}

QWidget *Elevator::widget()
{
    return &controller_;
}
