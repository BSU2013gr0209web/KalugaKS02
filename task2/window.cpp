#include <QtWidgets>

#include "window.h"
#include "analogclock.h"

Window::Window(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)
{
    AnalogClock *acl = new AnalogClock();
    acl->setMinimumSize(200, 200);
    clock = new QVBoxLayout;
    clock->addWidget(acl);
    setLayout(clock);
    //
    QAction *quitAction = new QAction(tr("В&ыхад"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    addAction(quitAction);
    //
    setContextMenuPolicy(Qt::ActionsContextMenu);
    setToolTip(tr("Перацягівайце гадзіны левай кнопкай мышы.\n"
                  "Выкарыстоўвайце правую кнопку мышы, каб адкрыць кантэкстнае меню."));
    setWindowTitle(tr("Гадзіны"));
    setWindowFlags(Qt::WindowStaysOnTopHint);
    QRect desktopRect = QApplication::desktop()->availableGeometry(this);
    QPoint center = desktopRect.topRight();

    move(center.x()-250, center.y()+50);
}

void Window::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}


void Window::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}


void Window::resizeEvent(QResizeEvent * /* event */)
{
    int side = qMin(width(), height());
    QRegion maskedRegion(width() / 2 - side / 2, height() / 2 - side / 2, side,
                             side , QRegion::Ellipse);
    setMask(maskedRegion);
}

QSize Window::sizeHint() const
{
    return QSize(100, 100);
}
