#include "stopwatch.h"

#include <QWidget>
#include <QtWidgets>

StopWatch::StopWatch(QWidget *parent)
    : QWidget(parent)
    , mRunning(false)
    , mStartTime()
    , mLabel(new QLabel("00:00:00,000"))
    , mTotalTime(0)
    , mStart(new QPushButton("Start"))
    , mPause(new QPushButton("Pause"))
    , mStop(new QPushButton("Stop"))
{
   QGridLayout *gridLayout = new QGridLayout(this);
   gridLayout->addWidget(mLabel, 0, 0, 1, 3);
   gridLayout->addWidget(mStart, 1, 0, 1, 1);
   gridLayout->addWidget(mPause, 1, 1, 1, 1);
   gridLayout->addWidget(mStop, 1, 2, 1, 1);

   connect(mStart, SIGNAL(clicked()), this, SLOT(start()));
   connect(mPause, SIGNAL(clicked()), this, SLOT(pause()));
   connect(mStop, SIGNAL(clicked()), this, SLOT(stop()));

   QFont font("Arial", 24, QFont::Bold);
   QPalette palette = mLabel->palette();
   palette.setColor(QPalette::WindowText, Qt::blue);
   mLabel->setPalette(palette);
   mLabel->setFont(font);
   gridLayout->setAlignment(mLabel, Qt::AlignCenter);

   mStart->setEnabled(true);
   mPause->setEnabled(false);
   mStop->setEnabled(false);

   startTimer(0);
}
void StopWatch::start()
{
    mStartTime = QDateTime::currentDateTime();
    mRunning = true;
    mStart->setEnabled(false);
    mPause->setEnabled(true);
    mStop->setEnabled(true);
}

void StopWatch::pause()
{
    mStart->setEnabled(true);
    mPause->setEnabled(false);
    mStop->setEnabled(true);
    timerEvent(new QTimerEvent(0));
    mTotalTime += mSessionTime;
    mRunning = false;
}

void StopWatch::stop()
{
    mStart->setEnabled(true);
    mPause->setEnabled(false);
    mStop->setEnabled(false);
    mTotalTime = 0;
    mRunning = false;
}

void StopWatch::timerEvent(QTimerEvent *)
{
    if(mRunning)
    {
        mSessionTime = mStartTime.msecsTo(QDateTime::currentDateTime());
        qint64 time = mTotalTime + mSessionTime;
        time *= 111;
        unsigned int h = time / 1000 / 60 / 60;
        unsigned int m = (time / 1000 / 60) - (h * 60);
        unsigned int s = (time / 1000) - ((m + (h * 60))* 60);
        unsigned int ms = time - (s + ((m + (h * 60))* 60)) * 1000;
        const QString diff = QString("%1:%2:%3,%4")
        .arg(h, 2, 10, QChar('0'))
        .arg(m, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'))
        .arg(ms, 3, 10, QChar('0'));
        mLabel->setText(diff);
   }
}
