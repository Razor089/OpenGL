#ifndef UTILITY_H
#define UTILITY_H
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<ctime>
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
/// Classe con metodi statici di utilita§
class Utility
{
    private:
        static int _vscprintf(const char * format, va_list pargs);
        static int oldTimeSinceStart;
    public:
        /// Variabili
        static int deltaTime;

        /// Metodo che permette di stampare a schermo
        static void printw(float x, float y, float z, char* format, ...);

        /// Metodo per il calcolo del DeltaTime
        static void calcDeltaTime();

        /// Metodo che genera un numero intero casuale nell'intervallo [a,b]
        static int RandomInt(int a, int b);
    
        /// Metodo che genera un numero intero casuale
        static int RandomInt();
};

#endif
