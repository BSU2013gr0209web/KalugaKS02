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
    QSize sizeHint() const Q_DECL_OVERRIDE;// калі збіраць пад новым стандартам, то там ужо ёсць паўключавое слова override

protected:
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    QVBoxLayout *clock;
    QPoint dragPosition;

};

#endif
