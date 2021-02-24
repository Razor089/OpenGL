#include "ball.h"

Ball::Ball()
{
    this->_position[Rect::X_AXIS] = 0;  
    this->_position[Rect::Y_AXIS] = 0; 
    this->_position[Rect::Z_AXIS] = 0;  
    this->_dimension[0] = 0;
    this->_dimension[1] = 0;
    this->_color[0] = 255;
    this->_color[1] = 255;
    this->_color[2] = 255;
    this->UP = false;
    this->DOWN = false;
    this->LEFT = false;
    this->RIGHT = false;
}

Ball::Ball(float position[3], int dimension[2], float speed)
{
    this->_position[Rect::X_AXIS] = position[0];
    this->_position[Rect::Y_AXIS] = position[1];
    this->_position[Rect::Z_AXIS] = position[2];
    this->_dimension[0] = dimension[0];
    this->_dimension[1] = dimension[1];
    this->_speed = speed;
    this->UP = false;
    this->DOWN = false;
    this->LEFT = false;
    this->RIGHT = false;
}
