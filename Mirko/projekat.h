#ifndef PROJEKAT_H
#define PROJEKAT_H

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
    void on_pushButton_clicked();
    void rtcTimer();
    double rettemp();

private:
    Ui::Projekat *ui;
};
#endif // PROJEKAT_H
