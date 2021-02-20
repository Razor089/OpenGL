#ifndef BAR_H
#define BAR_H
#include<OpenGL/gl.h>
class Bar
{
    private:
        float _x, _y, _z;
        float _speed;
        int _dimension[];
        
    public:
        Bar();
        Bar(float x, float y, float z, int dimension[], float speed);
        ~Bar();
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
