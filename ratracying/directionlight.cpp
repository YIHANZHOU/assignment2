#include "directionlight.h"
#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "sphere.h"
#include "light.h"

using std::vector;


DirectionLight::DirectionLight(float r_, float g_, float b_,float x_, float y_, float z_):Light(r_,g_,b_,x_,y_,z_){

}
DirectionLight::~DirectionLight(){}

Vec3 DirectionLight::getL(Vec3 intersectionPoint){
  return dir*(-1);
}
