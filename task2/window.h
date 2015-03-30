#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QDateTimeEdit;
class QSpinBox;
class QDoubleSpinBox;
class QGroupBox;
class QLabel;
class QLCDNumber;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

public slots:

private:
    void createClock();
    void createTools();

    QGroupBox *clockGroup;
    QGroupBox *toolsGroup;
};

#endif

