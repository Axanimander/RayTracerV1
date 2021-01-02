#include "ray.h"




Ray::Ray(Vec3 O, Vec3 V) : O(O) {
    D = V - O;
}

Vec3 Ray::P(double t) const{
    return O + (D * t);
}

Vec3 Ray::direction() const{
    return D;
}

Vec3 Ray::origin() const{
    return O;
}