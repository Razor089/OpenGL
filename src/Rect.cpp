#include"Rect.h"

/// Crea un oggetto rettangolo
Rect::Rect()
{
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
    this->_dimension[0] = 1;
    this->_dimension[1] = 1;
    this->color[0] = 255;
    this->color[1] = 255;
    this->color[2] = 255;
    this->_speed = 0;
}

/// Crea un oggetto rettangolo con parametri
Rect::Rect(float x, float y, float z, int dimension[], float speed)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_dimension[0] = dimension[0];
    this->_dimension[1] = dimension[1];
    this->color[0] = 255;
    this->color[1] = 255;
    this->color[2] = 255;
    this->_speed = speed;
}

/// Distruttore
Rect::~Rect() {}

/// Imposta la posizione sull'asse X
void Rect::SetX(float x)
{
    this->_x = x;
}

/// Imposta la posizione sull'asse Y
void Rect::SetY(float y)
{
    this->_y = y;
}

/// Imposta la posizione sull'asse Z
void Rect::SetZ(float z)
{
    this->_z = z;
}


void Rect::SetSpeed(float speed)
{
    this->_speed = speed;
}

/// Imposta le dimensioni del rettangolo
/// int w = larghezza
/// int h = altezza
void Rect::SetDimension(int w, int h)
{
    //this->_dimension = new[2];
    this->_dimension[0] = w;
    this->_dimension[1] = h;
}

/// Imposta il colore del rettangolo
/// int r = 0-255 rosso
/// int g = 0-255 verde
/// int b = 0-255 blue
void Rect::SetColor(int r, int g, int b)
{
    this->color[0] = r;
    this->color[1] = g;
    this->color[2] = b;
}

/// Ritorna la posizione sull'asse X
float Rect::GetX()
{
    return this->_x;
}

/// Ritorna la posizione sull'asse Y
float Rect::GetY()
{
    return this->_y;
}

/// Ritorna la posizione sull'asse Z
float Rect::GetZ()
{
    return this->_z;
}

/// Ritorna la velocità come float.
float Rect::GetSpeed()
{
    return this->_speed;
}

/// Metodo che esegue tutti i calcoli di movimento e rotazione
void Rect::Calculate()
{
    glTranslatef(this->_x, this->_y, 0);
}

/// Metodo che disegna il rettangolo a schermo
void Rect::Draw()
{
    glPushMatrix();
    Calculate();
    glBegin(GL_QUADS);
    glColor3f(this->color[0], this->color[1], this->color[2]);
    glVertex2f(this->_dimension[0]/-2.0f, this->_dimension[1]/-2.0f);
    glVertex2f(this->_dimension[0]/2.0f, this->_dimension[1]/-2.0f);
    glVertex2f(this->_dimension[0]/2.0f, this->_dimension[1]/2.0f);
    glVertex2f(this->_dimension[0]/-2.0f, this->_dimension[1]/2.0f);
    glEnd();
    glPopMatrix();
}
