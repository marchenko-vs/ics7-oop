#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <QWidget>
#include <QVBoxLayout>
#include <vector>
#include <QDebug>
#include <memory>

#include "button.h"

#define NUMBER_OF_FLOORS 9
#define DOORS_TIME  500
#define MOVING_TIME 3000

enum Direction
{
    UP = 1,
    STOP = 0,
    DOWN = -1
};

class Controller : public QWidget
{
    Q_OBJECT;

    enum ControllerStatus
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() = default;

public slots:
    void NewTarget(ssize_t floor);
    void PassedFloor(ssize_t floor, Direction direction_);

signals:
    void NewTargetSignal(ssize_t floor);
    void StoppedSignal(bool, ssize_t = 1);

private:
    ControllerStatus status_;

    Direction direction_;

    int current_floor_;
    int needed_floor_;

    std::vector<std::shared_ptr<Button>> buttons_;
    std::vector<bool> visited_floors_;

    std::unique_ptr<QVBoxLayout> layout_;

    bool TargetExists(ssize_t &new_floor);
};

#endif // _CONTROLLER_H_
