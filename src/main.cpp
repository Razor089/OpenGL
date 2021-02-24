#define GL_SILENCE_DEPRECATION
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
#include<OpenGL/glu.h>
#include<iostream>
#include"Rect.h"
#include"Line.h"
#include"Ball.h"
#include"utility/utility.h"

using namespace std;

// Prototipi

void display();
void reshape(int w, int h);
void keyboardDown(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void init();
void idle();
void message();

//Objects

Rect *player, *ai, *ball;
Line *separator;

/// Game Variables
int player_score, ia_score;

/// Utility Variables
#define ENTER 13
#define SPACE 32
#define ESC 27
bool start;
bool flag;
int oldTime;

/// Main
int main(int args, char** argv)
{
    glutInit(&args, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)/2)-400, (glutGet(GLUT_SCREEN_HEIGHT)/2)-300);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Pong");

    init();

    fprintf(stdout, "The GLUT_WINDOW_WIDTH is %d\nand the GLUT_WINDOW_HEIGHT is %d\n", glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyboardUp);
    glutKeyboardFunc(keyboardDown);

    glutMainLoop();

    return 0;
}

/// Idle Function
void idle()
{
    Utility::calcDeltaTime();
    
    /// Quando premiamo ENTER parte il timer, passati i due secondi lancia la palla
    if(flag)
    {
        int time = glutGet(GLUT_ELAPSED_TIME);
        if((time-oldTime)/2000 == 1)
        {
            flag = false;
            int dim = ball->GetDimension(Rect::WIDTH);
            ball->SetPosition(Utility::RandomInt(-90+(dim/2), 90-(dim/2)), 0, 0);
            start = true;
        }
    }

    player->Move(-99, 99, 0, 0, 0, 0);

    if(start)
    {
        //Move the ball
    }

    glutPostRedisplay();
}

/// Inizializzazione delle variabili e dello stato di OpenGL
void init()
{   
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    /// Inizializzazione delle variabili di gioco
    player_score = 0;
    ia_score = 0;
    start = false;
    flag = false;

    /// Inizializzazione del giocatore e dell'avversario
    player = new Rect();
    player->SetDimension(32, 5);
    player->SetPosition(0, -90, 0);
    player->SetSpeed(0.08);

    ai = new Rect();
    ai->SetDimension(32, 5);
    ai->SetPosition(0, 90, 0);

    ball = new Ball();
    ball->SetDimension(2,2);
    ball->SetSpeed(0.05);

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

/// Metodo che contiene tutti i messaggi a schermo
void message()
{
    Utility::printw(-90, 3, 0, "Player 1: %d", player_score);
    Utility::printw(55, 3, 0, "Player 2: %d", ia_score);
    if(!flag && !start)
    {
        Utility::printw(-30, 5, 0, "Press 'ENTER' to play");
    }
}

/// Metodo dove si disegna tutto sullo schermo
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    message();

    separator->Draw();
    ai->Draw();
    player->Draw();
    
    if(start)
    {
        ball->Draw();
    }

    glutSwapBuffers();
}

/// Metodo che gestisce gli input da tastiera
void keyboardDown(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a':
            player->LEFT = true;
            break;
        case 'd':
            player->RIGHT = true;
            break;
        case ENTER:
            flag = true;
            oldTime = glutGet(GLUT_ELAPSED_TIME);
            break;
        default:
            break;
    }
}

/// Metodo che gestisce gli input quando i tasti vengono rilasciati
void keyboardUp(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a':
            player->LEFT = false;
            break;
        case 'd':
            player->RIGHT = false;
            break;
        default:
            break;
    }
}
