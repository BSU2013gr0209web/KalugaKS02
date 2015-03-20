#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QtWidgets>

class StopWatch : public QWidget
{
    Q_OBJECT

public:

    StopWatch(QWidget * parent = 0);

public slots:

    void start();
    void pause();
    void stop();

protected:
    void timerEvent(QTimerEvent *);

private:
    bool mRunning;
    QDateTime mStartTime;
    QLCDNumber * mNumber;
    QLabel * mLabel;
    qint64 mTotalTime;
    qint64 mSessionTime;
    QPushButton * mStart;
    QPushButton * mPause;
    QPushButton * mStop;
};

#endif // STOPWATCH_H
