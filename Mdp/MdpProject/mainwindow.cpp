#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "dialog.h"
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(100);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog *d = new Dialog();
      d -> show();
}
