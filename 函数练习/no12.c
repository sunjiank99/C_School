#include<stdio.h>



  gys(int x,int y)
{  int a,b,c;
   
   if(x<y)
   {  a=x;
      x=y;
      y=a;
   }
   
   for(;;)
    {
     c=x%y;
     if(c==0)
     {return y;}
     x=y;
     y=c;
     }
  
   
}


int gbs(int x,int y)
{
   int i;
   
   for(i=1;;i++)
   {if(x*i%y==0)
     {return x*i;}
   }    
}

void yuefen(int fz,int fm)
{int s=gys(fz,fm);
  fz = fz/s;
  fm = fm/s;
  printf("the result is %d/%d\n",fz,fm);
  
}
add(int x,int y,int z,int h)
{int a,b;
 a=x*h+z*y;
 b=y*h;
 puts("和：");
 yuefen(a,b);
}
sub (int x,int y,int z,int h)
{int a,b;
 a=x*h-z*y;
 b=y*h;
 puts("差：");
 yuefen(a,b);
}
mul( int x,int y,int z,int h)
{ int a,b;
  a=x*z;
  b=y*h;
  puts("乘：");
  yuefen(a,b);
}
div(int x,int y,int z,int h)
{int a,b;
 a=x*h;
 b=y*z;
 puts("除以：");
 yuefen(a,b); 
}

main()
{
puts("请输入两个分数：输入形式（分子，分母）");
int a,b,c,d;
 scanf("%d,%d",&a,&b);
 scanf("%d,%d",&c,&d);
 add(a,b,c,d);
 sub(a,b,c,d);
 mul(a,b,c,d);
 div(a,b,c,d);
 system("pause");
 }
      
      
      
      
      
      
      

