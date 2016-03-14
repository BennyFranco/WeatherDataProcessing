#include "view/CreateStationWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreateStationWindow w;
    w.show();

    return a.exec();
}
