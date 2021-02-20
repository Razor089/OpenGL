#include"bar.h"

Bar::Bar()
{
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
    this->_dimension[0] = 1;
    this->_dimension[1] = 1;
    this->_speed = 0;
}

Bar::Bar(float x, float y, float z, int dimension[], float speed)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_dimension[0] = dimension[0];
    this->_dimension[1] = dimension[1];
    this->_speed = speed;
}

Bar::~Bar() {}

void Bar::SetX(float x)
{
    this->_x = x;
}

void Bar::SetY(float y)
{
    this->_y = y;
}

void Bar::SetZ(float z)
{
    this->_z = z;
}

void Bar::SetSpeed(float speed)
{
    this->_speed = speed;
}

void Bar::SetDimension(int w, int h)
{
    //this->_dimension = new[2];
    this->_dimension[0] = w;
    this->_dimension[1] = h;
}

float Bar::GetX()
{
    return this->_x;
}

float Bar::GetY()
{
    return this->_y;
}

float Bar::GetZ()
{
    return this->_z;
}

float Bar::GetSpeed()
{
    return this->_speed;
}

void Bar::Calculate()
{
    glTranslatef(this->_x, this->_y, 0);
}

void Bar::Draw()
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
