#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "sphere.h"
#include "pointlight.h"
#include "light.h"
#include  <math.h>



using std::vector;


Pointlight::Pointlight(float r_, float g_, float b_,float x, float y, float z):Light(r_,g_,b_){
  pos=Vec3(x,y,z);
  pos.normalize();
}

Pointlight::~Pointlight(){}

Vec3 Pointlight::getL(Vec3 intersectionPoint){
  Vec3 temp=pos-intersectionPoint;
  temp.normalize();
  return temp;
}
float Pointlight::getintensity(Vec3 intersectionPoint){
  Vec3 temp=pos-intersectionPoint;
  return 1/dot(temp,temp);
}
