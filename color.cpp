#include "color.h"


Color::Color(int R, int G, int B) : R(R), G(G), B(B) {}
Color::Color(){
    R = 0;
    G = 0;
    B = 0;
};

std::vector<int> Color::getColors(){
    
    return {R,G,B};
}

Color Color::intensity(double k){
    Color ret(R * k, G * k, B * k);
    return ret;
}

void Color::clamp(){
    R = std::min(255, std::max(0,R));
    G = std::min(255, std::max(0,G));
    B = std::min(255, std::max(0,B));
}


Color Color::operator*(const double& in){
    Color ret;
    ret.R = in * R;
    ret.G = in * G;
    ret.B = in * B;
    return ret;
}


Color Color::operator+(const Color& in){
    Color ret;
    ret.R = R + in.R;
    ret.G = G + in.G;
    ret.B = B + in.B;
    return ret;
}