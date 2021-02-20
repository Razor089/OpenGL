#ifndef LINE_H
#define LINE_H
#include<OpenGL/gl.h>

/// Classe che disegna una linea
class Line
{
    private:
        float _position[3];
        int _color[3];
        float _speed;
        int _length;

    public:

        /// Costanti

        static const int X_AXES;
        static const int Y_AXES;
        static const int Z_AXES;

        /// Crea un oggetto Linea
        Line();

        /// Crea un oggetto Linea con argomenti
        Line(float position[3], float speed, int length);

        /// Distruttore
        ~Line();

        /// Imposta la posizione sugli assi X, Y e Z
        void SetPosition(float x, float y, float z);

        /// Imposta la velocità
        void SetSpeed(float speed);

        /// Imposta il colore
        void SetColor(int r, int g, int b);

        /// Imposta la lunghezza
        void SetLength(int length);

        /// Calcolo delle trasformazioni
        void Calculate();

        /// Disegna una linea sullo schermo
        void Draw();

        /// Ritorna il vettore posizione
        float* GetPosition();

        /// Rtorna la posizione sull'asse selezionato
        /// X-AXES
        /// Y-AXES
        /// Z-AXES
        float GetPosition(int axis);

        /// Ritorna la velocità
        float GetSpeed();

        /// Ritorna la lunghezza
        int GetLength();
};

#endif