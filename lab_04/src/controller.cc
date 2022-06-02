#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    this->layout_ = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(this->layout_.get());

    for (int i = 0; i < NUMBER_OF_FLOORS; i++)
    {
        std::shared_ptr<Button> btn(new Button);
        btn->SetFloor(NUMBER_OF_FLOORS - i);
        btn->setText(QString::number(NUMBER_OF_FLOORS - i));

        buttons_.insert(buttons_.begin(), btn);
        layout_->addWidget(dynamic_cast<QPushButton *>(btn.get()));

        visited_floors_.push_back(true);
        QObject::connect(btn.get(), SIGNAL(FloorPressed(ssize_t)), this, SLOT(NewTarget(ssize_t)));
    }
}

void Controller::NewTarget(ssize_t floor)
{
    this->status_ = BUSY;
    this->visited_floors_[floor - 1] = false;

    TargetExists(floor);
    this->needed_floor_ = floor;
    emit NewTargetSignal(floor);
}

void Controller::PassedFloor(ssize_t floor, Direction direction_)
{
    if (status_ == BUSY)
    {
        this->current_floor_ = floor;
        this->direction_ = direction_;

        if (current_floor_ == needed_floor_)
        {
            qDebug() << "Elevator has stopped on floor: " << floor;

            emit this->buttons_.at(floor - 1)->UnpressSignal();
            this->visited_floors_[floor - 1] = true;

            if (TargetExists(floor))
            {
                this->needed_floor_ = floor;
                emit StoppedSignal(false, floor);
            }
            else
            {
                this->status_ = FREE;
                emit StoppedSignal(true);
            }
        }
    }
}


bool Controller::TargetExists(ssize_t &new_floor)
{
    int direction = direction_ != STOP ? direction_ : DOWN;

    for (int i = current_floor_ - 1; i >= 0 && i < NUMBER_OF_FLOORS; i += direction)
    {
        if (!visited_floors_[i])
        {
            new_floor = i + 1;
            return true;
        }
    }

    for (int i = current_floor_ - 1; i >= 0 && i < NUMBER_OF_FLOORS; i += -direction)
    {
        if (!visited_floors_[i])
        {
            new_floor = i + 1;
            return true;
        }
    }

    return false;
}
