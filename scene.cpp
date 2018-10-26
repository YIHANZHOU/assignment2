
#include "sphere.h"
#include "Vec3.h"
#include <cstdio>
#include <vector>
#include <cstring>
#include "light.h"
#include "scene.h"
#include <cmath>
#include <algorithm>



// for testing
#include <iostream>
using namespace std;
using std::vector;
using std::max;

Scene::Scene()
{
  vector<Sphere*>spheres;
  int count=0;
  int ambient_r=0;
  int ambient_g=0;
  int ambient_b=0;
}

void Scene::addsphere(Sphere s)
{
	spheres.push_back(s);
}
float Scene::raySphereIntersect(Vec3 eye,Vec3 raydir){
  float t=-1;
  int index=0;
  for (int i=0;i<spheres.size();i++)
  {
     float min=spheres[i].raySphereIntersect(eye,raydir);
     if(0<min<t){
       t=min;
       index=i;
     }else if( min>0>t){
       t=min;
       index=i;
     }
  }
	return t;
}

int Scene::Intersect(Vec3 eye,Vec3 raydir){
  float t=-1;
  int index=0;
  for (int i=0;i<spheres.size();i++)
  {
     float min=spheres[i].raySphereIntersect(eye,raydir);
     if(0<min<t|| min>0>t){
       t=min;
       index=i;
     }
  }
	return index;
}

Pixel Scene::raySphereIntersectcolor(Vec3 eye,Vec3 raydir,vector<Light*>lights,int index,float t){
   Pixel temp2;
   Material m=spheres[index].m;//
   float r,g,b;
   r=m.ar*255*ambient_r;
   g=m.ag*255*ambient_g;
   b=m.ab*255*ambient_b;
   //printf("ambient r%f g%f b%g",ambient_r,ambient_g,ambient_g);
   Vec3 intersectionPoint=eye+raydir*t;
   temp2.SetClamp(double(r),double(g),double(b));
   for (int i=0;i<lights.size();i++){

    if(isshadow(intersectionPoint,*lights[i],index)<0){
       //from intersection point to the light direction
       Vec3 L=lights[i]->getL(intersectionPoint);
       Vec3 N=intersectionPoint-spheres[index].position;
       N.normalize();
       Vec3 V=raydir*(-1);
       Vec3 H=L+V;
       H.normalize();
       float r2,g2,b2;
       float intensity=lights[i]->getintensity(intersectionPoint);
       r2=lights[i]->r*intensity;
       g2=lights[i]->g*intensity;
       b2=lights[i]->b*intensity;
       float max = std::max(dot(N, L), 0.0f);
      // printf("r2%fg2%fb2%fmax%f",m.dr,m.dg,m.db,max);
       r=r+r2*m.dr*max;
       g=g+g2*m.dg*max;
       b=b+b2*m.db*max;
       //printf("r%fg%fb%f",r,g,b);
     }}

   temp2.SetClamp(double(r),double(g),double(b));

  //printf("temp2%hhu",temp2.r);
  return temp2;

}


int Scene::isshadow(Vec3 intersectionPoint,Light l,int index)
{
  int shadow=-1;
  Vec3 L=l.getL(intersectionPoint);
  float lightDistance = (l.pos - intersectionPoint).length();
  for (int i=0;i<spheres.size();i++){
    float hit=spheres[i].raySphereIntersect(intersectionPoint+L*0.001*spheres[i].radius,L);
    printf("hit%f",hit);
          if(hit>=0.1 && hit<lightDistance ){

      shadow=shadow+2;
    }}
    return shadow;

}
