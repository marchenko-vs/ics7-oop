#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    layout_ = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(layout_.get());

    QObject::connect(this, SIGNAL(FloorPassedSignal(ssize_t, Direction)),
                     this, SLOT(FloorPassedSlot(ssize_t, Direction)));
    QObject::connect(this, SIGNAL(ControllerStoppedSignal()),
                     this, SLOT(ControllerStoppedSlot()));

    status_ = FREE;
    current_floor_ = 1;
    needed_floor_ = 1;
    direction_ = STOP;

    for (int i = 0; i < FLOOR_COUNT; i++)
    {
        std::shared_ptr<Button> btn(new Button);
        btn->SetFloor(FLOOR_COUNT - i);
        btn->setText(QString::number(FLOOR_COUNT - i));

        buttons_.insert(buttons_.begin(), btn);
        layout_->addWidget(btn.get());

        visited_floors_.push_back(true);

        QObject::connect(btn.get(), SIGNAL(PressedSignal(ssize_t)),
                         this, SLOT(NewTargetSlot(ssize_t)));
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
            emit FloorPassedSignal(current_floor_, direction_);
        else
        {
            direction_ = needed_floor_ > current_floor_ ? UP : DOWN;
            emit GotTargetSignal(needed_floor_, current_floor_);
        }
    }
}

void Controller::ControllerStoppedSlot()
{
    if (status_ == BUSY)
    {
        status_ = FREE;
        emit CabinStoppedSignal(true, current_floor_);
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
            buttons_[floor - 1]->NotPressed();
            visited_floors_[floor - 1] = true;

            if (TargetExists(needed_floor_))
                emit CabinStoppedSignal(false, current_floor_, needed_floor_);
            else
                emit ControllerStoppedSignal();
        }
    }
}

bool Controller::TargetExists(ssize_t& new_floor)
{
    int direction = direction_ != STOP ? direction_ : DOWN;

    for (int i = current_floor_ - 1; i >= 0 && i < FLOOR_COUNT; i += direction)
    {
        if (!visited_floors_[i])
        {
            new_floor = i + 1;
            return true;
        }
    }

    for (int i = current_floor_ - 1; i >= 0 && i < FLOOR_COUNT; i += -direction)
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
