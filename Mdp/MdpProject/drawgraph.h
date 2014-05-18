#ifndef DRAWGRAPH_H
#define DRAWGRAPH_H

#include "QVector"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPointF>
#include <QVector>

class drawGraph
{
public:
    QVector <QPointF> points;
    QVector <QLineF> lines;
    QVector <QString> countries;
    QGraphicsView * view;
    QGraphicsScene * scene;

    drawGraph();
    void draw();
    void show();
    void append(QString vertex);
};

#endif // DRAWGRAPH_H
