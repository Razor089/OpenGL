#define GL_SILENCE_DEPRECATION
#include<GLUT/glut.h>
#include<OpenGL/glu.h>
#include<iostream>

using namespace std;

void display();
void reshape(int w, int h);

int main(int args, char** argv)
{
    glutInit(&args, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)/2)-400, (glutGet(GLUT_SCREEN_HEIGHT)/2)-300);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Pong");

    fprintf(stdout, "The GLUT_WINDOW_WIDTH is %d\nand the GLUT_WINDOW_HEIGHT is %d\n", glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void reshape(int w, int h)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 600, 0);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //gluOrtho2D(0, 800, 600, 0);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    
    glBegin(GL_QUADS);
    glColor3d(123,45,23);
    glVertex2d(0, 0);
    glVertex2d(1, 0);
    glVertex2d(1, 1);
    glVertex2d(0, 1);
    glEnd();

    glutSwapBuffers();
}

void printw(float x, float y, float z, char* format, ...)
{
    
}
