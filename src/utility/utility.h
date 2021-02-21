#ifndef UTILITY_H
#define UTILITY_H
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
/// Classe con metodi statici di utilita§
class Utility
{
    private:
        static int _vscprintf(const char * format, va_list pargs);
    public:
        /// Metodo che permette di stampare a schermo
        static void printw(float x, float y, float z, char* format, ...);
};

#endif