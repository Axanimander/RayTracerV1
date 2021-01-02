#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "sdl_canvas.h"
#include "viewport.h"
#include "ray.h"
#include "sphere.h"
#include "light.h"
#include "hittable.h"
#include <vector>
#include <math.h>
#include <limits>
#include <cassert>
#include <iostream>
#include <tuple>
class Raytracer{
  private:
    SDLCanvas canvas;
    Viewport vp;
    std::vector<Sphere> spheres;
    std::vector<Light> lights;
    Color bg;
    double epsilon;
  public:
    Raytracer(SDLCanvas canvas, Viewport vp);
    void render();
    double computeLighting(Vec3 point, Vec3 normal, Vec3 V, double s);
    std::tuple<Sphere, double> closestIntersection(Ray r, double t1, double t2);
    Color traceRay(Ray r, double t1, double t2, int recursion_depth);
    void addSphere(Sphere s);
    void addLight(Light l);
    void moveSphere(int idx, Vec3 dV);
    void moveLight(int idx, Vec3 dV);
    Vec3 reflectRay(Vec3 R, Vec3 N);
    std::vector<double> intersectRaySphere(Ray r, Sphere s);
      
};

#endif