#include "Qt_App.h"
#include <QtWidgets/QApplication>

auto main(int argc, char *argv[])-> int{
    QApplication a(argc, argv);
    Qt_App w;
    w.show();
    return a.exec();
}
