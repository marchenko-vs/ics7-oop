#ifndef _CABIN_H_
#define _CABIN_H_

#include <QObject>

#include "doors.h"
#include "controller.h"

class Cabin : public QObject
{
    Q_OBJECT

private:
    enum CabinStatus
    {
        STANDING,
        GOT_TARGET,
        RIDING
    };

    void SaveState(const ssize_t& needed_floor, const ssize_t& current_floor);

    QTimer riding_timer_;

    Doors doors_;
    Direction direction_;
    CabinStatus status_;

    ssize_t current_floor_;
    ssize_t needed_floor_;

    bool target_exists_;

public:
    explicit Cabin(QObject *parent = nullptr);

    ~Cabin() = default;

signals:
    void FloorPassedSignal(ssize_t floor, Direction direction);
    void OpenDoorsSignal();
    void RidingSignal();

private slots:
    void RidingSlot();

public slots:
    void GotTargetSlot(ssize_t& needed_floor, ssize_t& current_floor);
    void StoppedSlot(bool is_last, ssize_t current_floor, ssize_t needed_floor = 1);
};

#endif // _CABIN_H_
