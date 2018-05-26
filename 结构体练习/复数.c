#include<stdio.h>

struct  plural 
{ double real;
  double imag;
}

main()
{puts("请输入两个复数 如3-2i输入：3,-2");
 struct plural number;
 struct plural number1;
 scanf("%lf,%lf",&number.real,&number.imag);
 scanf("%lf,%lf",&number1.real,&number1.imag);
 
 double real;
 double imag;
 
 real=number.real*number1.real-number.imag*number1.imag;
 imag=number.real*number1.imag+number1.real*number.imag;
 
 printf("两个复数相乘的积为%.3lf+%.3lfi",real,imag);
 system("pause");
}
