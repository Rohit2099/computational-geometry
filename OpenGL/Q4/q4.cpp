#include <GL/freeglut.h>
#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool draw = false;
float xprev, yprev;

void setBackground(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glFlush();
}

void checkPressed(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        if(state==GLUT_DOWN){
            draw = true;
            float mx=x, my=y;
            xprev = (mx/300) - 1.0;
            yprev = -((my/300) - 1.0);
        }
        else if(state==GLUT_UP){
            draw = false;
        }
    }
}


void freeHandDraw(int x, int y){
    if (draw){
        glColor3f(0.0, 0.0, 0.0);
        float mx = x, my = y;
        glPointSize(5.0);
        glLineWidth(4.0);
        glBegin(GL_LINES);
            glVertex2f(xprev, yprev);
            glVertex2f((mx/300) - 1.0, -((my/300) - 1.0));
        glEnd();
        xprev = (mx/300) - 1.0;
        yprev = -((my/300) - 1.0);
        glFlush();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGl - Fourth Window Demo");
    glutMouseFunc(checkPressed);
    glutMotionFunc(freeHandDraw);
    glutDisplayFunc(setBackground);
    glutMainLoop();
    return 0;
}