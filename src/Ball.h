#ifndef BALL_H
#define BALL_H
#include "Rect.h"

class Ball: public Rect
{
    public:
        /// Costruttore
        Ball();
        
        /// Costruttore con argomenti
        Ball(float position[3], int dimension[2], float speed);        

        /// Distruttore
        ~Ball();    
};

#endif
