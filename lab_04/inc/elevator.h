#ifndef _ELEVATOR_H_
#define _ELEVATOR_H_

#include <QObject>

#include "controller.h"
#include "cabin.h"

class Elevator : public QObject
{
    Q_OBJECT

private:
    Controller controller_;
    Cabin cabin_;

public:
    explicit Elevator(QObject *parent = nullptr);

    ~Elevator() = default;

    QWidget *widget();
};

#endif // _ELEVATOR_H_
