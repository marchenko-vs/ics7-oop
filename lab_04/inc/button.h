#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <QPushButton>
#include <QObject>

class Button : public QPushButton
{
    Q_OBJECT

private:
    enum ButtonStatus
    {
        ACTIVE,
        INACTIVE
    };

    ButtonStatus status_;
    ssize_t button_floor_;

public:
    Button(QWidget *parent = nullptr);

    void SetFloor(const ssize_t& floor);

    ~Button() = default;

signals:
    void PressedSignal(ssize_t floor);
    void NotPressedSignal();

private slots:
    void PressedSlot();

public slots:
    void NotPressedSlot();
};

#endif // _BUTTON_H_
