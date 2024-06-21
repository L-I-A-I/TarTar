#include <QApplication>
#include <QMainWindow>

#include "centralwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");

    QMainWindow w;

    auto cw = new CentralWidget(&w);
    w.setCentralWidget(cw);

    w.setMinimumSize(550, 400);

    w.showMaximized();

    return a.exec();
}
