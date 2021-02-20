#ifndef RECT_H
#define RECT_H
#include<OpenGL/gl.h>
class Rect
{
    private:
        float _x, _y, _z;
        float _speed;
        int _dimension[];
        
    public:
        Rect();
        Rect(float x, float y, float z, int dimension[], float speed);
        ~Rect();
        void SetX(float x);
        void SetY(float y);
        void SetZ(float z);
        void SetSpeed(float speed);
        void SetDimension(int w, int h);
        void Calculate();
        void Draw();
        float GetX();
        float GetY();
        float GetZ();
        float GetSpeed();
};

#endif
