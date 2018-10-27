#pragma once

#include "sphere.h"
#include "light.h"
#include "Vec3.h"
#include <cstdio>
#include <vector>
#include <cstring>
#include "pixel.h"
#include <iostream>
using namespace std;
using std::vector;
struct Intersct
{
    // Data
    float hit;
    int index;
    // Constructor
};
class Scene{
public:
  // vector<Directionlight*>Dllist;
  // int Dcount;
  // vector<Pointlight*>Ptlist;
  // int Pcount;
  //
  // vector<Spotlight*>Splist;
  // int Scount;
  // vector<Spotlight*>Amlist;
  // int Acount;
  vector<Sphere>spheres;
  vector<Light*>lights;
   //int count=0;
   float ambient_r;
   float ambient_g;
   float ambient_b;
   float background_r;
   float background_g;
   float background_b;
   int max_depth;
   Scene();
  Pixel raySphereIntersectcolor(Vec3 eye,Vec3 raydir,int index,float t);
  Pixel EvaluateRayTree(Vec3 eye,Vec3 raydir);
  Intersct raySphereIntersect(Vec3 eye,Vec3 raydir);
  int isshadow(Vec3 intersectionPoint,Light l);
  Vec3 reflect(Vec3 intersectionPoint,Light l,int index);
  Vec3 refract(Vec3 intersectionPoint,Light l,int index);

  //vector<light*>light;
};
