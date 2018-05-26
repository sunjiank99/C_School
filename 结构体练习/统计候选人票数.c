#include<stdio.h>
#include<string.h>

struct inf 
{char name[10];
 int score;
};
typedef struct inf CAND;

main()
{puts("这是一个投票系统");
 puts("目前有三位候选人姓名：王强，李丽，张亮");
 CAND inf[3];
 memset(inf[0].name,0,10*sizeof(char));
 memset(inf[1].name,0,10*sizeof(char));
 memset(inf[2].name,0,10*sizeof(char));
 strcpy(inf[0].name,"王强");
 strcpy(inf[1].name,"李丽");
 strcpy(inf[2].name,"张亮");
 
 
 inf[0].score=0;
 inf[1].score=0;
 inf[2].score=0;
 
 int count,choose,i;
 char name[10];
 memset(name,0,10*sizeof(char));
 for(count=0;;count++)
 {puts("请选择功能1-投票 2-查询");
  scanf("%d",&choose);
  fflush(stdin);
  if(choose==1)
  {puts("请输入您所投票的候选人姓名");
   gets(name);
   fflush(stdin);
   for(i=0;i<3;i++)
      {if(strcmp(name,inf[i].name)==0)
        {inf[i].score=inf[i].score+1;
         puts("投票成功");
         memset(name,0,10*sizeof(char));
        }
      } 
  }
  if(choose==2)
  {break;
  }
 }
 // in order
 order( inf[3]);
 
 // output result
 
 puts("名次   姓名    票数   ");
 for(i=0;i<3;i++)
 {
     printf("%d    %s     %d\n",i+1,inf[i].name,inf[i].score);            
 }
 system("pause");
 
 
}

order(CAND stu[3])
{  int i,j,k;
   CAND a;
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





 
