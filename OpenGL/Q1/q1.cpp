#include <GL/freeglut.h>
#include <GL/glut.h>
#include <fstream>

using namespace std;

GLclampf R, G, B, A;

void setBackground(){
    glClearColor(R, G, B, A);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glFlush();
}

void getInput(){
    ifstream ifile("input.txt", std::ios::in);
    ifile >> R >> G >> B >> A;
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGl - First Window Demo");
    getInput();
    glutDisplayFunc(setBackground);
    glutMainLoop();
    return 0;
}