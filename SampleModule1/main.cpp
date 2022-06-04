#include "FirstModule.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstModule w;
    w.show();

    return a.exec();
}
