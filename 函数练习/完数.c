#include<stdio.h>

int factorsum(int number) 
{
  int i,sum=1;
  
  for(i=2;i<=(number/2);i++)
  
  {
   if(number%i==0)
   {sum=sum+i;}                        
  }    
    
    return sum;
    
}

main()
{ int m,n,i;
  puts("输入两个正数m和n（m≥1，n≤10000）");
  scanf("%d%d",&m,&n);
  
  for(i=m;i<=n;i++)
  {if(i==factorsum(i))
     {printf("%d  ",i);}              
  }
  
  system("pause");    
      
      
}
