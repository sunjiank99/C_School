#include<stdio.h> 
#include<math.h>

int fn(int a, int n);

void main()
{  int a,n;
   puts("please input a ") ;
   
   scanf("%d",&a);
   
   puts("please input n ");
   
   scanf("%d",&n);
   
   int i,sum=0;
   
   for(i=0;i<n;i++)
   
   {sum=fn(a,i)+sum;
   }
   
   printf("a+aa+aaa+a.....a(%d as) sum = %d",n,sum);
   system("pause");
   
}

int fn(int a, int n)

{  int i,sum=0;
   for(i=0;i<n;i++)
   {
    sum=a*pow(10,i)+sum;
   }
   return sum;    
}
