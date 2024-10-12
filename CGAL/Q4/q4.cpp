#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <sstream>
#include <cstdlib>
#include <QGraphicsScene>
#include <cmath>
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


float areaTriangle(Point_2 p1, Point_2 p2, Point_2 p3){
    return ((p2.x() - p1.x()) * (p3.y() - p1.y())) - ((p3.x() - p1.x()) * (p2.y() - p1.y()));
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPen pen;
    pen.setColor(Qt::black);

    QGraphicsScene scene;
    QString qstr;

    int xpos = 300;
    int ypos = 300;

    Point_2 p1, p2, p3;
    std::ifstream ifile("input.txt", std::ios::in);
    ifile >> p1 >> p2 >> p3;

    float result = abs(areaTriangle(p1, p2, p3))/2;

    scene.setSceneRect(0,0, 600, 500);    
    scene.addLine(p1.x(), p1.y(), p2.x(), p2.y(), pen);
    scene.addLine(p2.x(), p2.y(), p3.x(), p3.y(), pen);
    scene.addLine(p3.x(), p3.y(), p1.x(), p1.y(), pen);

    qstr = QString::fromStdString("area: " + std::to_string(result).substr(0, std::to_string(result).find(".") + 2 + 1));
    QGraphicsTextItem *text = scene.addText(qstr);
    text->setPos(xpos, ypos);
    text->setDefaultTextColor(QColor::fromRgb(0, 0, 0));


    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();

    return app.exec();
}

