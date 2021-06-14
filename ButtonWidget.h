#pragma once
#include <QtWidgets/QDialog>
#include <QSignalMapper>
#include <QGridLayout>
class ButtonWidget : public QWidget{
    Q_OBJECT

public:
    ButtonWidget(const QStringList& texts, QWidget* parent = nullptr);

signals:
    void clicked(const QString& text);

private:
    QSignalMapper* signalMapper;
};