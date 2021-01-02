#ifndef VIEWPORT_H

#define VIEWPORT_H
#include "vec3.h"
#include "sdl_canvas.h"
class Viewport{
    Vec3 O; //camera position
    SDLCanvas s;
    double viewportW;
    double viewportH;
    
    public:
        Viewport(Vec3 O, SDLCanvas s, double w, double h);
        Vec3 canvasToViewportPos(Vec3 pos);
        Vec3 getOrigin();
};

#endif