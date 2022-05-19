#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Assignment5");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void game();
void MainWindow::on_pushButton_clicked()
{
    close();
    game();
}


