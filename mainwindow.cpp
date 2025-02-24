#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

const int bClicks = 0;
int clicks = bClicks;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui -> pushButton -> setStyleSheet("background: url(res/milly.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    clicks++;
    qDebug() << clicks;
    ui -> label_2 -> setText(QString::number(clicks));
}


void MainWindow::on_extBtn_clicked()
{
    QMessageBox::StandardButton exit1 = QMessageBox::question(this, "Exit", "r u sure?", QMessageBox::Yes | QMessageBox::No);

    if (exit1 == QMessageBox::Yes) {
        QMessageBox::StandardButton exit2 = QMessageBox::question(this, "Exit", "r u completely sure?", QMessageBox::Yes | QMessageBox::No);
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
}

