#ifndef PROJEKAT_H
#define PROJEKAT_H
#include <lcd.h>
#include <QString>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Projekat; }
QT_END_NAMESPACE

class Projekat : public QDialog
{
    Q_OBJECT

public:
    Projekat(QWidget *parent = nullptr);
    ~Projekat();

private slots:
    void on_Start_clicked();
    void rtcTimer();
    void on_Stop_clicked();

private:
    Ui::Projekat *ui;
};
#endif // PROJEKAT_H
