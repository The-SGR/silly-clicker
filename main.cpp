#include "mainwindow.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(400, 585);
    w.setWindowTitle("Silly Clicker");
    w.setWindowIcon(QIcon(":/cats/res/milly.jpg"));
    w.show();
    return a.exec();
}
