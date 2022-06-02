#ifndef _CABIN_H_
#define _CABIN_H_

#include <QObject>

#include "doors.h"
#include "controller.h"

class Cabin : public QObject
{
    Q_OBJECT;

    enum CabinStatus
    {
        GET,
        FREE,
        MOVING
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() = default;

public slots:
    void CabinMoving();
    void CabinGetsTarget(ssize_t floor);
    void CabinStopped(bool is_last, ssize_t new_floor = 1);

signals:
    void OpenDoorsSignal();
    void FloorPassed(ssize_t floor, Direction dir);

private:
    Doors door_;

    ssize_t current_floor_;
    ssize_t desired_floor_;

    Direction direction_;

    CabinStatus status_;

    QTimer move_timer_;

signals:
    void MovingSignal();
    void StoppedSignal(bool = true, ssize_t = 1);
};

#endif // _CABIN_H_
