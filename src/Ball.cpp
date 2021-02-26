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

void Ball::Move(int number)
{
    switch(number)
    {
        case 1:
            this->_position[Rect::X_AXIS] += 2*-this->_speed * Utility::deltaTime;
            this->_position[Rect::Y_AXIS] += this->_speed * Utility::deltaTime;
            break; 
        case 2:
            this->_position[Rect::X_AXIS] += -this->_speed * Utility::deltaTime;
            this->_position[Rect::Y_AXIS] += this->_speed * Utility::deltaTime;
            break;
        case 3:
            this->_position[Rect::Y_AXIS] += this->_speed * Utility::deltaTime;
            break;
        case 4:
            this->_position[Rect::X_AXIS] += this->_speed * Utility::deltaTime;
            this->_position[Rect::Y_AXIS] += this->_speed * Utility::deltaTime;
            break;
        case 5:
            this->_position[Rect::X_AXIS] += 2*this->_speed * Utility::deltaTime;
            this->_position[Rect::Y_AXIS] += this->_speed * Utility::deltaTime;
            break;
        default:
            break;
    }
}

void Ball::SetDirection(int dir)
{
    this->_direction = dir;
}

int Ball::GetDirection()
{
    return this->_direction;
}

void Ball::ChangeDirection()
{
    switch(this->_direction)
    {
        case 1:
            this->_direction = 5;
            break;
        case 2:
            this->_direction = 4;
            break;
        case 4:
            this->_direction = 2;
            break;
        case 5:
            this->_direction = 1;
            break;
        default:
            break;
    }
}
