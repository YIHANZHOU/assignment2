#pragma once
#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "light.h"

using std::vector;
class DirectionLight:public Light{
public:
  DirectionLight(float r_, float g_, float b_,float x_, float y_, float z_);
  ~DirectionLight();
   Vec3 getL(Vec3 intersectionPoint);
   Vec3 dir;
};
