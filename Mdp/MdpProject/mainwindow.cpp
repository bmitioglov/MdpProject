#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include "city.h"
#include "country.h"
#include "village.h"
#include <QDebug>

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
    DBInfoGetter* dbinfogetter = new DBInfoGetter();
    dbinfogetter->getAppropriateCountries(ui->comboBox->currentText(), "Страна");
//    dbinfogetter->getFlightMatrix("Страна");
//    DBInfoGetterDAO::printFlightMatrix(dbinfogetter->getFlightMatrix("Деревня").getMatrix());

    graph<Village>* graph1 = new graph<Village>();
    qDebug() << "Before print";
    DBInfoGetterDAO::printFlightMatrix(graph1->getFlightMatrix().getMatrix());

//    DBInfoGetterDAO::printFlightMatrix(dbinfogetter->getFlightMatrix("Страна").getMatrix());
    d -> show();
}

void MainWindow::on_comboBox_currentTextChanged()
{
//   prop = ui->comboBox->currentText();
   //QMessageBox::information(this, "123", country);
}

void MainWindow::on_comboBox_2_currentTextChanged()
{
//   country =ui->comboBox_2->currentText();
}
