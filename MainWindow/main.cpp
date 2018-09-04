#include "MainWidget.h"
#include <QApplication>

#include "Loader.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Loader loader;

    int result = EXIT_SUCCESS;

    if (loader.authDialogAccepted())
    {
        loader.start();
        result = app.exec();
    }

    return result;
}
