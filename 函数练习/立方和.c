#include<stdio.h>
#include<math.h>

int is(int i)
{
    int a1,a2,a3,a4,a5,sum;
    
    a1=i%10;
    a2=i%100/10;
    a3=i%1000/100;
    a4=i%10000/1000;
    a5=i%100000/10000;
    sum=pow(a1,3)+pow(a2,3)+pow(a3,3)+pow(a4,3)+pow(a5,3);
return sum;
}    
void main()

{ int m,n,i;
puts("输入两个正数m和n（m≥1，n≤10000）");
scanf("%d%d",&m,&n);
for(i=m;i<=n;i++)
if(i==is(i))
{printf("%d   ",i);}

system("pause");
     
     
} 
