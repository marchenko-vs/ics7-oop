#ifndef _DOORS_H_
#define _DOORS_H_

#include <QObject>
#include <QDebug>
#include <QTimer>

class Door : public QObject
{
    Q_OBJECT;

private:
    enum DoorStatus
    {
        OPEN,
        OPENING,
        CLOSING,
        CLOSED
    };

public:
    Door();

    ~Door() = default;

public slots:
    void OpeningSlot();

private:
    DoorStatus status_;

    QTimer opening_timer_;
    QTimer closing_timer_;
    QTimer open_timer_;

private slots:
    void OpenSlot();
    void ClosingSlot();
    void ClosedSlot();

signals:
    void ClosedSignal();
};

#endif // _DOORS_H_
