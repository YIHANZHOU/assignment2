#include "pixel.h"
#include  <vector>
#include "sphere.h"
#include "light.h"
#include "Vec3.h"
using std::vector;



Light::Light()
{
	r=g=b=0;
	x=y=z=0;
}

Light::Light(float r_,float g_,float b_,float x_,float y_,float z_)
{
	r=r_;
	g=g_;
	b=b_;
	x=x_;
	y=y_;
	z=z_;
}

Light::~Light() {}
Vec3 Light::getL(Vec3 intersectionPoint){
	return Vec3(0, 0, 0);
}
float Light::getintensity(Vec3 intersectionPoint){
	return 1;
}

