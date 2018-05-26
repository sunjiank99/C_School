#include<stdio.h>

struct stu
{
       int number;
       char name[10];
       int score[3];
} ;
typedef struct stu INF;
main()
{
  puts("请输入学生的学号");
  INF inf;
  scanf("%d",&inf.number);
  fflush(stdin);
  puts("请输入姓名");
  gets(inf.name);
  fflush(stdin);
  puts("请输入三门科目的成绩");
  int i;
  double sum=0;
  for(i=0;i<3;i++)
  {scanf("%d",&inf.score[i]);
   sum=sum+inf.score[i];
  }
  printf("平均成绩为%lf",sum/3); 
  system("pause");
}
