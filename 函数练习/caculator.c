#include<stdio.h>

qiuti()
{   double r;
    puts("����������İ뾶"); 
    scanf("%lf",&r);
    printf("����������%lf",4/3*3.1415926535*r*r*r);         
}

yuanzhu()
{   double r;double h;
    puts("������Բ׶��ĵ���뾶�͸�");
    scanf("%lf%lf",&r,&h);
    printf("Բ׶��������%lf",3.1415926535*r*r*h); 
} 
yuanzui()
{   double r;double h;
    puts("������Բ׶��ĵ���뾶�͸�");
    scanf("%lf%lf",&r,&h);
    printf("Բ׶��������%lf",3.1415926535*r*r*h/3);
}
main()
{

 puts("��ѡ����1-�����������2-����Բ�������3-����Բ׶�����,������-�˳�");
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
