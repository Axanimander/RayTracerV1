#include "raytracer.h"


using std::cerr;
using std::endl;
#define INF std::numeric_limits<double>::infinity()
Raytracer::Raytracer(SDLCanvas canvas, Viewport vp) : canvas(canvas), vp(vp) {
    bg = Color(0,0,0);
    epsilon = .001;
}

void Raytracer::render(){
    for(int x = canvas.left(); x < canvas.right(); x++){
        for(int y = canvas.top(); y < canvas.bottom(); y++){
            Vec3 pos(x, y, 1);
            Vec3 D = vp.canvasToViewportPos(pos);
            Ray r(vp.getOrigin(), D);
            Color c = traceRay(r,1,INFINITY, 10);
            //std::cerr << c.getColors()[2] << std::endl;
            c.clamp();
            canvas.putPixel(x, y, c);
        }
    }
    canvas.updateCanvas();
}

void Raytracer::addSphere(Sphere s){
    spheres.push_back(s);
}

void Raytracer::moveSphere(int idx, Vec3 dV){
    spheres[idx].move(dV);
}

Color Raytracer::traceRay(Ray r, double t1, double t2, int recursion_depth){
    std::tuple<Sphere, double> intersect = closestIntersection(r, t1, t2);
    if(std::get<0>(intersect).radius == -1){
        return bg;
    }
    Sphere closest_sphere = std::get<0>(intersect);
    double closest = std::get<1>(intersect);
    Vec3 point = r.O + (r.D * closest);
    Vec3 normal = point - closest_sphere.center;
    normal = (normal * (1.0/normal.length()));
    double intensity = computeLighting(point, normal, -r.D, closest_sphere.specular);
    Color local_color = closest_sphere.color * intensity;
    if(recursion_depth <= 0 || closest_sphere.reflective <=0){
        return local_color;
    }

    Vec3 R = reflectRay(-r.D, normal);
    Ray reflectedRay(point, R);
    Color reflected_color = traceRay(reflectedRay, epsilon, INFINITY, recursion_depth - 1);

    return (local_color * (1 - closest_sphere.reflective)) + ( reflected_color * closest_sphere.reflective);
    
}

std::vector<double> Raytracer::intersectRaySphere(Ray r, Sphere s){
    std::vector<double> result(2);
    Vec3 OC = r.O - s.center;
    double k1 = dot(r.D, r.D);   //r.D.dotProduct(r.D);
    double k2 = 2 * dot(OC, r.D);//2 * OC.dotProduct(r.D);
    double k3 = dot(OC, OC) - (s.radius * s.radius); //OC.dotProduct(OC) - (s.radius * s.radius);
    // Solving the quadratic ((-k2 +- sqrt(k2^2 - 4k1k3))/2k1) see https://www.gabrielgambetta.com/computer-graphics-from-scratch/basic-ray-tracing.html
    double discriminant = k2 * k2 - 4 * k1 * k3;
    if(discriminant < 0){
        result[0] = INF;
        result[1] = INF;
        return result;
    }
    result[0] = (-k2 + sqrt(discriminant)) / (2 * k1);
    result[1] = (-k2 - sqrt(discriminant)) / (2 * k1);
    return result;
}

double Raytracer::computeLighting(Vec3 point, Vec3 normal, Vec3 V, double s){
    double intensity = 0;
    double length = sqrt(dot(normal, normal));
    double lengthV = sqrt(dot(V,V));
    assert(length != 0);
    double lightdot;
    Vec3 lightv;
    double tmax;
    //cerr << length << " AND THE NORMAL: " << normal.x << "\n";
    //assert(length > 0.9 && length < 1.1);
    for(unsigned int i = 0; i < lights.size(); i++){
        Light light = lights[i];
        if(light.type == 'A'){
            
            intensity += light.intensity;
        }else{
            
            if(light.type == 'P'){
                lightv = light.pos - point;
                //cerr << light.pos.x << " X " <<point.x <<"VX" << lightv.x <<  "\n";
                tmax = 1.0;
            }else{ //Directional light
                lightv = light.pos;
                tmax = INFINITY;
            }
            Ray inter(point, lightv);
            std::tuple<Sphere, double> intersect =  closestIntersection(inter, epsilon, tmax);
            if(std::get<0>(intersect).radius != -1){
                continue;
            }
            lightdot = dot(normal, lightv); //normal.dotProduct(lightv);
            if(lightdot > 0){
                intensity += light.intensity * (lightdot / (length * lightv.length()));
            }
            if(s != -1){ //Specular light property
                double r1 = 2 * dot(normal, lightv);//2 * normal.dotProduct(lightv);
                Vec3 vecr = ((normal * r1) - lightv);
                
                double rdot = dot(vecr, V);//vecr.dotProduct(V);
                if(rdot > 0){
                    intensity += light.intensity * pow((rdot / (vecr.length() * lengthV)), s);
                }
            }
                         //   cerr << "INTENSITY " << intensity <<" "<< point.x << " " << point.y << " " << point.z <<" "<<lightdot<<" " << lightv.length() <<   "\n";
    assert(intensity == intensity);
    
        }
    }

    return intensity;
}

void Raytracer::addLight(Light l){
    lights.push_back(l);
}

void Raytracer::moveLight(int idx, Vec3 dV){
    lights[idx].move(dV);
}

std::tuple<Sphere, double> Raytracer::closestIntersection(Ray r, double t1, double t2){
    double closest = INFINITY;
    Sphere closest_sphere;
    
    for(auto sphere : spheres){
        std::vector<double> ts = intersectRaySphere(r, sphere);
        if(ts[0] < closest && t1 < ts[0] && ts[0] < t2){
            closest = ts[0];
            closest_sphere = sphere;
        }
        if(ts[1] < closest && t1 < ts[1] && ts[1] < t2){
            closest = ts[1];
            closest_sphere = sphere;
        }
    }
    if(closest_sphere.radius != -1){
        return std::tuple<Sphere, double>(closest_sphere, closest);
    }
    return std::tuple<Sphere, double>(closest_sphere, INFINITY);
}

Vec3 Raytracer::reflectRay(Vec3 R, Vec3 N){
    return (N * dot(N,R) - R) * 2;//(N * N.dotProduct(R) - R) * 2;
}