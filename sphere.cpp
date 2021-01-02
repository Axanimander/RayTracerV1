#include "sphere.h"



Sphere::Sphere(Vec3 center, double radius, Color color, double specular, double reflective) 
: center(center), radius(radius),  color(color), specular(specular), reflective(reflective) {};

Sphere::Sphere(){
    center = Vec3(-1, -1, -1);
    radius = -1;
    color  = Color(-1, -1, -1);
    specular = -1;
}


void Sphere::move(Vec3 dV){
    center = center + dV;
}

/*bool Sphere::hit(const Ray &r, double t1, double t2, hit_record& rec) const {
    Vec3 OC = r.O - center;
    double k1 = r.direction().length_squared();   //r.D.dotProduct(r.D);
    double k2 = dot(OC, r.D);//2 * OC.dotProduct(r.D);
    double k3 = OC.length_squared() - (radius * radius); //OC.dotProduct(OC) - (s.radius * s.radius);
    // Solving the quadratic ((-k2 +- sqrt(k2^2 - 4k1k3))/2k1) see https://www.gabrielgambetta.com/computer-graphics-from-scratch/basic-ray-tracing.html
    double discriminant = k2 * k2 - k1 * k3;
    if(discriminant < 0){
        return false;
    }
    auto sqrtd = sqrt(discriminant);
    auto root = (-k2 - sqrtd) / k1;
    if(root < t1 || t2 < root){
        root = (-k2 + sqrtd) / k1;
        if(root < t1 || t2 < root){
            return false;
        }
    }
    rec.t = root;
    rec.p = r.P(rec.t);
    rec.normal = (rec.p - center) / radius;
    return true;
}*/