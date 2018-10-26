#include "directionlight.h"
#include "scene.h"
#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "sphere.h"
#include "light.h"

using std::vector;


DirectionLight::DirectionLight(float r_, float g_, float b_,float x, float y, float z):Light(r_,g_,b_){
  dir=Vec3(x,y,z);
  dir.normalize();
}
DirectionLight::~DirectionLight(){}

Vec3 DirectionLight::getL(Vec3 intersectionPoint){
  return dir*(-1);
}
