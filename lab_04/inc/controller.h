#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>

#include <memory>
#include <vector>

#include "button.h"

#define NUMBER_OF_FLOORS 14
#define DOORS_WORKING_TIME  900
#define ELEVATOR_RIDING_TIME 3000

enum Direction
{
    DOWN = -1,
    STOP = 0,
    UP = 1
};

class Controller : public QWidget
{
    Q_OBJECT

private:
    enum ControllerStatus
    {
        FREE,
        GOT_TARGET,
        BUSY
    };

    bool TargetExists(ssize_t& new_floor);

    ControllerStatus status_;
    Direction direction_;

    ssize_t current_floor_;
    ssize_t needed_floor_;

    std::vector<std::shared_ptr<Button>> buttons_;
    std::vector<bool> visited_floors_;
    std::unique_ptr<QVBoxLayout> layout_;

public:
    explicit Controller(QWidget *parent = nullptr);

    Direction GetDirection() const;
    void SetDirection(const Direction& direction);

    ~Controller() = default;

signals:
    void ControllerStoppedSignal();
    void CabinStoppedSignal(bool, ssize_t, ssize_t = 1);
    void GotTargetSignal(ssize_t& needed_floor, ssize_t& current_floor);
    void FloorPassedSignal(ssize_t floor, Direction direction);

public slots:
    void NewTargetSlot(ssize_t floor);
    void FloorPassedSlot(ssize_t floor, Direction direction);
    void ControllerStoppedSlot();
};

#endif // _CONTROLLER_H_
