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
  puts("��������Ҫ����������n");
  int num,count;
  scanf("%d",&num);
  fflush(stdin);
  
  INF info[num],*str;
  //��Ϣ������ 
  
  for(count=0;count<num;count++)
  {str=&info[count];
   str->no=count+1;
   printf("������%d�ŵ�����\n",str->no);
   gets(str->name);
   fflush(stdin);
   puts("�������������");
   scanf("%d",&str->basicsalary);
   fflush(stdin);
   puts("�����뽱��");
   scanf("%d",&str->award);
   fflush(stdin);
   puts("�����뱣��");
   scanf("%d",&str->insure);
   fflush(stdin);
   str->salary=str->basicsalary+str->award-str->insure;
   printf("ʵ������Ϊ%d\n\n",str->salary);
   }
  system("pause"); 
} 
