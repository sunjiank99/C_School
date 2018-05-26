#include<stdio.h>
#include<string.h>


void main()
{
     puts("please input an integer");
     
     int number;
     char a[20];
     scanf("%d",&number);
     transform(number,a);
     int count;
     for(count=strlen(a)-1;count>=0;count--)
     {
     printf("a[%d]=%c  ",count,a[count]);
     }
     for(count=strlen(a)-1;count>=0;count--)
     {printf("%c",a[count]);}
     system("pause");
     
     
} 

transform(int number,char b[20])
{ 
  if(!number)
  {return;}
  int a;
  
  
  a=number%10;
  static i=0;
  b[i]=a+'0';
  i=i+1;
  b[i]='\0';
  
  transform(number/10,b);
  
}


