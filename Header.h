#pragma once

#ifndef MYCLASS_H
#define MYCLASS_H
#include <QObject>

// A class that has signals and slots.
class MyClass : public QObject {
    Q_OBJECT
public:
    MyClass();
    int value() const { return val; }
public slots:
    // The value of "val" is changed.
    void setValue(int);
    void logic();
signals:
    // The signal should be sent out,
     // when "val" is changed.
    void valueChanged(int);
private:
    int val;
};
#endif // MYCLASS_H