#include "projekat.h"
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <QTimer>
#include <QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <lcd.h>

#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Projekat w;
    w.show();
    return a.exec();
}
