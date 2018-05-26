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
        puts("游戏开始");
        struct car
        {  char name[20];
           int number;
           int beilv;
        } ;
        struct car inf[8];
        //下面给每个写入押注汽车品牌信息 
        int i;
        for(i=1;i<=7;i++)
        {inf[i].number=i;
        }
        //车名 
        strcpy(inf[1].name,"大众");
        strcpy(inf[2].name,"宝马");
        strcpy(inf[3].name,"三菱");
        strcpy(inf[4].name,"现代");
        strcpy(inf[5].name,"东风");
        strcpy(inf[6].name,"本田");
        strcpy(inf[7].name,"红旗");
        //倍率
        inf[1].beilv=1;
        inf[2].beilv=7;
        inf[3].beilv=3;
        inf[4].beilv=20;
        inf[5].beilv=100;
        inf[6].beilv=10;
        inf[7].beilv=5;
        
        //游戏开始
        //提示用户信息 
        
        int money=0;
        money=*addmoney; //金币 
         PURPLE_BLACK;
        printf("号码：");
        for(i=1;i<=7;i++)
        {printf("%5d  ",inf[i].number);
        }
        puts(""); 
        printf("品牌："); 
        for(i=1;i<=7;i++)
        {   
           printf("%5s  ",inf[i].name); 
        }
        puts("");
         printf("倍率：");
        for(i=1;i<=7;i++)
        {   
           printf("%5d  ",inf[i].beilv);              
        }
        puts("");
       A: printf("您现在的金币为%d",money); 
         
       //开始押注
       puts("请选择你要押注的车牌号码按回车开始"); 
       int haoma,suijihaoma;
       
       scanf("%d",&haoma);
       //随机数设定 
       srand((unsigned)time(NULL));
       
       suijihaoma=rand()%8;
       
       //出奖 
       
       if(haoma==suijihaoma)
       
       { RED_BLACK;
         printf("此次开奖车牌为%s 您获得的金币为%d\n",inf[suijihaoma].name,inf[suijihaoma].beilv);
         money=money+inf[suijihaoma].beilv;
         }                   
       else
       { 
         
         DGREEN_BLACK;
         if(suijihaoma!=0)
         {printf("此次开奖车牌为%s 您没有中奖，赔了金币%d\n",inf[suijihaoma].name,inf[haoma].beilv);}
         else
         {printf("此次没有任何开奖车牌开奖，再接再厉！\n");}
                                  
         money=money-inf[haoma].beilv;
       }
       if(money>0)
       {
       goto A;    
       }
       else
       { printf("您的金币不足\n");
         printf("\n\n\n你没有金币了请联系管理员进行充值"); 
       }
       
       
       
       system("color 4A");   
                           
        
        
             
        
        
        system("pause");         
    
    
    }
}


int STAR(int *money)
{    BLACK_PURPLE;
     puts("---------------------------------------------------------------------------------------------"); 
     puts("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
     puts("-----------------------------------汽车对对碰-------------------------------------------------");
     puts("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
     puts("----------------------------------------------------------------------------------------------"); 
     //账号密码存放区 
     char id[]="sunjiank99";char password[]="5223280123";
     //用户输入区
     char inputid[20];char inputpassword[20]; 
      GREEN_BLACK;
    T: puts("请选择功能：1-玩家  2-管理员");
     
     int gongneng;
     scanf("%d",&gongneng);
     fflush(stdin);
     
     if(gongneng==1)
     { 
     
     GRAY_BLACK;
     puts("请输入玩家账号：");
     b:gets(inputid);
     
     if(strcmp(inputid,id)==0)
     {     DYELLOW_BLACK;
           puts("请输入密码：");
           
        a:   gets(inputpassword);
           
           if(strcmp(inputpassword,password)==0)
           
           return 0;
           
           else
           
           puts("密码错误，请从新输入密码");
           
           goto a ; 
     }
     else
     {    puts("没有这个账号，请输入有效账号");
     
          goto b;
     }
     }
     else
     {   CYAN_BLACK;
         P:puts("请输入管理员密码");
         fflush(stdin);
         char a[20];
         gets(a);
         if(strcmp(a,"123456")==0)
         
         {puts("请输入你要充值的金币数量：\n");
          int tt;*money;
         scanf("%d",&tt);
         *money=tt;
         goto T;
         }
         else 
         { puts("密码错误");
           goto  P;
         } 
     } 
            
                                  
                                  
         
          
     }
     
      
      
     
     
     
     
     
     
