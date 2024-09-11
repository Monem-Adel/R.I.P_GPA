#include "mainwindow.h"
#include <QSplashScreen>
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen splash(QPixmap(":/icon/iconRIPGPA2.png"));
    splash.show();
    //Set a timer to close the splash screen and show the main window after a delay
    QTimer::singleShot(1500, &splash, &QSplashScreen::close); // 3000 milliseconds = 3 seconds

    MainWindow w;

    //Show the main window after the splash screen is closed
    QTimer::singleShot(1500, &w, &QMainWindow::show); // Show main window after 3 seconds

    // w.show();

    return a.exec();
}
