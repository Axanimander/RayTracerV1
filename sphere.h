#ifndef SPHERE_H

#define SPHERE_H

#include <math.h>

#include "color.h"
#include "vec3.h"
class Sphere{
    public:
        Vec3 center;
        double radius;
        Color color;
        double specular;
        double reflective;
        Sphere(Vec3 center, double radius, Color color, double specular, double reflective);
        Sphere();
        void move(Vec3 dV);

};

#endif