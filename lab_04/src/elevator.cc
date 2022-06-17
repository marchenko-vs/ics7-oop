#include <QPalette>

#include "elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    controller_.setStyleSheet("background-color:skyblue;");

    QObject::connect(&cabin_, SIGNAL(FloorPassedSignal(ssize_t, Direction)), // defined in controller module
                     &controller_, SLOT(FloorPassedSlot(ssize_t, Direction))); // implemented in controller module

    QObject::connect(&controller_, SIGNAL(GotTargetSignal(ssize_t&, ssize_t&)), // defined in controller module
                     &cabin_, SLOT(GotTargetSlot(ssize_t&, ssize_t&))); // implemented in cabin module

    QObject::connect(&controller_, SIGNAL(CabinStoppedSignal(bool, ssize_t, ssize_t)), // defined in controller module
                     &cabin_, SLOT(StoppedSlot(bool, ssize_t, ssize_t))); // implemented in cabin module
}

QWidget *Elevator::widget()
{
    return &controller_;
}
