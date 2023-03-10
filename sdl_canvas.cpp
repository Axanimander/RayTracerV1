#include "sdl_canvas.h"
#include <iostream>

SDLCanvas::SDLCanvas(int width, int height) : width(width), height(height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    
  }
  SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
  window = SDL_CreateWindow("Raytracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
  surface = SDL_GetWindowSurface(window);
}

void SDLCanvas::addPixelToSurface(int x, int y, Color c){
  std::vector<int> col = c.getColors();
  unsigned char* pixels = (unsigned char*)surface -> pixels;
  pixels[4 * (y * surface -> w + x) + 0] = col[0];
  pixels[4 * (y * surface -> w + x) + 1] = col[1];
  pixels[4 * (y * surface -> w + x) + 2] = col[2];       
}


void SDLCanvas::putPixel(int x, int y, Color c){
    std::vector<int> colors = c.getColors();
   // SDL_RenderClear(renderer);
  //  SDL_SetRenderDrawColor(renderer, colors[0], colors[1], colors[2],255);
    int screen_x = width/2 + x;
    int screen_y = height/2 - y;
    addPixelToSurface(screen_x, screen_y, c);
   // SDL_RenderDrawPoint(renderer, screen_x, screen_y);
   
    //SDL_RenderPresent(renderer);
}


void SDLCanvas::updateCanvas(){
  if(SDL_UpdateWindowSurface(window) == 0){
    std::cout << "Updated Window Surface\n";
  }
}
int SDLCanvas::getHeight(){
    return height;
}

int SDLCanvas::getWidth(){
    return width;
}

double SDLCanvas::left(){
  return -width/2;
}

double SDLCanvas::right(){
  return width/2;
}

double SDLCanvas::top(){
  return -height/2;
}

double SDLCanvas::bottom(){
  return height/2;
}