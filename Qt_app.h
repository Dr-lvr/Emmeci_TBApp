#pragma once
#include <regex>
#include <ranges>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <QtWidgets/QDialog>
#include <qmessagebox.h>
#include "Ui_QtApplication.h"


class Qt_App : public QDialog {
    Q_OBJECT
public:
    Qt_App(QWidget *parent = Q_NULLPTR);
//public slots:
private:
    Ui::Dialog ui;
};