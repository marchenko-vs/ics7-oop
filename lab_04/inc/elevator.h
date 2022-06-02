#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_

#include <QObject>

#include "controller.h"
#include "cabin.h"

class Elevator : public QObject
{
    Q_OBJECT;
public:
    explicit Elevator(QObject *parent = nullptr);
    ~Elevator() = default;

    QWidget *widget();

private:
    Controller controller_;

    Cabin cabin_;
};

#endif // _ELEVATOR_H_
