#pragma once
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
class DigitalClock : public QLCDNumber{
    Q_OBJECT

public:
    DigitalClock(QWidget* parent = nullptr);

private slots:
    void showTime();
};
DigitalClock::DigitalClock(QWidget* parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);

    showTime();

    setWindowTitle(tr("Digital Clock"));
    resize(150, 60);
}
void DigitalClock::showTime(){
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}