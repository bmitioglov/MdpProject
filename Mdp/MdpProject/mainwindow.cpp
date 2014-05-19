#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include "city.h"
#include "country.h"
#include "village.h"
#include "drawgraph.h"
#include "allocator.h"
#include <QDebug>

using namespace HolidayHelper;
using namespace Vertex;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
}

using namespace DB;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DBInfoGetter* dbinfogetter = new DBInfoGetter();
    drawGraph *dg = new drawGraph();

    if (ui->comboBox->currentText() == "По странам"){
        Allocator<Country> *al     = new Allocator<Country>();
        graph<Country> *v = al->pointer();
        DBInfoGetterDAO::printFlightMatrix(v->getFlightMatrix().getMatrix());

        QString curr_val = ui->comboBox_2->currentText();
        int index = v->getFlightMatrix().getMap().key(curr_val);

        QVector<int> paths = v->getFlightMatrix().getMatrix()[index];

        for (int i = 0; i < paths.length(); ++i) {
            if (paths[i] != 0) dg->append(v->getFlightMatrix().getMap().value(paths[i]));
        }

        dg->draw();
        dg->show();
        delete dg;
    }
    else if (ui->comboBox->currentText()== "По деревням"){
        Allocator<Village> *al = new Allocator<Village>();
        graph<Village> *v = al->pointer();
        DBInfoGetterDAO::printFlightMatrix(v->getFlightMatrix().getMatrix());

        QString curr_val = ui->comboBox_2->currentText();
        int index = v->getFlightMatrix().getMap().key(curr_val);

        QVector<int> paths = v->getFlightMatrix().getMatrix()[index];

        for (int i = 0; i < paths.length(); ++i) {
            if (paths[i] != 0) dg->append(v->getFlightMatrix().getMap().value(paths[i]));
        }

        dg->draw();
        dg->show();
        delete dg;
    }
    else
    if (ui->comboBox->currentText()== "По городам"){
            Allocator<City> *al     = new Allocator<City>();
            graph<City> *v = al->pointer();
            DBInfoGetterDAO::printFlightMatrix(v->getFlightMatrix().getMatrix());

            QString curr_val = ui->comboBox_2->currentText();
            int index = v->getFlightMatrix().getMap().key(curr_val);

            QVector<int> paths = v->getFlightMatrix().getMatrix()[index];

            for (int i = 0; i < paths.length(); ++i) {
                if (paths[i] != 0) dg->append(v->getFlightMatrix().getMap().value(paths[i]));
            }

            dg->draw();
            dg->show();
            delete dg;
    }
    else
    {
        ui->label_4->setText("Выберите тип путешествия, пожалуйста");
    }
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
