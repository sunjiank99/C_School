#include<stdio.h>

qiuti()
{   double r;
    puts("请输入球体的半径"); 
    scanf("%lf",&r);
    printf("球体的体积是%lf",4/3*3.1415926535*r*r*r);         
}

yuanzhu()
{   double r;double h;
    puts("请输入圆锥体的底面半径和高");
    scanf("%lf%lf",&r,&h);
    printf("圆锥体的体积是%lf",3.1415926535*r*r*h); 
} 
yuanzui()
{   double r;double h;
    puts("请输入圆锥体的底面半径和高");
    scanf("%lf%lf",&r,&h);
    printf("圆锥体的体积是%lf",3.1415926535*r*r*h/3);
}
main()
{

 puts("请选择功能1-计算球体体积2-计算圆柱体体积3-计算圆锥体体积,其他键-退出");
 while(1)
 {int a;
 scanf("%d",&a);
 switch(a)
 { case 1:qiuti();break;
   case 2:yuanzhu();break;
   case 3:yuanzui();break;
   default:return;
 }
 fflush(stdin);
 }
  
 }
