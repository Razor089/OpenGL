#define GL_SILENCE_DEPRECATION
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
#include<OpenGL/glu.h>
#include<iostream>
#include"Rect.h"
#include"Line.h"

using namespace std;

// Prototipi

void display();
void reshape(int w, int h);
void init();

//Objects

Rect *player, *ai;
Line *separator;

/// Main
int main(int args, char** argv)
{
    glutInit(&args, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)/2)-400, (glutGet(GLUT_SCREEN_HEIGHT)/2)-300);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Pong");

    fprintf(stdout, "The GLUT_WINDOW_WIDTH is %d\nand the GLUT_WINDOW_HEIGHT is %d\n", glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    init();

    glutMainLoop();

    return 0;
}

/// Inizializzazione delle variabili e dello stato di OpenGL
void init()
{   
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    int dim[2];
    dim[0] = 30;
    dim[1] = 5;
    player = new Rect(0, -90, 0, dim, 0);
    ai = new Rect(0, 90, 0, dim, 0);

    separator = new Line();
    separator->SetPosition(0,0,0);
    separator->SetLength(198);
}

/// Metodo che governa il ridimensionamento della finestra
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)600, (GLsizei)600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/// Metodo dove si disegna tutto sullo schermo
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    separator->Draw();
    ai->Draw();
    player->Draw();

    glutSwapBuffers();
}

/// Metodo che permette di stampare a schermo
void printw(float x, float y, float z, char* format, ...)
{
    
}
