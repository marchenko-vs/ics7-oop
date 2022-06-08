#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <QWidget>
#include <QVBoxLayout>
#include <vector>
#include <QDebug>
#include <memory>

#include "button.h"

#define FLOOR_COUNT 14
#define DOORS_TIME  900
#define RIDING_TIME 3000

enum Direction
{
    DOWN = -1,
    STOP = 0,
    UP = 1
};

class Controller : public QWidget
{
    Q_OBJECT;

    enum ControllerStatus
    {
        FREE,
        GOT_TARGET,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);

    Direction GetDirection() const;
    void SetDirection(const Direction& direction);

    ~Controller() = default;

public slots:
    void NewTargetSlot(ssize_t floor);
    void FloorPassedSlot(ssize_t floor, Direction direction);
    void ControllerStoppedSlot();

private:
    bool TargetExists(ssize_t& new_floor);

    ControllerStatus status_;
    Direction direction_;

    ssize_t current_floor_;
    ssize_t needed_floor_;

    std::vector<std::shared_ptr<Button>> buttons_;
    std::vector<bool> visited_floors_;
    std::unique_ptr<QVBoxLayout> layout_;

signals:
    void ControllerStoppedSignal();
    void CabinStoppedSignal(bool, ssize_t, ssize_t = 1);
    void GotTargetSignal(ssize_t& needed_floor, ssize_t& current_floor);
    void FloorPassedSignal(ssize_t floor, Direction direction);
};

#endif // _CONTROLLER_H_
