#include "viewport.h"


Viewport::Viewport(Vec3 O, SDLCanvas s, double w, double h) : O(O), s(s),viewportW(w),viewportH(h)  {

}



Vec3 Viewport::canvasToViewportPos(Vec3 pos){
    Vec3 ret;
    ret.e[0] = pos.x() * (viewportW / s.getWidth());
    ret.e[1] = pos.y() * (viewportH / s.getHeight());
    ret.e[2] = 1;
    return ret;
}

Vec3 Viewport::getOrigin(){
    return O;
}

