#include <QtWidgets>

#include "analogclock.h"

AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);
}

void AnalogClock::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 9),
        QPoint(-7, 9),
        QPoint(0, -50)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 9),
        QPoint(-7, 9),
        QPoint(0, -80)
    };
    static const QPoint secondHand[3] = {
        QPoint(3,12),
        QPoint(-3,12),
        QPoint(0,-100)
    };
    static const QPoint clockCover = QPoint(0,0);

    QColor hourColor(127, 0, 127, 191);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(0, 0, 127, 191);
    QColor coverColor(0, 0, 127);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    //current date
    QString date;
    QDate d;
    d = QDate::currentDate();
    int day = d.dayOfWeek();
    QString weekDay = QDate::shortDayName(day);
    weekDay[0].isUpper();
    date=QDate::currentDate().toString("dd.MM");
    painter.setPen(coverColor);
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(-60, 5, weekDay);
    painter.drawText(30, 5, date);

    //minute
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    //hour
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    //second
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

    painter.save();
    painter.rotate(6.0 * (time.second() + time.msec() / 1000.0));
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();

    //cover
    painter.setBrush(coverColor);
    painter.drawEllipse(clockCover, 7, 7);

}
