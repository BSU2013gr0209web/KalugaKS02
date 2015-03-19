#include <QtWidgets>

#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    setDigitCount(8);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime();

    setWindowTitle(tr("Digital Clock"));
}

void DigitalClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    if ((time.second() % 2) == 0)
    {
        text[2] = ' ';
        text[5] = ' ';
    }
    display(text);
}
