#include "projekat.h"
#include <lcd.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Projekat w;
    w.show();
    return a.exec();
}
