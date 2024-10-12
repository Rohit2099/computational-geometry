#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <sstream>
#include <QGraphicsScene>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsView> 
#include <fstream>
#include <QPen>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
#include <CGAL/Line_2.h>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
typedef K::Line_2 Line_2;

bool XOR(bool a, bool b){
    return !a ^ !b;
}

float areaTriangle(QPointF p1, QPointF p2, QPointF p3){
    return ((p2.x() - p1.x()) * (p3.y() - p1.y())) - ((p3.x() - p1.x()) * (p2.y() - p1.y()));
}

float areaPolygon(QPolygonF points){
    float sum = 0;
    QPointF fixed = points[0];
    int i = 1;
    do{
        sum += areaTriangle(fixed, points[i], points[i+1]);
        i += 1;
    }while(i < points.size() - 1);
    return sum;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    QString qstr;

    QPen pen;
    pen.setColor(Qt::red);

    int xpos = 200;
    int ypos = 300;

    Point_2 p1;
    QPolygonF points;
    std::ifstream ifile("input.txt", std::ios::in);
    while(ifile >> p1){
        points << QPointF(p1.x(), p1.y());
    }

    float result = abs(areaPolygon(points)/2);

    scene.setSceneRect(0,0, 600, 500);
    qstr = QString::fromStdString("area: " + std::to_string(result).substr(0, std::to_string(result).find(".") + 2 + 1));
    QGraphicsTextItem *text = scene.addText(qstr);
    text->setPos(xpos, ypos);
    text->setDefaultTextColor(QColor::fromRgb(0, 0, 0));

    scene.addPolygon(points);

    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();

    return app.exec();
}

