#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":images/welcome.jpg"));
    splash->show();
    Sleep(750);

    MainWindow w;
    w.show();

    splash->finish(&w);
    delete splash;

    return a.exec();
}
