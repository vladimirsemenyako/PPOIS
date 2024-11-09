#include "dvdwindow.h"
#include <QPixmap>
#include <QTimer>

DVDWindow::DVDWindow(QWidget *parent) : QMainWindow(parent), dx(2), dy(2) {
    setFixedSize(800, 600);

    dvdLabel = new QLabel(this);
    QPixmap logo(":/img/DVD_logo.png");
    dvdLabel->setPixmap(logo.scaled(100, 50));
    dvdLabel->setGeometry(100, 100, 100, 50);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DVDWindow::moveLogo);
    timer->start(10);
}

void DVDWindow::moveLogo() {
    int x = dvdLabel->x();
    int y = dvdLabel->y();

    if (x <= 0 || x + dvdLabel->width() >= width())
        dx = -dx;
    if (y <= 0 || y + dvdLabel->height() >= height())
        dy = -dy;

    dvdLabel->move(x + dx, y + dy);
}