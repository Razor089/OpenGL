#ifndef BALL_H
#define BALL_H
#include "Rect.h"

class Ball: public Rect
{
    private:
        int _direction;
    public:

        /// Costruttore
        Ball();
        
        /// Costruttore con argomenti
        Ball(float position[3], int dimension[2], float speed);        

        /// Distruttore
        ~Ball();

        /// Metodo di movimento della palla
        void Move(int number);

        /// Metodo che imposta la direzione
        void SetDirection(int dir);

        /// Metodo che ritorna la direzione
        int GetDirection();

        /// Metodo che cambia la direzione laterale della palla
        void ChangeDirection();    
};

#endif
