#ifndef RECT_H
#define RECT_H
#include<OpenGL/gl.h>

/// Classe che disegna un rettangolo
class Rect
{
    private:
        float _x, _y, _z;
        float _speed;
        int _color[3];
        int _dimension[2];
        
    public:
        /// Crea un oggetto rettangolo
        Rect();

        /// Crea un oggetto rettangolo con parametri
        Rect(float x, float y, float z, int dimension[], float speed);

        /// Distruttore
        ~Rect();
        
        /// Imposta la posizione sull'asse X
        void SetX(float x);
        
        /// Imposta la posizione sull'asse Y
        void SetY(float y);
        
        /// Imposta la posizione sull'asse Z
        void SetZ(float z);

        ///Metodo che imposta la velocità
        void SetSpeed(float speed);

        /// Imposta le dimensioni del rettangolo
        /// int w = larghezza
        /// int h = altezza
        void SetDimension(int w, int h);
        
        /// Imposta il colore del rettangolo
        /// int r = 0-255 rosso
        /// int g = 0-255 verde
        /// int b = 0-255 blue
        void SetColor(int r, int g, int b);
        
        /// Metodo che esegue tutti i calcoli di movimento e rotazione
        void Calculate();
        
        /// Metodo che disegna il rettangolo a schermo
        void Draw();
        
        /// Ritorna la posizione sull'asse X
        float GetX();
        
        /// Ritorna la posizione sull'asse Y
        float GetY();
        
        /// Ritorna la posizione sull'asse Z
        float GetZ();
        
        /// Ritorna la velocità
        float GetSpeed();
};

#endif
