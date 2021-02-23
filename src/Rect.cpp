#include"Rect.h"

const int Rect::X_AXIS = 0;
const int Rect::Y_AXIS = 1;
const int Rect::Z_AXIS = 2;

Rect::Rect()
{
    this->_position[Rect::X_AXIS] = 0;
    this->_position[Rect::Y_AXIS] = 0;
    this->_position[Rect::Z_AXIS] = 0;
    this->_dimension[0] = 1;
    this->_dimension[1] = 1;
    this->_color[0] = 255;
    this->_color[1] = 255;
    this->_color[2] = 255;
    this->_speed = 0;
    this->UP = false;
    this->DOWN = false;
    this->RIGHT = false;
    this->LEFT = false;
}

Rect::Rect(float position[3], int dimension[2], float speed)
{
    this->_position[Rect::X_AXIS] = position[0];
    this->_position[Rect::Y_AXIS] = position[1];
    this->_position[Rect::Z_AXIS] = position[2];
    this->_dimension[0] = dimension[0];
    this->_dimension[1] = dimension[1];
    this->_color[0] = 255;
    this->_color[1] = 255;
    this->_color[2] = 255;
    this->_speed = speed;
    this->UP = false;
    this->DOWN = false;
    this->LEFT = false;
    this->RIGHT = false;
}

Rect::~Rect() {}

void Rect::SetX(float x)
{
    this->_position[Rect::X_AXIS] = x;
}

void Rect::SetY(float y)
{
    this->_position[Rect::Y_AXIS] = y;
}

void Rect::SetZ(float z)
{
    this->_position[Rect::Z_AXIS] = z;
}

void Rect::SetSpeed(float speed)
{
    this->_speed = speed;
}

void Rect::SetDimension(int w, int h)
{
    this->_dimension[0] = w;
    this->_dimension[1] = h;
}

void Rect::SetColor(int r, int g, int b)
{
    this->_color[0] = r;
    this->_color[1] = g;
    this->_color[2] = b;
}

void Rect::SetPosition(float x, float y, float z)
{
    this->_position[Rect::X_AXIS] = x;
    this->_position[Rect::Y_AXIS] = y;
    this->_position[Rect::Z_AXIS] = z;
}

float* Rect::GetPosition()
{
    return this->_position;
}

float Rect::GetPosition(int axis)
{
    switch (axis)
    {
    case 0:
        return this->_position[Rect::X_AXIS];
    case 1:
        return this->_position[Rect::Y_AXIS];
    case 2:
        return this->_position[Rect::Z_AXIS];
    default:
        return -1;
    }
}

float Rect::GetSpeed()
{
    return this->_speed;
}

void Rect::Move()
{
    if(UP)
    {
        this->_position[Rect::Y_AXIS] += this->_speed * Utility::deltaTime;
    }
    if(DOWN)
    {
        this->_position[Rect::Y_AXIS] += -this->_speed * Utility::deltaTime;
    }
    if(LEFT)
    {
        this->_position[Rect::X_AXIS] += -this->_speed * Utility::deltaTime;
        if(this->_position[Rect::X_AXIS]-(this->_dimension[0]/2) < -99)
        {
            this->_position[Rect::X_AXIS] = -99+(this->_dimension[0]/2);
        }
    }
    if(RIGHT)
    {
        this->_position[Rect::X_AXIS] += this->_speed * Utility::deltaTime;
        if(this->_position[Rect::X_AXIS]+(this->_dimension[0]/2) > 99)
        {
            this->_position[Rect::X_AXIS] = 99-(this->_dimension[0]/2);
        }
    }
}

void Rect::Calculate()
{
    glTranslatef(this->_position[Rect::X_AXIS], this->_position[Rect::Y_AXIS], this->_position[Rect::Z_AXIS]);
}

void Rect::Draw()
{
    glPushMatrix();
    Calculate();
    glBegin(GL_QUADS);
    glColor3f(this->_color[0], this->_color[1], this->_color[2]);
    glVertex2f(this->_dimension[0]/-2.0f, this->_dimension[1]/-2.0f);
    glVertex2f(this->_dimension[0]/2.0f, this->_dimension[1]/-2.0f);
    glVertex2f(this->_dimension[0]/2.0f, this->_dimension[1]/2.0f);
    glVertex2f(this->_dimension[0]/-2.0f, this->_dimension[1]/2.0f);
    glEnd();
    glPopMatrix();
}
