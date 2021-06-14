#include "Qt_App.h"
Qt_App::Qt_App(QWidget *parent) : QDialog(parent){
    ui.setupUi(this);
    //QObject::connect(ui.QButton_List, SIGNAL(clicked), this, SLOT(this->logic));
    QObject::connect(ui.Submit_Button, SIGNAL(clicked()), this, SLOT(logic()));
}
/*
void Qt_App::tutorialMessage() { 
    QMessageBox::information(NULL, "Confirm Path", ui.ListPath_Editor->toPlainText(), QMessageBox::Ok);
}*/