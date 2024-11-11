#include <QApplication>
#include "dvdwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    DVDWindow window;
    window.show();

    return app.exec();
}