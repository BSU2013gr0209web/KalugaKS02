#include <QtWidgets>

#include "window.h"
#include "analogclock.h"
#include "digitalclock.h"
#include "stopwatch.h"
#include "countdown.h"

Window::Window()
{
    createClock();
    createTools();
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(clockGroup);
    layout->addWidget(toolsGroup);
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

void Window::createTools()
{
    toolsGroup = new QGroupBox(tr("Tools"));
    StopWatch *swd = new StopWatch();
    swd->setMaximumSize(600,300);
    swd->show();
    CountDown *cnt = new CountDown();
    cnt->setMaximumSize(600,300);
    cnt->show();
    QVBoxLayout *tools = new QVBoxLayout;
    tools->addWidget(swd);
    tools->addWidget(cnt);
    toolsGroup->setLayout(tools);
}
