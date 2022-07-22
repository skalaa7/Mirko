#include "projekat.h"
#include "ui_projekat.h"
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <QTextStream>
#include <QString>
#include <string>
#include <string.h>
#include <QTextStream>
#include <errno.h>
#include <QTimer>
#include <QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

int click = 0;
int cnt = 0;


char tekst[100];
const char NESTO = 0x48;
int fd,vr;
char svj[5];
char *sv;
double t,l;
FILE *ft;
FILE *lig;


const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

int lcd_h;


QLineSeries *series = new QLineSeries();

Projekat::Projekat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Projekat)
{
    ui->setupUi(this);

vr + '0';
    if (wiringPiSetup() < 0){
        fprintf(stderr, " greska %s\n", strerror(errno));
    }

    fd = wiringPiI2CSetup(NESTO);
    lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);

    lig = fopen("log", "w");

    QTimer *myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(rtcTimer()));
    myTimer -> start(1000);

    QChart *chart = new QChart();

    chart -> legend()->hide();
    chart -> addSeries(series);
    chart -> createDefaultAxes();
    chart -> axisX() -> setRange(0, 10);
    chart -> axisY() -> setRange(0, 255);

    chart -> setTitle("mjerenje svjetlosti");


    QChartView *chartView = new QChartView(chart);
    chartView -> setRenderHint(QPainter::Antialiasing);
    ui -> verticalLayout -> addWidget(chartView);
}

Projekat::~Projekat()
{
    delete ui;
}


void Projekat::rtcTimer()
{
    if (click){
        lcdClear(lcd_h);
        wiringPiI2CReadReg8 (fd,NESTO+4);
        vr = wiringPiI2CReadReg8 (fd,NESTO+4);

        sprintf(svj, "%d", vr);
        sv = &svj[0];

        series->append(cnt, vr);
        lcdPosition(lcd_h,0,0);
        lcdPrintf(lcd_h,sv);

        cnt++;

        if (cnt > 11){
            cnt = 0;
            series -> clear();
        }
    }
}
void Projekat::on_Start_clicked()
{
     click = 1;
}

void Projekat::on_Stop_clicked()
{
    click = 0;
}
