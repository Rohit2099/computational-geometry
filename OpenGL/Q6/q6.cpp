#include <GL/freeglut.h>
#include <GL/glut.h>
#include <fstream>
#include <vector>

using namespace std;

struct Point{
    GLfloat x, y;
};

typedef struct Point Point;

vector<Point> points;

void drawFigure(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
    glLineWidth(2.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glBegin(GL_LINES);
        for(int i = 0; i< points.size() - 1; i++){
            for(int j = i + 1; j< points.size() ; j++){
                glVertex2f(points[i].x, points[i].y);
                glVertex2f(points[j].x, points[j].y);
            }
        }

    glEnd();

    glFlush();
}

void getInput(){
    ifstream ifile("input.txt", std::ios::in);
    Point p;
    while(ifile >> p.x >> p.y){
        points.push_back(p);
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGl - Sixth Window Demo");
    getInput();
    glutDisplayFunc(drawFigure);
    glutMainLoop();
    return 0;
}