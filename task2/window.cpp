#include <QtWidgets>

#include "window.h"
#include "analogclock.h"

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
    QVBoxLayout *clock = new QVBoxLayout;
    clock->addWidget(acl);
    clockGroup->setLayout(clock);
}

void Window::createTools()
{
    toolsGroup = new QGroupBox(tr("Tools"));
    QVBoxLayout *tools = new QVBoxLayout;
    toolsGroup->setLayout(tools);
}
