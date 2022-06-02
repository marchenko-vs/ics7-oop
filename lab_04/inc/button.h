#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <QPushButton>
#include <QObject>

class Button : public QPushButton
{
    Q_OBJECT;

    enum ButtonStatus
    {
        ACTIVE,
        INACTIVE
    };

public:
    Button(QWidget *parent = nullptr);
    ~Button() = default;

    void SetFloor(const ssize_t &floor);

public slots:
    void Pressed();
    void Unpressed();

signals:
    void FloorPressed(ssize_t floor);
    void UnpressSignal();

private:
    ButtonStatus status_;

    ssize_t button_floor_;
};

#endif // _BUTTON_H_
