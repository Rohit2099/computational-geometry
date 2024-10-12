#include <GL/freeglut.h>
#include <GL/glut.h>
#include <fstream>
#include <vector>

using namespace std;    
    
struct Point{
    GLfloat x, y, z;
};

typedef struct Point Point;

vector<Point> points;

void getInput(){
    ifstream ifile("input.txt", std::ios::in);
    Point p;
    while(ifile >> p.x >> p.y >> p.z){
        points.push_back(p);
    }
}

void drawQuads(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glBegin(GL_QUADS);
        for(int i=0; i<points.size(); i+=4){
            glColor3f(i==0, i==4, i==8);
            glVertex3f(points[i + 3].x, points[i + 3].y, points[i + 3].z);
            glVertex3f(points[i + 2].x, points[i + 2].y, points[i + 2].z);
            glVertex3f(points[i + 1].x, points[i + 1].y, points[i + 1].z);
            glVertex3f(points[i].x, points[i].y, points[i].z);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGl - Fifth Window Demo"); 
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    getInput();
    glutDisplayFunc(drawQuads); 
    glutMainLoop();
    return 0;
}