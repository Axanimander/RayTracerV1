/*
* AUTHOR: Stephen Anderson
* Description: A simple ray tracer using SDL
* Made for fun as a personal project.
* Large speedups gained with -O3 but still not fast, or optimized at all 
*/
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include <iostream>

#include "vec3.h"
#include "sdl_canvas.h"
#include "viewport.h"
#include "raytracer.h"
#include "sphere.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

using std::cerr;
using std::endl;
int main(int argc, char* args[]) {

  SDLCanvas S(640, 640);
  Vec3 O(0,0,0);
  Viewport VP(O,S,1,1);
  Sphere S1(Vec3(0, -1, 3), .5,Color(255,0,0), 500, 0.6);
  Sphere S2(Vec3(1, 0, 4), .5, Color(0,0,255), 500, 0.5);
  Sphere S3(Vec3(-1, 0, 4), .5, Color(0, 255, 0), 10, 0.7);
  Sphere S4(Vec3(0, -5002, 0), 5000, Color(255, 255, 0), 1000, .5);
  Sphere S5(Vec3(0,0,6), 1, Color(0,0,0), 1000, .9);
  Raytracer R(S,VP); //I wrote the whole program to make this joke
  R.addSphere(S1);
  R.addSphere(S2);
  R.addSphere(S3);
  R.addSphere(S4);
  R.addSphere(S5);
  R.addLight(Light('A', 0.2, Vec3(0,0,0)));
  R.addLight(Light('P', 0.6, Vec3(2,1,0)));
  R.addLight(Light('D', 0.2, Vec3(1,4,4)));

  R.render();
  for(int i = 0; i < 20; i++){
    R.moveSphere(0, Vec3(.1,0,0));
    R.moveSphere(1, Vec3(0, .1, 0));
  //  R.moveSphere(2, Vec3(.1,0,0));
   // R.moveLight(2, Vec3(0, 0,-.3));
    R.render();
    
  }
  //Color blue(0, 0, 0xff);
  //S.putPixel(0,0,blue);
  
  SDL_Delay(1000);
}