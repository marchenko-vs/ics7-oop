#ifndef _DOORS_H_
#define _DOORS_H_

#include <QObject>
#include <QDebug>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT;

private:
    enum DoorsStatus
    {
        OPEN,
        OPENING,
        CLOSING,
        CLOSED
    };

public:
    Doors();
    ~Doors() = default;

public slots:
    void Opened();
    void Closed();

private slots:
    void Opening();
    void Closing();

signals:
    void ClosedSignal();

private:
    DoorsStatus status_;

    QTimer opening_timer_;
    QTimer closing_timer_;
    QTimer opened_timer_;
};

#endif // _DOORS_H_
