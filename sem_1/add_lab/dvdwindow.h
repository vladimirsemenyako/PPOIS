#ifndef DVDWINDOW_H
#define DVDWINDOW_H

#include <QMainWindow>
#include <QLabel>

class DVDWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit DVDWindow(QWidget *parent = nullptr);

    private slots:
        void moveLogo();

private:
    QLabel *dvdLabel;
    int dx, dy;
};

#endif // DVDWINDOW_H