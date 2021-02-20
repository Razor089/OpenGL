#define GL_SILENCE_DEPRECATION
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
#include<OpenGL/glu.h>
#include<iostream>
#include"Bar.h"

using namespace std;

void display();
void reshape(int w, int h);
void init();

//Objects
Bar *player;

int main(int args, char** argv)
{
    glutInit(&args, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)/2)-400, (glutGet(GLUT_SCREEN_HEIGHT)/2)-300);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Pong");
    init();

    fprintf(stdout, "The GLUT_WINDOW_WIDTH is %d\nand the GLUT_WINDOW_HEIGHT is %d\n", glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void init()
{   
    int dim[2];
    dim[0] = 200;
    dim[1] = 30;
    player = new Bar(400, 30, 0, dim, 0);
}

void reshape(int w, int h)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, (GLsizei)800, (GLsizei)600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -10, 10);
    glMatrixMode(GL_MODELVIEW);

    player->Draw();

    glutSwapBuffers();
}

void printw(float x, float y, float z, char* format, ...)
{
    
}
