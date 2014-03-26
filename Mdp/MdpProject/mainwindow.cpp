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

QString prop;
QString country;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog *d = new Dialog();
      d -> show();
       //QMessageBox::information(this, "123", prop);
}

void MainWindow::on_comboBox_currentTextChanged()
{
   prop = ui->comboBox->currentText();
   //QMessageBox::information(this, "123", country);
}

void MainWindow::on_comboBox_2_currentTextChanged()
{
   country =ui->comboBox_2->currentText();
}
