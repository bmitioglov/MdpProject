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
    ui->comboBox_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog *d = new Dialog();
    DBInfoGetter* dbinfogetter = new DBInfoGetter();
//    dbinfogetter->getAppropriateCountries(ui->comboBox->currentText(), "Страна");


    if (ui->comboBox->currentText() == "По странам"){
        graph<Country>* graph1 = new graph<Country>();
        DBInfoGetterDAO::printFlightMatrix(graph1->getFlightMatrix().getMatrix());
        d -> show();
    }
    else
    if (ui->comboBox->currentText()=="По деревням"){
        graph<Village>* graph1 = new graph<Village>();
        DBInfoGetterDAO::printFlightMatrix(graph1->getFlightMatrix().getMatrix());
        d -> show();
    }
    else
    if (ui->comboBox->currentText()=="По городам"){
            graph<City>* graph1 = new graph<City>();
            DBInfoGetterDAO::printFlightMatrix(graph1->getFlightMatrix().getMatrix());
            d -> show();
    }
    else
    {
        ui->label_4->setText("Выберите тип путешествия, пожалуйста");
    }

//    DBInfoGetterDAO::printFlightMatrix(dbinfogetter->getFlightMatrix("Страна").getMatrix());

}

void MainWindow::on_comboBox_currentTextChanged()
{
    ui->label_4->clear();
    ui->pushButton->setEnabled(true);
    ui->comboBox_2->clear();
    qDebug()<< ui->comboBox->currentText();
    if (ui->comboBox->currentText() == "По странам"){
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_2->addItem("Австралия");
        ui->comboBox_2->addItem("Америка");
        ui->comboBox_2->addItem("Англия");
        ui->comboBox_2->addItem("Беларусь");
        ui->comboBox_2->addItem("Болгария");
        ui->comboBox_2->addItem("Германия");
        ui->comboBox_2->addItem("Греция");
        ui->comboBox_2->addItem("Испания");
        ui->comboBox_2->addItem("Казахстан");
        ui->comboBox_2->addItem("Норвегия");
        ui->comboBox_2->addItem("Россия");
    }
    else
    if (ui->comboBox->currentText()=="По деревням"){
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_2->addItem("Куршавель");
        ui->comboBox_2->addItem("Сент-Сирк");
    }
    else
    {
        if (ui->comboBox->currentText()=="По городам"){
            ui->comboBox_2->setEnabled(true);
        }
    }

}

void MainWindow::on_comboBox_2_currentTextChanged()
{
//   country =ui->comboBox_2->currentText();
}
