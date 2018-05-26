#include<stdio.h>
 

leap(int a)
{  if(a%100==0&&a%400==0)
    {
        return 1;                 
    }
   if(a%100!=0&&a%4==0)
    {   return 1; 
    
    }
   return 0; 
}


void main()

{ while(1)
{
  puts("please input year-month-day");
  int year,month,day;
  scanf("%d-%d-%d",&year,&month,&day);
  countdays(year,month,day);
  fflush(stdin);
}  
  
} 

countdate(int year,int m,int c)
{ int s;
  if(leap(year)==1)
  
  {switch (m)
		{
		case 1:
			s = 0 + c;
			break;
		case 2:
			s = 0 + 31 + c;
			break;

		case 3:
			s = 0 + 31 + 29 + c; break;
		case 4:
			s = 0 + 31 + 29 + 31 + c; break;
		case 5:
			s = 0 + 31 + 29 + 31 + 30 + c; break;
		case 6:
			s = 0 + 31 + 29 + 31 + 30 + 31 + c; break;
		case 7:
			s = 0 + 31 + 29 + 31 + 30 + 31 + 30 + c; break;

		case 8:s = 0 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + c; break;
		case 9:s = 0 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + c; break;
		case 10: s = 0 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c; break;
		case 11:s = 0 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c; break;
		case 12:s = 0 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c; break;
		}
   }
   if(leap(year)==0)
   {  switch (m)
		{
		case 1:
			s = 0 + c;
			break;
		case 2:
			s = 0 + 31 + c;
			break;

		case 3:
			s = 0 + 31 + 28 + c; break;
		case 4:
			s = 0 + 31 + 28 + 31 + c; break;
		case 5:
			s = 0 + 31 + 28 + 31 + 30 + c; break;
		case 6:
			s = 0 + 31 + 28 + 31 + 30 + 31 + c; break;
		case 7:
			s = 0 + 31 + 28 + 31 + 30 + 31 + 30 + c; break;

		case 8:s = 0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + c; break;
		case 9:s = 0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + c; break;
		case 10: s = 0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c; break;
		case 11:s = 0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c; break;
		case 12:s = 0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c; break;
        }
   }
   return s;
}   
countdays(int year,int m,int d)
{   int count,sum=0;
    for(count=1900;count<year;count++)
    {   if(leap(year)==0)
         {sum=sum+366;
         }
        if(leap(year)==1)
        {
           sum=sum+365;              
        }
    }    
    sum=sum+countdate(year,m,d);
    
    if((sum%5)==3)
    {puts("渔夫在打鱼");
    }
    else if((sum%5)==0)
    {puts("渔夫在晒网");
    }
    else
    {puts("渔夫什么也没做"); 
    }
}    
    
      
   
