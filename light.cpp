#include "light.h"

Light::Light(char type, double intensity, Vec3 pos) : type(type), intensity(intensity), pos(pos) {};

void Light::move(Vec3 dV){
    pos = pos + dV;
}