#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "sphere.h"
#include "pointlight.h"
#include "light.h"
#include  <math.h>



using std::vector;


Pointlight::Pointlight(float r_, float g_, float b_,float x_, float y_, float z_):Light(r_,g_,b_,x_,y_,z_){
}

Pointlight::~Pointlight(){}

Vec3 Pointlight::getL(Vec3 intersectionPoint){
  Vec3 temp=pos-intersectionPoint;
  temp.normalize();
  return temp;
}
float Pointlight::getintensity(Vec3 intersectionPoint){
	Vec3 pos = Vec3(x, y, z);
  Vec3 temp=pos-intersectionPoint;
  return 1/dot(temp,temp);
}
Vec3 Pointlight::getpos(){
  Vec3 temp=Vec3(x,y,z);
  return temp;
}
