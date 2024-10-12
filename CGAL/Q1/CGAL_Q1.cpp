#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView> 
#include <fstream>
#include <QPen>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;

int main(int argc, char **argv){
    QApplication app(argc, argv);
    Point_2 p;

    QGraphicsScene scene;
    scene.setSceneRect(0,0, 500, 500);
    
    QPen pen;
    pen.setColor(Qt::red);

    std::ifstream ifile("input.txt", std::ios::in);
    while(ifile >> p){
        scene.addEllipse(p.x(), p.y(), 5, 5, pen, QBrush(Qt::red));
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

