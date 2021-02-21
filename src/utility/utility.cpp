#include "utility.h"

int Utility::_vscprintf(const char * format, va_list pargs)
{
    int retval; 
      va_list argcopy; 
      __va_copy(argcopy, pargs); 
      retval = vsnprintf(NULL, 0, format, argcopy); 
      va_end(argcopy); 
      return retval; 
}

void Utility::printw(float x, float y, float z, char* format, ...)
{
    /// Lista Argomenti variabili
    va_list args;
    int len;
    int i;
    char* text;

    /// Inizializziamo la lista di argomenti
    va_start(args, format);

    /// Prendiamo il numero di caratteri
    len = _vscprintf(format, args) + 1;

    /// Allochiamo memoria per una stringa
    text = (char*)malloc(len * sizeof(char));

    vsnprintf(text, len, format, args);

    va_end(args);

    /// Specifichiamo la posizione della scritta
    glRasterPos3f(x, y, z);

    /// Disegniamo uno a uno i caratteri
    for(i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

    free(text);
}