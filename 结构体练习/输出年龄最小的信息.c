#include<stdio.h>
struct inf 
{ char name[10];
  int age;
  char address[20];
};

typedef struct inf INFO;
main()
{
   puts("��������������5���˵����������䣬סַ");
   INFO  inf[5];
   int i;
   for(i=0;i<5;i++)
   
      {       printf("������%d�ŵ���Ϣ\n",i+1);
              scanf("%s%d%s",inf[i].name,&inf[i].age,inf[i].address);
              fflush(stdin);     
      }  
   int j,k;
   INFO a;
   a=inf[0];
   for(i=1;i<5;i++)
   { 
     if(a.age>inf[i].age)
    { a=inf[i];
    }
   }
   puts("������С�˵���Ϣ");
   printf("name:%s  age:%d    address:%s",a.name,a.age,a.address);
   system("pause");   
}
 
