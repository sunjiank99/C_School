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

 puts("����һ��������50�˵�ͨѶ��");
 //��Ϣ������      
 for(count=0;;count++)
 {puts("��ѡ����1���½���ϵ�ˣ�2���˳���") ;
  scanf("%d",&choose);
  fflush(stdin);
  if(choose==1)
  
         {
               puts("������������");
               scanf("%s",inf[count].name);
               fflush(stdin);
               puts("���������գ���-��-�գ�");
               scanf("%d-%d-%d",&inf[count].year,&inf[count].month,&inf[count].day);
               fflush(stdin);
               puts("������绰����");
               gets(inf[count].phone);
               fflush(stdin);
               puts("������סַ"); 
               gets(inf[count].address);
               fflush(stdin);
         }
  if(choose==2)
  { quantity=count;//��¼����������� 
    break;
  }
}  
  
  //��Ϣ������
  order(inf,quantity);
  
  //��Ϣ�����
  
  puts("����--����--�绰����--��ͥסַ");
  
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
           
                            
                          
                          
   
    
    
          
          
          




 

 
