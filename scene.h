#pragma once

#include "sphere.h"
#include "light.h"
#include "Vec3.h"
#include <cstdio>
#include <vector>
#include <cstring>
#include "pixel.h"

// for testing
#include <iostream>
using namespace std;
using std::vector;
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
   int count=0;
   float ambient_r;
   float ambient_g;
   float ambient_b;
  Scene();
  void addsphere(Sphere s);
  Pixel raySphereIntersectcolor(Vec3 eye,Vec3 raydir,vector<Light*>lights,int index,float t);
  float raySphereIntersect(Vec3 eye,Vec3 raydir);
  int Intersect(Vec3 eye,Vec3 raydir);
  int isshadow(Vec3 intersectionPoint,Light l,int index);
  //vector<light*>light;
};
