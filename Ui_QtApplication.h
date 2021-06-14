#pragma once
#ifndef DESIGNERSZRKTO_H
#define DESIGNERSZRKTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QSignalMapper>

QT_BEGIN_NAMESPACE

class Ui_Dialog : public QDialog
{
public:
    QTextEdit* ListPath_Editor;
    QTextEdit* SourcePath_Editor;
    QTextEdit* DestinationPath_Editor;
    QPushButton* Submit_Button;
    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QSignalMapper* mapper;

    void logic(QString);

    void setupUi(QDialog* Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(806, 404);
        ListPath_Editor = new QTextEdit(Dialog);
        ListPath_Editor->setObjectName(QString::fromUtf8("ListPath_Editor"));
        ListPath_Editor->setGeometry(QRect(10, 10, 591, 51));
        QFont font;
        font.setPointSize(15);
        ListPath_Editor->setFont(font);
        SourcePath_Editor = new QTextEdit(Dialog);
        SourcePath_Editor->setObjectName(QString::fromUtf8("SourcePath_Editor"));
        SourcePath_Editor->setGeometry(QRect(10, 80, 591, 51));
        SourcePath_Editor->setFont(font);
        DestinationPath_Editor = new QTextEdit(Dialog);
        DestinationPath_Editor->setObjectName(QString::fromUtf8("DestinationPath_Editor"));
        DestinationPath_Editor->setGeometry(QRect(10, 150, 591, 51));
        DestinationPath_Editor->setFont(font);
        Submit_Button = new QPushButton(Dialog);
        Submit_Button->setObjectName(QString::fromUtf8("QButton_Destination"));
        Submit_Button->setEnabled(true);
        Submit_Button->setGeometry(QRect(610, 150, 191, 51));
        Submit_Button->setFont(font);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(10, 220, 391, 181));
        QFont font1;
        font1.setPointSize(26);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(410, 220, 391, 181));
        pushButton_2->setFont(font1);
        retranslateUi(Dialog);
        mapper = new QSignalMapper(this);
        
        
        connect(ListPath_Editor, SIGNAL(textChanged()), Dialog, SLOT(tutorialMessage()));
        connect(SourcePath_Editor, SIGNAL(textChanged()), Dialog, SLOT(tutorialMessage()));
        connect(DestinationPath_Editor, SIGNAL(textChanged()), Dialog, SLOT(tutorialMessage()));

        connect(Submit_Button, &QPushButton::clicked,
            mapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));
        mapper->setMapping(Submit_Button, Submit_Button->text()); // by clicking a button will translate the text of the button,

        // send text button from the mapper in the slot where the text will be set
        connect(mapper, static_cast<void(QSignalMapper::*)(const QString&)>(&QSignalMapper::mapped),
            [=](const QString str) {
                //Submit_Button->setText(ListPath_Editor->toPlainText());
                QMessageBox::information(NULL, "Validating data", str, QMessageBox::Ok);
                std::string strIn;
                std::fstream csvList;
                std::stringstream sStream;
                std::filesystem::current_path("C:/Users/ASUS/Desktop");
                if (std::filesystem::is_regular_file("C:/Users/ASUS/Desktop/list.csv")) {
                    csvList.open("C:/Users/ASUS/Desktop/list.csv", std::ios::in);
                    if (csvList.is_open()) {
                        std::string csvLine;
                        std::smatch rgxMatch;
                        using namespace std::regex_constants;
                        while (std::getline(csvList, csvLine)) {
                            for (auto& folder : std::filesystem::directory_iterator("input")) {
                                std::string directoyPath(folder.path().string());
                                if (folder.is_directory() &&
                                    std::regex_search(
                                        directoyPath,
                                        rgxMatch,
                                        std::regex(csvLine.substr(0, csvLine.find_first_of(';') - 1
                                        )
                                        ))) {
                                    for (auto& file : std::filesystem::directory_iterator(folder.path())) {
                                        std::string filePath(file.path().string());
                                        sStream.str("");
                                        sStream
                                            << csvLine.substr(csvLine.find_first_of(';', 0) + 1, csvLine.find_first_of(';', csvLine.find_first_of(';', 0)) + 1);
                                        if (file.is_regular_file() &&
                                            std::regex_search(
                                                filePath,
                                                rgxMatch,
                                                std::regex(sStream.str(), ECMAScript))) {
                                            //QMessageBox::information(NULL, "", "Start Parsing Data", QMessageBox::Ok);
                                            try {
                                                std::filesystem::copy(file.path(), "output");
                                            }
                                            catch (...) {
                                                QMessageBox::information(NULL, "ALERT", "(!!!) FILE ALREADY COPIED (!!!)", QMessageBox::Ok);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        csvList.close();
                        QMessageBox::information(NULL, "ALERT", "JOB DONE, bye! ^__^", QMessageBox::Ok);
                    }
                }
                else {
                    QMessageBox::information(NULL, "ALERT", "Drop a valid csv / txt or call with arguments", QMessageBox::Ok);
                }
            });

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog* Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Emmeci_ToolBoxV1", nullptr));
        ListPath_Editor->setPlaceholderText(QApplication::translate("Dialog", "Drop List", nullptr));
        SourcePath_Editor->setPlaceholderText(QApplication::translate("Dialog", "Drop Source Path", nullptr));
        DestinationPath_Editor->setPlaceholderText(QApplication::translate("Dialog", "Drop Destination Path", nullptr));
        Submit_Button->setText(QApplication::translate("Dialog", "Submit Destination", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "Reset", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "Start Copy", nullptr));
    } // retranslateUi

};
namespace Ui {
    class Dialog : public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERSZRKTO_H