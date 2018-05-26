#include<stdio.h>
#include<string.h>



void main()
{
 puts("please input a haxedamical number");
 
 int number,i;
 char a[20];
 
 scanf("%d",&number);
 haxe( number, a);
 
 for(i=strlen(a)-1;i>=0;i--)
 {
      printf("%c",a[i]);                    
 }
 
 system("pause");
 
 
     
     
}

haxe(int number,char a[])
{  if(number==0)
    {return;}
    
   int num;
   
   num=number%2;
   
   static int i=0;
   
   a[i]=num+'0';
   
   i=i+1;
   a[i]='\0';           
            
   haxe(number/2,a) ;        
}
 
