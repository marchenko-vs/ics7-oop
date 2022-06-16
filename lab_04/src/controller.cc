#include "controller.h"

#include <cstdlib>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    layout_ = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(layout_.get());

    QObject::connect(this, SIGNAL(FloorPassedSignal(ssize_t, Direction)), // here
                     this, SLOT(FloorPassedSlot(ssize_t, Direction))); // here

    QObject::connect(this, SIGNAL(ControllerStoppedSignal()), // here
                     this, SLOT(ControllerStoppedSlot())); // here

    status_ = FREE;
    current_floor_ = 1;
    needed_floor_ = 1;
    direction_ = STOP;

    for (std::size_t i = 0; i < NUMBER_OF_FLOORS; i++)
    {
        std::shared_ptr<Button> btn(new Button);
        btn->SetFloor(NUMBER_OF_FLOORS - i);
        btn->setText(QString::number(NUMBER_OF_FLOORS - i));

        buttons_.insert(buttons_.begin(), btn);
        layout_->addWidget(btn.get());

        visited_floors_.push_back(true);

        QObject::connect(btn.get(), SIGNAL(PressedSignal(ssize_t)), // linking every button
                         this, SLOT(NewTargetSlot(ssize_t)));       // with a signal
    }
}

void Controller::NewTargetSlot(ssize_t floor)
{
    visited_floors_[floor - 1] = false;

    if (status_ != GOT_TARGET)
    {
        status_ = GOT_TARGET;
        TargetExists(floor);
        needed_floor_ = floor;

        if (current_floor_ == needed_floor_)
            emit FloorPassedSignal(current_floor_, direction_); // here
        else
        {
            direction_ = needed_floor_ > current_floor_ ? UP : DOWN;

            emit GotTargetSignal(needed_floor_, current_floor_); // in elevator module
        }
    }
}

void Controller::ControllerStoppedSlot()
{
    if (status_ == BUSY)
    {
        status_ = FREE;

        emit CabinStoppedSignal(true, current_floor_); // in elevator module
    }
}

void Controller::FloorPassedSlot(ssize_t floor, Direction direction)
{
    if (status_ == GOT_TARGET || status_ == BUSY)
    {
        status_ = BUSY;
        current_floor_ = floor;
        direction_ = direction;

        if (current_floor_ == needed_floor_)
        {
            buttons_[floor - 1]->NotPressedSlot();
            visited_floors_[floor - 1] = true;

            if (TargetExists(needed_floor_))
                emit CabinStoppedSignal(false, current_floor_, needed_floor_); // in elevator module
            else
                emit ControllerStoppedSignal(); // in controller module
        }
    }
}

bool Controller::TargetExists(ssize_t& new_floor)
{
    int direction = direction_ != STOP ? direction_ : DOWN;

    for (ssize_t i = current_floor_ - 1; i >= 0 && i < NUMBER_OF_FLOORS; i += direction)
    {
        if (!visited_floors_[i])
        {
            new_floor = i + 1;

            return true;
        }
    }

    for (ssize_t i = current_floor_ - 1; i >= 0 && i < NUMBER_OF_FLOORS; i += -direction)
    {
        if (!visited_floors_[i])
        {
            new_floor = i + 1;

            return true;
        }
    }

    return false;
}

Direction Controller::GetDirection() const
{
    return direction_;
}

void Controller::SetDirection(const Direction& direction)
{
    direction_ = direction;
}
