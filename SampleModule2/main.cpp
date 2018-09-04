#include "SecondModule.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SecondModule w;
    w.show();

    return a.exec();
}
