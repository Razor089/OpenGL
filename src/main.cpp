#define GL_SILENCE_DEPRECATION
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
#include<OpenGL/glu.h>
#include<iostream>
#include<math.h>
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
void inizializzaPalla();
void Collisions();
void AiMove();

//Objects

Rect *player, *ai;
Ball *ball;
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
            inizializzaPalla();
            start = true;
        }
    }

    player->Move(-99, 99, 0, 0, 0, 0);
    AiMove();

    if(start)
    {
        ball->Move(ball->GetDirection());
    }

    if(ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) < -99 ||
       ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) > 99)
    {
        ball->ChangeDirection();
    }

    Collisions();

    if(ball->GetPosition(Rect::Y_AXIS)-(ball->GetDimension(Rect::HEIGHT)/2) > 101)
    {
        player_score++;
        start = false;
        flag = false;
        ball->SetPosition(0,0,0);
        ball->SetSpeed(0.08);
    }
    else if(ball->GetPosition(Rect::Y_AXIS)+(ball->GetDimension(Rect::HEIGHT)/2) < -101)
    {
        ia_score++;
        start = false;
        flag = false;
        ball->SetPosition(0,0,0);
        ball->SetSpeed(0.08);
    }

    glutPostRedisplay();
}

/// Metodo per muovere l'avversario
void AiMove()
{
    if(ai->GetPosition(Rect::X_AXIS) < ball->GetPosition(Rect::X_AXIS))
    {
        ai->RIGHT = true;
        ai->LEFT = false;
    }
    else if(ai->GetPosition(Rect::X_AXIS) > ball->GetPosition(Rect::X_AXIS))
    {
        ai->RIGHT = false;
        ai->LEFT = true;
    }
    ai->Move(-99, 99, 0, 0, 0, 0);
}

/// Metodo per il calcolo delle collisioni tra la palla e i giocatori
void Collisions()
{
    /// Collisioni con il giocatore
    if(ball->GetPosition(Rect::Y_AXIS)-(ball->GetDimension(Rect::HEIGHT)/2) <= player->GetPosition(Rect::Y_AXIS)+(player->GetDimension(Rect::HEIGHT)/2))
    {
        if(ball->GetPosition(Rect::Y_AXIS)+(ball->GetDimension(Rect::HEIGHT)/2) < player->GetPosition(Rect::Y_AXIS)-(player->GetDimension(Rect::HEIGHT)/2)) return;

        if(ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= player->GetPosition(Rect::X_AXIS)-(player->GetDimension(Rect::WIDTH)/2) &&
           ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= player->GetPosition(Rect::X_AXIS)+(player->GetDimension(Rect::WIDTH)/2))
        {
            if(ball->GetSpeed() > 0)
            {
                ball->SetSpeed(ball->GetSpeed()+0.01);
            }
            else
            {
                ball->SetSpeed(ball->GetSpeed()-0.01);
            }
            ball->SetSpeed(ball->GetSpeed() * -1);
            if(ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= player->GetPosition(Rect::X_AXIS)-2 &&
               ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= player->GetPosition(Rect::X_AXIS)+2)
            {
                ball->SetDirection(3);
            }
            else if((ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= player->GetPosition(Rect::X_AXIS)-(player->GetDimension(Rect::WIDTH)/2)) &&
                    (ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) < player->GetPosition(Rect::X_AXIS)-(player->GetDimension(Rect::WIDTH)/2)+4))
            {
                ball->SetDirection(1);
            }
            else if((ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= player->GetPosition(Rect::X_AXIS)+(player->GetDimension(Rect::WIDTH)/2)) &&
                    (ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) > player->GetPosition(Rect::X_AXIS)+(player->GetDimension(Rect::WIDTH)/2)-4))
            {
                ball->SetDirection(5);
            }
            else if((ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= player->GetPosition(Rect::X_AXIS)-(player->GetDimension(Rect::WIDTH)/2)+4) &&
                    (ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) < player->GetPosition(Rect::X_AXIS)-(player->GetDimension(Rect::WIDTH)/2)+10))
            {
                ball->SetDirection(2);
            }
            else if((ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= player->GetPosition(Rect::X_AXIS)+(player->GetDimension(Rect::WIDTH)/2)-4) &&
                    (ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) > player->GetPosition(Rect::X_AXIS)+(player->GetDimension(Rect::WIDTH)/2)-10))
            {
                ball->SetDirection(4);
            }
        }
    }

    /// Collisioni con l'avversario
    if(ball->GetPosition(Rect::Y_AXIS)+(ball->GetDimension(Rect::HEIGHT)/2) >= ai->GetPosition(Rect::Y_AXIS)-(ai->GetDimension(Rect::HEIGHT)/2))
    {
        if(ball->GetPosition(Rect::Y_AXIS)-(ball->GetDimension(Rect::HEIGHT)/2) > ai->GetPosition(Rect::Y_AXIS)+(ai->GetDimension(Rect::HEIGHT)/2)) return;

        if(ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= ai->GetPosition(Rect::X_AXIS)-(ai->GetDimension(Rect::WIDTH)/2) &&
           ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= ai->GetPosition(Rect::X_AXIS)+(ai->GetDimension(Rect::WIDTH)/2))
        {
            if(ball->GetSpeed() > 0)
            {
                ball->SetSpeed(ball->GetSpeed()+0.01);
            }
            else
            {
                ball->SetSpeed(ball->GetSpeed()-0.01);
            }
            ball->SetSpeed(ball->GetSpeed() * -1);
            if(ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= ai->GetPosition(Rect::X_AXIS)-2 &&
               ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= ai->GetPosition(Rect::X_AXIS)+2)
            {
                ball->SetDirection(3);
            }
            else if((ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= ai->GetPosition(Rect::X_AXIS)-(ai->GetDimension(Rect::WIDTH)/2)) &&
                    (ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) < ai->GetPosition(Rect::X_AXIS)-(ai->GetDimension(Rect::WIDTH)/2)+4))
            {
                ball->SetDirection(5);
            }
            else if((ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= ai->GetPosition(Rect::X_AXIS)+(ai->GetDimension(Rect::WIDTH)/2)) &&
                    (ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) > ai->GetPosition(Rect::X_AXIS)+(ai->GetDimension(Rect::WIDTH)/2)-4))
            {
                ball->SetDirection(1);
            }
            else if((ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) >= ai->GetPosition(Rect::X_AXIS)-(ai->GetDimension(Rect::WIDTH)/2)+4) &&
                    (ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) < ai->GetPosition(Rect::X_AXIS)-(ai->GetDimension(Rect::WIDTH)/2)+10))
            {
                ball->SetDirection(4);
            }
            else if((ball->GetPosition(Rect::X_AXIS)-(ball->GetDimension(Rect::WIDTH)/2) <= ai->GetPosition(Rect::X_AXIS)+(ai->GetDimension(Rect::WIDTH)/2)-4) &&
                    (ball->GetPosition(Rect::X_AXIS)+(ball->GetDimension(Rect::WIDTH)/2) > ai->GetPosition(Rect::X_AXIS)+(ai->GetDimension(Rect::WIDTH)/2)-10))
            {
                ball->SetDirection(2);
            }
        }
    }
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
    ai->SetSpeed(0.08);

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
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
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

/// Metodo che inizializza la palla
void inizializzaPalla()
{
  int dim = ball->GetDimension(Rect::WIDTH);
  int dir = Utility::RandomInt()%2;
  if(dir == 0)
  {
       ball->SetSpeed(abs(ball->GetSpeed()));
  }
  else
  {
       ball->SetSpeed(ball->GetSpeed()*-1);
  }
  ball->SetPosition(Utility::RandomInt(-90+(dim/2), 90-(dim/2)), 0, 0);
  ball->SetDirection(Utility::RandomInt(1,5));
}
