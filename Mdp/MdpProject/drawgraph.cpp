#include "drawgraph.h"

using namespace HolidayHelper;

drawGraph::drawGraph() {
    view = new QGraphicsView();
    scene = new QGraphicsScene();
    view->setScene(scene);
    view->setWindowTitle("Варианты поездки");
}

void drawGraph::draw() {
    for(int i = 0; i<countries.size() ; i++) {
        points.append(QPointF(i*100, 100));
    }

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
}

void drawGraph::show() {
    view->show();
}

void drawGraph::append(QString vertex) {
    countries.append(vertex);
}
