#include<stdio.h>
int fib(int y);

void main()
{ puts("please intput m and n (m>=1,n<=10000)");
  int m,n,i,number;
  
  
  
  scanf("%d%d",&m,&n);
  
  for(i=1;;i++)
  { number=fib(i);
   if(number>=m&&number<=n)
   {printf("%d  ",number);
   }
   else if(number>n)
   {break;
   }
   
  }

  
  
     system("pause");
     
     
} 


int fib(int y)
{int a[30],i;
  
  a[0]=1;
  a[1]=1;
  
  for(i=2;i<30;i++)
  {a[i]=a[i-1]+a[i-2];}
  
  return a[y-1];
  
  
}
