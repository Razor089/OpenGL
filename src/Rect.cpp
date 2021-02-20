#include"Rect.h"

Rect::Rect()
{
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
    this->_dimension[0] = 1;
    this->_dimension[1] = 1;
    this->_speed = 0;
}

Rect::Rect(float x, float y, float z, int dimension[], float speed)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_dimension[0] = dimension[0];
    this->_dimension[1] = dimension[1];
    this->_speed = speed;
}

Rect::~Rect() {}

void Rect::SetX(float x)
{
    this->_x = x;
}

void Rect::SetY(float y)
{
    this->_y = y;
}

void Rect::SetZ(float z)
{
    this->_z = z;
}

void Rect::SetSpeed(float speed)
{
    this->_speed = speed;
}

void Rect::SetDimension(int w, int h)
{
    //this->_dimension = new[2];
    this->_dimension[0] = w;
    this->_dimension[1] = h;
}

float Rect::GetX()
{
    return this->_x;
}

float Rect::GetY()
{
    return this->_y;
}

float Rect::GetZ()
{
    return this->_z;
}

float Rect::GetSpeed()
{
    return this->_speed;
}

void Rect::Calculate()
{
    glTranslatef(this->_x, this->_y, 0);
}

void Rect::Draw()
{
    glPushMatrix();
    Calculate();
    glBegin(GL_QUADS);
    glColor3f(255, 0, 255);
    glVertex2f(this->_dimension[0]/-2.0f, this->_dimension[1]/-2.0f);
    glVertex2f(this->_dimension[0]/2.0f, this->_dimension[1]/-2.0f);
    glVertex2f(this->_dimension[0]/2.0f, this->_dimension[1]/2.0f);
    glVertex2f(this->_dimension[0]/-2.0f, this->_dimension[1]/2.0f);
    glEnd();
    glPopMatrix();
}
