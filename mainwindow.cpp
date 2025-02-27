#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>

const int bClicks = 0;
int clicks = bClicks;
QFile file("data.txt");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd()) {
            line = in.readLine();
            clicks = line.toInt();
        }
        file.close();
    }
}

MainWindow::~MainWindow()
{
    QFile file("data.txt");
    file.close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    clicks++;
    qDebug() << clicks;
    ui -> label_2 -> setText(QString::number(clicks));
    QFile file("data.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << clicks;
    }
}


void MainWindow::on_extBtn_clicked()
{
    QMessageBox::StandardButton exit1 = QMessageBox::question(this, "Exit", "r u sure?", QMessageBox::No | QMessageBox::Yes);

    if (exit1 == QMessageBox::Yes) {
        QMessageBox::StandardButton exit2 = QMessageBox::question(this, "Exit", "r u completely sure?", QMessageBox::No | QMessageBox::Yes);
        if (exit2 == QMessageBox::Yes) {
            QMessageBox::information(this, "Bai!!!!!", "Bai!!!!!!!!!!!");
            QApplication::quit();
        }
    }
}


void MainWindow::on_gitBtn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/The-SGR"));
}


void MainWindow::on_pushButton_2_clicked()
{
    if (ui -> millyBtn -> isChecked()) {
        qDebug() << "Milly was chosen";
        ui -> pushButton -> setIcon(QIcon(":/cats/res/milly.jpg"));
    }
    if (ui -> uniBtn -> isChecked()) {
        qDebug() << "Uni was chosen";
        ui -> pushButton -> setIcon(QIcon(":/cats/res/uni.png"));
    }
    if (ui -> lunaBtn -> isChecked()) {
        qDebug() << "Luna was chosen";
        ui -> pushButton -> setIcon(QIcon(":/cats/res/lunaistabby.jpg"));
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reset = QMessageBox::question(this, "Reset Data", "Are you sure?\nThe application will close and your clicks will be lost FOREVER\nSo proceed?", QMessageBox::No | QMessageBox::Yes);

    if (reset == QMessageBox::Yes) {
        QFile file("data.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "0";
            file.close();
            QApplication::quit();
        }
    }
}

