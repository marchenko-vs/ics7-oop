#include <QDebug>

#include "button.h"

Button::Button(QWidget *parrent) : QPushButton(parrent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(Pressed()));
    QObject::connect(this, SIGNAL(UnpressSignal()), this, SLOT(Unpressed()));

    this->status_ = INACTIVE;
    this->button_floor_ = 1;
}

void Button::SetFloor(const ssize_t &floor)
{
    this->button_floor_ = floor;
}

void Button::Pressed()
{
    if (status_ == INACTIVE)
    {
        this->setFocus();
        this->setStyleSheet("background-color: purple; color: white");
        this->update();

        this->status_ = ACTIVE;
        this->setDisabled(true);
        emit FloorPressed(this->button_floor_);
    }
}

void Button::Unpressed()
{
    if (status_ == ACTIVE)
    {
        this->setStyleSheet("background-color:yellow");
        this->update();

        this->status_ = INACTIVE;
        this->setDisabled(false);
    }
}
