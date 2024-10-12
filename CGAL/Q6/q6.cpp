#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QPointF>
#include <QRectF>
#include <QApplication> 
#include <QPolygon>
#include <sstream>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPainter>
#include <QPainterPath>
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

double areaTriangle(QPointF p1, QPointF p2, QPointF p3){
    return ((p2.x() - p1.x()) * (p3.y() - p1.y())) - ((p3.x() - p1.x()) * (p2.y() - p1.y()));
}

bool left(QPointF p1, QPointF p2, QPointF p3){
    return areaTriangle(p1, p2, p3) > 0;
}

bool leftOn(QPointF p1, QPointF p2, QPointF p3){
    return areaTriangle(p1, p2, p3) >= 0;
}

bool collinear(QPointF p1, QPointF p2, QPointF p3){
    return areaTriangle(p1, p2, p3) == 0;
}

bool intersectProper(QPointF p1, QPointF p2, QPointF p3, QPointF p4){
    if (collinear(p1, p2, p3) || collinear(p1, p2, p4) || collinear(p3, p4, p1) || collinear(p3, p4, p2)){
        return false;
    }
    return XOR(left(p1, p2, p3), left(p1, p2, p4)) && XOR(left(p3, p4, p1), left(p3, p4, p2));
}

bool between(QPointF p1, QPointF p2, QPointF p3){
    if (!collinear(p1, p2, p3)){
        return false;
    }
    if (p1.x() != p2.x()){
        return ((p1.x() <= p3.x()) && (p3.x() <= p2.x())) || ((p1.x() >= p3.x()) && (p3.x() >= p2.x()));
    }
    return ((p1.y() <= p3.y()) && (p3.y() <= p2.y())) || ((p1.y() >= p3.y()) && (p3.y() >= p2.y()));
}

bool intersect(QPointF p1, QPointF p2, QPointF p3, QPointF p4){
    if (intersectProper(p1, p2, p3, p4)){
        return true;
    }
    else if (between(p1, p2, p3) || between(p1, p2, p4) || between(p3, p4, p1) || between(p3, p4, p2)){
        return true;
    }
    return false;
}

bool notEqual(QPointF a, QPointF b){
    if (a.x() != b.x() || a.y() != b.y()){
        return true;
    }
    return false;
}

bool isDiagonal(QPointF p1, QPointF p2, QPolygonF points){
    int n = points.size();
    for(int i=0; i< n; i++){
        QPointF c = points[i%n];
        QPointF d = points[(i+1)%n];
        if(notEqual(c, p1) && notEqual(d, p1) && notEqual(c, p2) && notEqual(d, p2) && intersect(p1, p2, c, d)){
            return false;
        }        

    }
    return true;
}

bool inCone(QPointF p1, QPointF p2, QPolygonF points){
    QPointF prev, next1;
    int n = points.size();
    for(int i=0; i<n; i++){
        if (points[(i)%n].x() == p1.x() && points[(i)%n].y() == p1.y()){
            prev = points[(i-1+n)%n];
            next1 = points[(i+1)%n];
            break;
        }
    }
    if (leftOn(p1, next1, prev)){
        return left(p1, p2, prev) && left(p2, p1, next1);
    }
    else{
        return !(leftOn(p1, p2, next1) && leftOn(p2, p1, prev));
    }
}

bool diagonal(QPointF p1, QPointF p2, QPolygonF points){
    return inCone(p1, p2, points) && inCone(p2, p1, points) && isDiagonal(p1, p2, points);
}

QColor getColor(int i){
    return QColor::fromRgb((i * 53) % 256,(i * 151) % 256,(i * 223) % 256, 127);
}

void earInnit(std::vector<bool> &ear, QPolygonF &points){
    int n = points.size();
    for(int i=0; i<n; i++){
        QPointF prev, next1;
        prev = points[(i-1+ n)%n];
        next1 = points[(i+1)%n];
        ear[(i)%n] = diagonal(prev, next1, points);
    }
}

void triangulate(QPolygonF &points, QGraphicsScene &scene, QPen &pen){    
    int n = points.size();
    int color = 1;
    int i = 0;

    QPointF v0, v1, v2, v3, v4;
    std::vector<bool> ear(n);    

    earInnit(ear, points);

    while (n > 3){
        v2 = points[i%points.size()];
        int start = i%points.size();
        do{
            if(ear[i%ear.size()]){
                int k = points.size();
                v2 = points[(i)%k];
                v3 = points[(i+1+k)%k];
                v4 = points[(i+2+k)%k];
                v1 = points[(i-1+k)%k];
                v0 = points[(i-2+k)%k];

                QPolygonF triangle;
                triangle << v1 << v2 << v3;
                scene.addPolygon(triangle, pen, QBrush(getColor(color)));
                triangle.clear();
                color++;

                points.erase(points.begin() + i%k);
                ear.erase(ear.begin() + i%k);

                ear[(i-1+ear.size())%ear.size()] = diagonal(v0, v3, points);
                ear[(i+ear.size())%ear.size()] = diagonal(v1, v4, points);

                n--;
                break;
            }
            i += 1;
        }while(i%points.size() != start);
    }
    scene.addPolygon(points, pen, QBrush(getColor(color)));
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene;

    QPen pen; 
    pen.setColor(Qt::black);

    int xpos = 200;
    int ypos = 300;

    Point_2 p1;
    QPolygonF points, polygon;

    std::ifstream ifile("input.txt", std::ios::in);
    while(ifile >> p1){
        points << QPointF(p1.x(), p1.y());
    }

    for(int i=points.size() - 1;i>=0;i--){
        polygon << points[i];
    }


    scene.setSceneRect(0, 0, 600, 500);
    scene.addPolygon(points);

    triangulate(polygon, scene, pen);

    
    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    view->setRenderHint(QPainter::Antialiasing);
    view->show();

    return app.exec();
}

