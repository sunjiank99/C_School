#include<stdio.h>
double cylinder(float r,float h);
void main()
{
     puts("please input cylinder's radius");
     double radius;
     
     scanf("%lf",&radius);
     
     puts("please input cylinder's height");
     double height;
     
     scanf("%lf",&height);
     
     double V;
     
     V=cylinder(radius,height);
     
     printf("the volume of cylinder is %lf",V);
     
     system("pause");
}

double cylinder(float r,float h)
{
  double V;
  V=3.1415926535*r*r*h;
  return V;
}
