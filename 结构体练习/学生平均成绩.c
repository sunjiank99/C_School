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
  puts("������ѧ����ѧ��");
  INF inf;
  scanf("%d",&inf.number);
  fflush(stdin);
  puts("����������");
  gets(inf.name);
  fflush(stdin);
  puts("���������ſ�Ŀ�ĳɼ�");
  int i;
  double sum=0;
  for(i=0;i<3;i++)
  {scanf("%d",&inf.score[i]);
   sum=sum+inf.score[i];
  }
  printf("ƽ���ɼ�Ϊ%lf",sum/3); 
  system("pause");
}
