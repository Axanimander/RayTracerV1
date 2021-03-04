# RayTracerV1
A Simple SDL Raytracer made in C++

# To make it go
* Just run make
* You need an xwindow environment or the like
* The program was tested using `vcxsrv` from within WSL
* Should just run natively on Linux with SDL2 installed
**Requires SDL2**

# Instructions
* Use `main.cpp` to create spheres and mess with lighting, an example is in place

# Troubleshooting
Getting this error:
```
libGL error: No matching fbConfigs or visuals found
libGL error: failed to load driver: swrast
malloc(): corrupted top size
```
or some equivalent? Run:
`sudo ldconfig -p | grep -i gl.so`
and look for any files on the right that have `.1` on the end. If they exist, enter
`sudo mv </file/location/file_name.so>.1 </file/location/file_name.so>.1.ORIGINAL`
for example:
`sudo mv /lib/x86_64-linux-gnu/libGL.so.1 /lib/x86_64-linux-gnu/libGL.so.1.ORIGINAL`

# What is it
* This is a ray tracer built from scratch using the SDL API to *only* place pixels individually, everything else is hand made by me

# Features
* Sphere rendering
* Specularity
* Shadows
* Reflections

# Example

* Here is a simple scene.

![Gif1](/res/Gif1.gif)
