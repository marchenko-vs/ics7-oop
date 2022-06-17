#ifndef _DOORS_H_
#define _DOORS_H_

#include <QObject>
#include <QDebug>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT

private:
    enum DoorStatus
    {
        OPEN,
        OPENING,
        CLOSING,
        CLOSED
    };

    DoorStatus status_;

    QTimer opening_timer_;
    QTimer closing_timer_;
    QTimer open_timer_;

public:
    Doors();

    ~Doors() = default;

signals:
    void ClosedSignal();

private slots:
    void OpenSlot();
    void ClosingSlot();
    void ClosedSlot();

public slots:
    void OpeningSlot();
};

#endif // _DOORS_H_
