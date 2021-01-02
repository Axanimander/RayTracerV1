#ifndef COLOR_H

#define COLOR_H
#include <vector>
#include <math.h>
#include <algorithm>
class Color{
    public:
        Color();
        Color(int R, int G, int B);
        std::vector<int> getColors();
        Color intensity(double k);
        Color operator*(const double& in);
        Color operator+(const Color& in);
        void clamp();
    private:
        int R;
        int G;
        int B;
};

#endif