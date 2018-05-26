#include<stdio.h>


choose(int number)
{
  int A,B,C;
  
  A=number/1000;
  B=number/100%10;
  C=number/10%10;
  if(A==B+C&&number%11==0)
  {printf("%d   ",number);
  }          
} 
main()
{
      int i;
      for(i=1000;i<10000;i++)
      {choose(i);
      }
      system("pause");
}
