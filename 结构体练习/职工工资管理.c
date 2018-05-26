#include<stdio.h>

struct inf
{ int no;
  char name[10];
  int basicsalary;
  int award;
  int insure;
  int salary;
};
typedef struct inf INF;

main()
{
  puts("请输入您要创建的人数n");
  int num,count;
  scanf("%d",&num);
  fflush(stdin);
  
  INF info[num],*str;
  //信息输入区 
  
  for(count=0;count<num;count++)
  {str=&info[count];
   str->no=count+1;
   printf("请输入%d号的姓名\n",str->no);
   gets(str->name);
   fflush(stdin);
   puts("请输入基本工资");
   scanf("%d",&str->basicsalary);
   fflush(stdin);
   puts("请输入奖金");
   scanf("%d",&str->award);
   fflush(stdin);
   puts("请输入保险");
   scanf("%d",&str->insure);
   fflush(stdin);
   str->salary=str->basicsalary+str->award-str->insure;
   printf("实发工资为%d\n\n",str->salary);
   }
  system("pause"); 
} 
