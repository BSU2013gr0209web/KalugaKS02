#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QtWidgets>

class CountDown : public QWidget
{
    Q_OBJECT

public:

    CountDown(QWidget * parent = 0);

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

#endif // COUNTDOWN_H
