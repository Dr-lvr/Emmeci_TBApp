#include "Qt_App.h"
#include <QtWidgets/QApplication>
#include <time.h>
#include <windows.h>
#include <QDateTime>
#include <QDebug>
//#include "DigitalClock.h"

auto main(int argc, char *argv[])-> int{
    QApplication a(argc, argv);
    Qt_App w;
    //DigitalClock k;
    w.show();
    //k.show();
    QMessageBox::information(NULL, "Validating data", "Ready", QMessageBox::Ok);
    return a.exec();
}
