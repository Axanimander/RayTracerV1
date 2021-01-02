#ifndef LIGHT_H
#define LIGHT_H
#include "vec3.h"

class Light{
    public:
        char type;
        double intensity;
        Vec3 pos;
        Light(char type, double intensity, Vec3 pos);
        void move(Vec3 dV);
};
#endif