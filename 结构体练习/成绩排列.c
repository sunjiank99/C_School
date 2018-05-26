#include<stdio.h>

struct student
{
   char name[10];
   double score;       
};
typedef struct student STD;

void main() 
{    puts("请输入10个学生的姓名-分数");
     int i;
     STD stu[10];
     for(i=0;i<10;i++)
     
     {printf("%d号学生：\n",i+1);        
      scanf("%s%lf",stu[i].name,&stu[i].score);
      fflush(stdin);
     }
     order(stu);
     
     printf(" 名次  姓名  分数  \n");
     for(i=0;i<10;i++)
     {
     printf(" %-5d%-5s     %-5.0lf  \n",i+1,stu[i].name,stu[i].score);
     }
     
     system("pause");
}
order(STD stu[10])
{  int i,j,k;
   STD a;
   for(i=0;i<9;i++)
       { k=i;
        for(j=i+1;j<10;j++) 
          {  if(stu[i].score<stu[j].score)
             {i=j;
             }
             if(i!=k)
             {a=stu[j];
              stu[j]=stu[k];
              stu[k]=a;
             }
          i=k;  
          } 
       }  
}
          
