#include "countdown.h"

#include <QWidget>
#include <QtWidgets>

CountDown::CountDown(QWidget *parent)
    : QWidget(parent)
    , mRunning(false)
    , mStartTime()
    , mNumber(new QLCDNumber(13))
    , mLabel(new QLabel("CountDown"))
    , mTotalTime(0)
    , mStart(new QPushButton("Start"))
    , mPause(new QPushButton("Pause"))
    , mStop(new QPushButton("Stop"))
{
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(mLabel, 0, 0, 1, 3);
    gridLayout->addWidget(mNumber, 1, 0, 1, 3);
    gridLayout->addWidget(mStart, 2, 0, 1, 1);
    gridLayout->addWidget(mPause, 2, 1, 1, 1);
    gridLayout->addWidget(mStop, 2, 2, 1, 1);

   connect(mStart, SIGNAL(clicked()), this, SLOT(start()));
   connect(mPause, SIGNAL(clicked()), this, SLOT(pause()));
   connect(mStop, SIGNAL(clicked()), this, SLOT(stop()));
   mNumber->display("00:00:00.000");
   mNumber->setMinimumSize(400,120);
   mNumber->setSegmentStyle(QLCDNumber::Filled);
   gridLayout->setAlignment(mNumber, Qt::AlignCenter);

   mStart->setEnabled(true);
   mPause->setEnabled(false);
   mStop->setEnabled(false);

   startTimer(0);
}
void CountDown::start()
{
    mStartTime = QDateTime::currentDateTime();
    mRunning = true;
    mStart->setEnabled(false);
    mPause->setEnabled(true);
    mStop->setEnabled(true);
}

void CountDown::pause()
{
    mStart->setEnabled(true);
    mPause->setEnabled(false);
    mStop->setEnabled(true);
    timerEvent(new QTimerEvent(0));
    mTotalTime += mSessionTime;
    mRunning = false;
}

void CountDown::stop()
{
    mStart->setEnabled(true);
    mPause->setEnabled(false);
    mStop->setEnabled(false);
    mTotalTime = 0;
    mRunning = false;
}

void CountDown::timerEvent(QTimerEvent *)
{
    if(mRunning)
    {
        mSessionTime = mStartTime.msecsTo(QDateTime::currentDateTime());
        qint64 time = mTotalTime + mSessionTime;
        unsigned int h = time / 1000 / 60 / 60;
        unsigned int m = (time / 1000 / 60) - (h * 60);
        unsigned int s = (time / 1000) - ((m + (h * 60))* 60);
        unsigned int ms = time - (s + ((m + (h * 60))* 60))*1000;
        const QString diff = QString("%1:%2:%3.%4")
        .arg(h, 2, 10, QChar('0'))
        .arg(m, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'))
        .arg(ms, 3, 10, QChar('0'));
        mNumber->display(diff);
   }
}

