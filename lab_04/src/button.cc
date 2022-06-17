#include <QDebug>

#include "button.h"

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()), // Qt signal (default)
                     this, SLOT(PressedSlot())); // here

    QObject::connect(this, SIGNAL(NotPressedSignal()), // here
                     this, SLOT(NotPressedSlot())); // here

    status_ = INACTIVE;
    button_floor_ = 1;

    setStyleSheet("border-style: outset;"
                  "color: black;"
                  "border-width: 1px;"
                  "border-radius: 10px;"
                  "border-color: black;"
                  "font: bold 14px;"
                  "padding: 6px;");
}

void Button::SetFloor(const ssize_t& floor)
{
    button_floor_ = floor;
}

void Button::PressedSlot()
{
    if (status_ == INACTIVE)
    {
        this->setStyleSheet("background-color: yellow;"
                            "color: black;"
                            "border-style: outset;"
                            "border-width: 1px;"
                            "border-radius: 10px;"
                            "border-color: black;"
                            "font: bold 14px;"
                            "padding: 6px;");
        this->update();

        status_ = ACTIVE;
        this->setDisabled(true);

        emit PressedSignal(button_floor_); // in controller for every button
    }
}

void Button::NotPressedSlot()
{
    if (status_ == ACTIVE)
    {
        this->setStyleSheet("background-color: skyblue;"
                            "color: black;"
                            "border-style: outset;"
                            "border-width: 1px;"
                            "border-radius: 10px;"
                            "border-color: black;"
                            "font: bold 14px;"
                            "padding: 6px;");
        this->update();

        status_ = INACTIVE;
        this->setDisabled(false);
    }
}
