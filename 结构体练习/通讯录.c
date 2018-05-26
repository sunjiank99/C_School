#include<stdio.h>

struct inf 
{char name[10];
 int year;
 int month;
 int day;
 char phone [20];
 char address[20];
};
typedef struct inf INF;

main()
{INF inf[50];

 int choose,count,quantity;

 puts("这是一个能容纳50人的通讯簿");
 //信息输入区      
 for(count=0;;count++)
 {puts("请选择功能1（新建联系人）2（退出）") ;
  scanf("%d",&choose);
  fflush(stdin);
  if(choose==1)
  
         {
               puts("请输入姓名：");
               scanf("%s",inf[count].name);
               fflush(stdin);
               puts("请输入生日（年-月-日）");
               scanf("%d-%d-%d",&inf[count].year,&inf[count].month,&inf[count].day);
               fflush(stdin);
               puts("请输入电话号码");
               gets(inf[count].phone);
               fflush(stdin);
               puts("请输入住址"); 
               gets(inf[count].address);
               fflush(stdin);
         }
  if(choose==2)
  { quantity=count;//记录输入的总人数 
    break;
  }
}  
  
  //信息排列区
  order(inf,quantity);
  
  //信息输出区
  
  puts("姓名--生日--电话号码--家庭住址");
  
  for(count=0;count<quantity;count++)
  {printf("%s  %d-%d-%d  %s    %s\n",inf[count].name,inf[count].year,inf[count].month,inf[count].day,inf[count].phone,inf[count].address);
  }
  
  system("pause"); 
       
}
 
     
 order (INF inf[50],int count)
{ INF a;
    int i,j,k;
    for(i=0;i<count-1;i++)
    {
      k=i;
      for(j=i+1;j<count;j++)
        {
          if(inf[i].year>inf[j].year)
         {i=j;}
          if(inf[i].year==inf[j].year&&inf[i].month>inf[j].month)
         {i=j;}
          if(inf[i].year==inf[j].year&&inf[i].month==inf[j].month&&inf[i].day>inf[j].day)
           {i=j;}
           
          if(i!=k)
          {a=inf[j];
           inf[j]=inf[k];
           inf[k]=a;
          }
         }
      i=k;
     }
}           
           
                            
                          
                          
   
    
    
          
          
          




 

 
