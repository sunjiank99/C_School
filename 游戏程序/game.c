#include<stdio.h>
#include<string.h>
#include<time.h>
#include <Windows.h>
#include"color.h"
int STAR(int *money);

void main()
{    
     
     int qq=0;
     int *addmoney=&qq; 
    if(STAR(addmoney)==0)
    {   DRED_BLACK;
        puts("��Ϸ��ʼ");
        struct car
        {  char name[20];
           int number;
           int beilv;
        } ;
        struct car inf[8];
        //�����ÿ��д��Ѻע����Ʒ����Ϣ 
        int i;
        for(i=1;i<=7;i++)
        {inf[i].number=i;
        }
        //���� 
        strcpy(inf[1].name,"����");
        strcpy(inf[2].name,"����");
        strcpy(inf[3].name,"����");
        strcpy(inf[4].name,"�ִ�");
        strcpy(inf[5].name,"����");
        strcpy(inf[6].name,"����");
        strcpy(inf[7].name,"����");
        //����
        inf[1].beilv=1;
        inf[2].beilv=7;
        inf[3].beilv=3;
        inf[4].beilv=20;
        inf[5].beilv=100;
        inf[6].beilv=10;
        inf[7].beilv=5;
        
        //��Ϸ��ʼ
        //��ʾ�û���Ϣ 
        
        int money=0;
        money=*addmoney; //��� 
         PURPLE_BLACK;
        printf("���룺");
        for(i=1;i<=7;i++)
        {printf("%5d  ",inf[i].number);
        }
        puts(""); 
        printf("Ʒ�ƣ�"); 
        for(i=1;i<=7;i++)
        {   
           printf("%5s  ",inf[i].name); 
        }
        puts("");
         printf("���ʣ�");
        for(i=1;i<=7;i++)
        {   
           printf("%5d  ",inf[i].beilv);              
        }
        puts("");
       A: printf("�����ڵĽ��Ϊ%d",money); 
         
       //��ʼѺע
       puts("��ѡ����ҪѺע�ĳ��ƺ��밴�س���ʼ"); 
       int haoma,suijihaoma;
       
       scanf("%d",&haoma);
       //������趨 
       srand((unsigned)time(NULL));
       
       suijihaoma=rand()%8;
       
       //���� 
       
       if(haoma==suijihaoma)
       
       { RED_BLACK;
         printf("�˴ο�������Ϊ%s ����õĽ��Ϊ%d\n",inf[suijihaoma].name,inf[suijihaoma].beilv);
         money=money+inf[suijihaoma].beilv;
         }                   
       else
       { 
         
         DGREEN_BLACK;
         if(suijihaoma!=0)
         {printf("�˴ο�������Ϊ%s ��û���н������˽��%d\n",inf[suijihaoma].name,inf[haoma].beilv);}
         else
         {printf("�˴�û���κο������ƿ������ٽ�������\n");}
                                  
         money=money-inf[haoma].beilv;
       }
       if(money>0)
       {
       goto A;    
       }
       else
       { printf("���Ľ�Ҳ���\n");
         printf("\n\n\n��û�н��������ϵ����Ա���г�ֵ"); 
       }
       
       
       
       system("color 4A");   
                           
        
        
             
        
        
        system("pause");         
    
    
    }
}


int STAR(int *money)
{    BLACK_PURPLE;
     puts("---------------------------------------------------------------------------------------------"); 
     puts("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
     puts("-----------------------------------�����Զ���-------------------------------------------------");
     puts("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
     puts("----------------------------------------------------------------------------------------------"); 
     //�˺��������� 
     char id[]="sunjiank99";char password[]="5223280123";
     //�û�������
     char inputid[20];char inputpassword[20]; 
      GREEN_BLACK;
    T: puts("��ѡ���ܣ�1-���  2-����Ա");
     
     int gongneng;
     scanf("%d",&gongneng);
     fflush(stdin);
     
     if(gongneng==1)
     { 
     
     GRAY_BLACK;
     puts("����������˺ţ�");
     b:gets(inputid);
     
     if(strcmp(inputid,id)==0)
     {     DYELLOW_BLACK;
           puts("���������룺");
           
        a:   gets(inputpassword);
           
           if(strcmp(inputpassword,password)==0)
           
           return 0;
           
           else
           
           puts("��������������������");
           
           goto a ; 
     }
     else
     {    puts("û������˺ţ���������Ч�˺�");
     
          goto b;
     }
     }
     else
     {   CYAN_BLACK;
         P:puts("���������Ա����");
         fflush(stdin);
         char a[20];
         gets(a);
         if(strcmp(a,"123456")==0)
         
         {puts("��������Ҫ��ֵ�Ľ��������\n");
          int tt;*money;
         scanf("%d",&tt);
         *money=tt;
         goto T;
         }
         else 
         { puts("�������");
           goto  P;
         } 
     } 
            
                                  
                                  
         
          
     }
     
      
      
     
     
     
     
     
     
