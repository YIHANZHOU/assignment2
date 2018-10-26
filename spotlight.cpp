#include "pixel.h"
#include  <vector>
#include "Vec3.h"
#include "sphere.h"
#include "scene.h"
#include "spotlight.h"
#include "light.h"
#include <math.h>
using std::vector;
const double PI = 4*atan(1.0);


Spotlight::Spotlight(float r_, float g_, float b_,float px, float py, float pz,float dx,float dy,float dz,float angle1_,float angle2_):Light(r_,g_,b_){
  pos=Vec3(px,py,pz);
  pos.normalize();
  dir=Vec3(dx,dy,dz);
  dir.normalize();
  angle1=angle1_;
  angle2=angle2_;

}

Spotlight::~Spotlight(){}

Vec3 Spotlight::getL(Vec3 intersectionPoint){
  Vec3 temp=pos-intersectionPoint;
  temp.normalize();
  return temp;
}
float Spotlight::getintensity(Vec3 intersectionPoint){
  Vec3 temp2=intersectionPoint-pos;
  int intensity;
  Vec3 temp=temp2;
  temp.normalize();
  float angle=dot(dir,temp);
  float current_angle =180.f*acos(angle)/ PI;

  if(current_angle >=angle2){
    intensity=0;
  }
  else if(current_angle<=angle1){
    intensity=1/dot(temp2,temp2);
  }
  else{
   double temp=angle2-current_angle;
   intensity=pow(temp,0.8)/((angle2-angle1)*dot(temp2,temp2));
   //if (angle>cos((angle1*PI/180)/2)){
    //intensity=dot(temp2,temp2);
  }
  return intensity;
}
