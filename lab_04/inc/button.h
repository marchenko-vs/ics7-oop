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

    void SetFloor(const ssize_t& floor);

public slots:
    void NotPressed();

signals:
    void PressedSignal(ssize_t floor);
    void NotPressedSignal();

private:
    ButtonStatus status_;
    ssize_t button_floor_;

private slots:
    void PressedSlot();
};

#endif // _BUTTON_H_
