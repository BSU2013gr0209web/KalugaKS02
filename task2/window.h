#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QDateTimeEdit;
class QCalendarWidget;
class QVBoxLayout;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    QVBoxLayout *clock;
    QPoint dragPosition;

};

#endif
