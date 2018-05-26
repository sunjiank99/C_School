#include<stdio.h>

reverse(int number)
{
 if(!number)
 
 return;
 
 printf("%d",number%10);
 
 reverse(number/10);
}
main()
{puts("please input a integer");

int number;

scanf("%d",&number);

reverse(number);

system("pause");
}
