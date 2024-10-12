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

void displayPoints(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glBegin(GL_POINTS);
        for(int i=0; i< points.size(); i++){
            glVertex2f(points[i].x, points[i].y);
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
    glutCreateWindow("OpenGl - Second Window Demo");
    getInput();
    glutDisplayFunc(displayPoints);
    glutMainLoop();
    return 0;
}