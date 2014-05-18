#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include "city.h"
#include "country.h"
#include "village.h"
#include <QDebug>

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPointF>
#include <QVector>

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

    if (ui->comboBox->currentText() == "По странам"){
        graph<Country>* graph1 = new graph<Country>();
        DBInfoGetterDAO::printFlightMatrix(graph1->getFlightMatrix().getMatrix());
    }
    else
    if (ui->comboBox->currentText()== "По деревням"){
        graph<Village>* graph1 = new graph<Village>();
        DBInfoGetterDAO::printFlightMatrix(graph1->getFlightMatrix().getMatrix());
    }
    else
    if (ui->comboBox->currentText()== "По городам"){
            graph<City>* graph1 = new graph<City>();
            DBInfoGetterDAO::printFlightMatrix(graph1->getFlightMatrix().getMatrix());
    }
    else
    {
        ui->label_4->setText("Выберите тип путешествия, пожалуйста");
    }

    // Drawing

    QVector <QPointF> points;
    QVector <QLineF> lines;
    QVector <QString> countries;
    countries.append("Russia");
    countries.append("USA");
    countries.append("123");
    countries.append("2222");
    countries.append("233333");

    for(int i = 0; i<countries.size() ; i++)
       points.append(QPointF(i*100, 100));

    QGraphicsView * view = new QGraphicsView();
    QGraphicsScene * scene = new QGraphicsScene();
    view->setScene(scene);
    view->setWindowTitle("Варианты поездки");
    QGraphicsTextItem *textItem = new QGraphicsTextItem("SPB");
     textItem->setPos(100, 20);
    scene->addEllipse(100, 0, 50, 50);

    scene->addItem(textItem);

    for(int i = 0; i< points.size(); i++) {
        scene->addEllipse(points[i].x(), points[i].y(), 75, 50);
        scene->addLine(125,50, points[i].x()+25,points[i].y() );
        QGraphicsTextItem *textItem = new QGraphicsTextItem(countries[i]);
        textItem->setPos(points[i].x()+10, points[i].y()+10);
        scene->addItem(textItem);
    }

    // Show the view
    view->show();

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
