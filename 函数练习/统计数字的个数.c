#include<stdio.h>
int countdigit(char a[],char n); 

void main()

{
 puts("please input a integer");
 
 char a[20];
 gets(a);
 
 puts("please input the number you refer");
 
 char i;
 scanf("%c",&i);
 
 int number;
 number=countdigit(a,i);
 
 printf(" in %s  the number of %c is %d",a,i,number);
 system("pause");
 
} 
int countdigit(char a[],char n)

{
int sum=0,i;

for(i=0;a[i]!='\0';i++)
{if(a[i]==n)
   {sum=sum+1;}
}
return sum;
    
}
