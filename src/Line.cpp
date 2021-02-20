#include "Line.h"

const int Line::X_AXES = 0;
const int Line::Y_AXES = 1;
const int Line::Z_AXES = 2;

Line::Line()
{
    this->_position[Line::X_AXES] = 0;
    this->_position[Line::Y_AXES] = 0;
    this->_position[Line::Z_AXES] = 0;
    this->_speed = 0;
    this->_length = 1;
    this->_color[0] = 255;
    this->_color[1] = 255;
    this->_color[2] = 255;
}

Line::Line(float position[3], float speed, int length)
{
    this->_position[Line::X_AXES] = position[0];
    this->_position[Line::Y_AXES] = position[1];
    this->_position[Line::Z_AXES] = position[2];
    this->_speed = speed;
    this->_length = length;
    this->_color[0] = 255;
    this->_color[1] = 255;
    this->_color[2] = 255;
}

Line::~Line() {}

void Line::SetColor(int r, int g, int b)
{
    this->_color[0] = r;
    this->_color[1] = g;
    this->_color[2] = b;
}

void Line::SetLength(int length)
{
    this->_length = length;
}

void Line::SetPosition(float x, float y, float z)
{
    this->_position[Line::X_AXES] = x;
    this->_position[Line::Y_AXES] = y;
    this->_position[Line::Z_AXES] = z;
}

void Line::SetSpeed(float speed)
{
    this->_speed = speed;
}

float Line::GetPosition(int axes)
{
    switch (axes)
    {
    case 0:
        return this->_position[Line::X_AXES];
    case 1:
        return this->_position[Line::Y_AXES];
    case 2:
        return this->_position[Line::Z_AXES];
    default:
        return -1;
    }
}

float* Line::GetPosition()
{
    return this->_position;
}

int Line::GetLength()
{
    return this->_length;
}

void Line::Calculate()
{
    glTranslatef(this->_position[Line::X_AXES], this->_position[Line::Y_AXES], this->_position[Line::Z_AXES]);
}

void Line::Draw()
{
    glPushMatrix();
    this->Calculate();
    glColor3f(this->_color[0], this->_color[1], this->_color[2]);
    glBegin(GL_LINES);
    glVertex3f((0-this->_length/2), 0, 0);
    glVertex3f((0+this->_length/2), 0, 0);
    glEnd();
    glPopMatrix();
}