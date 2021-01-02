#ifndef SDL_CANVAS_H
#define SDL_CANVAS_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include "color.h"


//An interface for us to put pixels on. That's it.
class SDLCanvas {
    private:
        int     width; //Height and width may be adjustable later
        int     height;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface * surface;
        void    addPixelToSurface(int x, int y, Color c);
    public:
                SDLCanvas(int width, int height);
        void    putPixel(int x, int y, Color c); // The only thing we need here
        void    updateCanvas();
        int getWidth();
        int getHeight();
        double left();
        double right();
        double top();
        double bottom();
};

#endif
