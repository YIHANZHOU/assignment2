#include "light.h"
#include "pixel.h"
#include "sphere.h"
Light::Light()
{
	r=g=b=0;
	pos=Vec3(0,0,0);
}

Light::Light(float r_,float g_,float b_)
{
	r=r_;
	g=g_;
	b=b_;
}

Light::~Light() {}
Vec3 Light::getL(Vec3 intersectionPoint){
   return Vec3(0,0,0);
 }
float Light::getintensity(Vec3 intersectionPoint){
	 return 1;
}
