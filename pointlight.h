#pragma once
#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "light.h"

using std::vector;
class Pointlight:public Light{
public:
  Pointlight(float r_, float g_, float b_,float x, float y, float z);
   ~Pointlight();
  Vec3 getL(Vec3 intersectionPoint);
  Vec3 pos;
  float getintensity(Vec3 intersectionPoint);
};
