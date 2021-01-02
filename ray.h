#ifndef RAY_H

#define RAY_H
#include "vec3.h"
class Ray{
    public:
        Vec3 P(double t) const;
        Vec3 D;
        Vec3 O;
        Vec3 direction() const;
        Vec3 origin() const;
        Ray();
        Ray(Vec3 O, Vec3 D);
};

#endif