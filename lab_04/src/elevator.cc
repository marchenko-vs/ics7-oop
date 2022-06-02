#include "elevator.h"
#include "cabin.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    this->controller_.setStyleSheet("background-color:skyblue;");

    QObject::connect(&cabin_, SIGNAL(FloorPassed(ssize_t, Direction)), &controller_, SLOT(PassedFloor(ssize_t, Direction)));
    QObject::connect(&controller_, SIGNAL(NewTargetSignal(ssize_t)), &cabin_, SLOT(CabinGetsTarget(ssize_t)));
    QObject::connect(&controller_, SIGNAL(StoppedSignal(bool, ssize_t)), &cabin_, SLOT(CabinStopped(bool, ssize_t)));
}

QWidget *Elevator::widget()
{
    return &this->controller_;
}
