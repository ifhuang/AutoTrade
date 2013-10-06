#include "mainwindow.h"
#include <windows.h>
#include <QApplication>
#include <QSplashScreen>

const char *PROGRAM_NAME = "TradeCube";

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":images/welcome.jpg"));
    splash->show();
    Sleep(750);

    MainWindow mainwindow;
    mainwindow.show();

    splash->finish(&mainwindow);
    delete splash;

    return app.exec();
}
