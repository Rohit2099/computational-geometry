#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsView> 
#include <fstream>
#include <QPen>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
#include <CGAL/Line_2.h>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
typedef K::Line_2 Line_2;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0,0, 500, 500);
    
    QPen pen;
    pen.setColor(Qt::black);

    std::ifstream ifile("input.txt", std::ios::in);
    float x1, y1, x2, y2;
    while(ifile >> x1 >> y1 >> x2 >> y2){
        QLineF l1(x1, y1, x2, y2);
        scene.addLine(l1, pen);
    }
 
    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();

    return app.exec();
}

