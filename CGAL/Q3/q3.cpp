#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <sstream>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QColor>
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

float areaTriangle(Point_2 p1, Point_2 p2, Point_2 p3){
    return ((p2.x() - p1.x()) * (p3.y() - p1.y())) - ((p3.x() - p1.x()) * (p2.y() - p1.y()));
}

bool left(Point_2 p1, Point_2 p2, Point_2 p3){
    return areaTriangle(p1, p2, p3) > 0;
}

bool leftOn(Point_2 p1, Point_2 p2, Point_2 p3){
    return areaTriangle(p1, p2, p3) >= 0;
}

bool collinear(Point_2 p1, Point_2 p2, Point_2 p3){
    return areaTriangle(p1, p2, p3) == 0;
}

bool intersectProper(Point_2 p1, Point_2 p2, Point_2 p3, Point_2 p4){
    if (collinear(p1, p2, p3) || collinear(p2, p3, p4) || collinear(p3, p4, p1) || collinear(p4, p1, p2)){
        return false;
    }
    return XOR(left(p1, p2, p3), left(p1, p2, p4)) && XOR(left(p3, p4, p1), left(p3, p4, p2));
}

bool between(Point_2 p1, Point_2 p2, Point_2 p3){
    if (!collinear(p1, p2, p3)){
        return false;
    }
    if (p1.x() != p2.x()){
        return ((p1.x() <= p3.x()) && (p3.x() <= p2.x())) || ((p1.x() >= p3.x()) && (p3.x() >= p2.x()));
    }
    return ((p1.y() <= p3.y()) && (p3.y() <= p2.y())) || ((p1.y() >= p3.y()) && (p3.y() >= p2.y()));
}

bool intersect(Point_2 p1, Point_2 p2, Point_2 p3, Point_2 p4){
    if (intersectProper(p1, p2, p3, p4)){
        return true;
    }
    else if (between(p1, p2, p3) || between(p1, p2, p4) || between(p3, p4, p1) || between(p3, p4, p2)){
        return true;
    }
    return false;
}

Point_2 intersectPoint(Point_2 p1, Point_2 p2, Point_2 p3, Point_2 p4){
    float A = (p1.x() * p2.y()) - (p1.y() * p2.x());
    float B = (p3.x() * p4.y()) - (p3.y() * p4.x());
    float C = p1.x() - p2.x();
    float D = p1.y() - p2.y();
    float E = p3.x() - p4.x();
    float F = p3.y() - p4.y();    

    float i1 = ((A * E) - (C * B))/((C * F) - (D * E));
    float i2 = ((A * F) - (D * B))/((C * F) - (D * E));

    Point_2 result(i1, i2);
    return result;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPen pen;
    pen.setColor(Qt::black);

    int xpos = 200;
    int ypos = 400;

    float x1, y1, x2, y2;
    Point_2 p1, p2;
    std::vector<Point_2> points;

    std::ifstream ifile("input.txt", std::ios::in);
    while(ifile >> p1 >> p2){
        points.push_back(p1);
        points.push_back(p2);
    }

    int diags = int((points.size() * (points.size() - 1)) / 2);
    int count = 0;

    QGraphicsScene scene[diags];

    for(int i = 0; i< points.size() - 2; i += 2){
        for(int j = i+2; j<points.size(); j += 2){

            bool intersects = false;
            Point_2 PoI;
            QString qstr;

            if(intersect(points[i], points[i+1], points[j], points[j+1])){
                PoI = intersectPoint(points[i], points[i+1], points[j], points[j+1]);
                intersects = true;
            }

            scene[count].setSceneRect(0,0, 500, 500);
            scene[count].addLine(points[i].x(), points[i].y(), points[i+1].x(), points[i+1].y(), pen);
            scene[count].addLine(points[j].x(), points[j].y(), points[j+1].x(), points[j+1].y(), pen);

            qstr = QString::fromStdString(std::to_string(i/2 + 1) + "-" + std::to_string(j/2 + 1));

            if (intersects){
                qstr.append("\nLines Intersect");
                qstr.append(QString::fromStdString("\nLines Intersect at (" + std::to_string(PoI.x()).substr(0, std::to_string(PoI.x()).find(".") + 2 + 1) + "," + std::to_string(PoI.y()).substr(0, std::to_string(PoI.y()).find(".") + 2 + 1) +")"));

                QGraphicsTextItem *text = scene[count].addText(qstr);
                text->setPos(xpos, ypos);
                text->setDefaultTextColor(QColor::fromRgb(0, 0, 0));
            }
            else{
                qstr.append("\nLines do not Intersect");
                QGraphicsTextItem *text = scene[count].addText(qstr);
                text->setPos(xpos, ypos);
                text->setDefaultTextColor(QColor::fromRgb(0, 0, 0));
            }

            QGraphicsView* view = new QGraphicsView(&scene[count]);
            CGAL::Qt::GraphicsViewNavigation navigation;
            view->installEventFilter(&navigation);
            view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
            view->viewport()->installEventFilter(&navigation);
            view->setRenderHint(QPainter::Antialiasing);
            view->show();
            count++;
        }
    }

    return app.exec();
}

