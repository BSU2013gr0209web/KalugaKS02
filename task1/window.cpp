#include <QtWidgets>

#include "window.h"
#include "analogclock.h"
#include "digitalclock.h"
#include "stopwatch.h"

Window::Window()
{
    createClock();
    createStopWatch();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(clockGroup);
    layout->addWidget(stopWatchGroup);
    setLayout(layout);

    setWindowTitle(tr("Time Master"));
}

void Window::createClock()
{
    clockGroup = new QGroupBox(tr("Clock"));
    AnalogClock *acl = new AnalogClock();
    acl->setMinimumSize(400,400);
    acl->show();
    DigitalClock *dcl = new DigitalClock();
    dcl->setMinimumSize(400,120);
    dcl->show();
    QVBoxLayout *clock = new QVBoxLayout;
    clock->addWidget(acl);
    clock->addWidget(dcl);
    clockGroup->setLayout(clock);
}

void Window::createStopWatch()
{
    stopWatchGroup = new QGroupBox(tr("StopWatch"));
    StopWatch *swd = new StopWatch();
    swd->setMinimumSize(400,120);
    swd->show();
    QVBoxLayout *stopWatch = new QVBoxLayout;
    stopWatch->addWidget(swd);
    stopWatchGroup->setLayout(stopWatch);
}
