#include<stdio.h>
#include<windows.h>
#include"color.h"
#define X 8
#define Y 20
#include<time.h>
#pragma comment(lib, "WINMM.LIB")

struct playerinf
{
         char name[5];
         double score;

};
struct playerinf p;


void lie(int x)
{
     int j = 0;
     for(j;j<x;j++)
        printf("\n");
}
void hang(int y)
{
     int i = 0;
     for(i;i<y;i++)
        printf(" ");
}
CHOOSE(int n,char *MENU[4])//���ѡ��˵��ĺ���
{
   int j,i;
   lie(X);
   hang(Y);
   BLACK_GREEN;printf("-------------------------------\n");BLACK_WHITE;

   for(j=0;j<4;j++)
   {
      if(j==n)
      {
         hang(Y);
         BLACK_GREEN;printf("|  ");BLACK_WHITE;
         BLACK_GREEN;printf("        %s  %c",MENU[j],4);BLACK_WHITE;
         BLACK_GREEN;printf("        |\n");BLACK_WHITE;
      }
      else
      {
          hang(Y);
          BLACK_GREEN;printf("|  ");BLACK_WHITE;
          BLACK_RED;printf("        %s   ",MENU[j]);BLACK_WHITE;
          BLACK_GREEN;printf("        |\n");BLACK_WHITE;
      }
   }
   hang(Y);
   BLACK_GREEN;printf("|");BLACK_WHITE;
   printf("�����ƶ�(w)�����ƶ�(s)ѡ��(j)");
   BLACK_GREEN;printf("|\n");BLACK_WHITE;
   hang(Y);
   BLACK_GREEN;printf("-------------------------------\n");BLACK_WHITE;
}
DWORD WINAPI ThreadProc1( LPVOID lpParam )   //�߳�1 ��������
{



     system("bjmusic.exe");

}
DWORD WINAPI ThreadProc2( LPVOID lpParam )    //�߳�2 ������������
{
  system("fadong.exe");

}
DWORD WINAPI ThreadProc3( LPVOID lpParam )    //�߳�2 ������ײ����
{
  system("pengzhuang.exe");
}
 sizeofscreen(int x,int y)                    //��Ļ��С
{
    HWND hwnd=GetForegroundWindow();//�õ����ھ��
    SetWindowTextA(hwnd,"GAME");//���ñ���

    char setting[30];
    sprintf(setting,"mode con:cols=%d lines=%d",x,y);//���ÿ���̨��ȣ��߶�
    system(setting);
    SetWindowPos(hwnd,HWND_TOPMOST,0,0,x,y,NULL);//�ö�����

    MoveWindow(hwnd,0,0,x,y,1);//�ƶ����壬ʵ��ȫ��
}

void gotoxy(int x,int y)    //���ƹ����ƶ�
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}
void input(double x,double y)      //���������Ϣ
{
      gotoxy(x,y);
      RED_BLUE;
      printf("�������������");
      gotoxy(x,y+1);
      printf("����:");
      gets(p.name);
      BLACK_WHITE;
      return ;
}
void scoreoutput(double x,double y) //��Ϸ���������ҳɼ�
{     while(1)
      {gotoxy(x,y);
      RED_BLUE;
      printf("�װ���          %s",p.name);
      gotoxy(x,y+1);
      printf("�����ܷ�:       %lf.0��",p.score);
      gotoxy(x,y+5);
      printf("���س������˳�");
      if(GetAsyncKeyState(13))
      {
          return;
      }

      BLACK_WHITE;
      }

}
void scoreoutputStop(double x,double y) //��Ϸ   �ж�  �����ҳɼ�
{     while(1)
      {gotoxy(x,y);
      RED_BLUE;
      printf("��Ϸ��ͣ");
      gotoxy(x,y+1);
      printf("�װ���          %s",p.name);
      gotoxy(x,y+2);
      printf("����Ŀǰ���ܷ�:       %lf.0��",p.score);
      gotoxy(x,y+5);
      printf("���س���������Ϸ");
      if(GetAsyncKeyState(13))
      {
          return;
      }


      BLACK_WHITE;
      }

}
tree(double x,double y)//x�������2 y�������0 ��С 5*4
{   BLACK_WHITE;
    gotoxy( x+2, y);
    BLACK_GREEN; printf("%c",30);
    gotoxy( x+1, y+1);
     printf("%c%c%c",30,30,30);
     gotoxy( x, y+2);
     printf("%c%c%c%c%c",30,30,30,30,30);
     gotoxy( x+2, y+3);
    DYELLOW_DYELLOW; printf("%c",35);
    BLACK_WHITE;

}

wall(double x,double y)  //��СΪ4*2  ��*��
{   gotoxy(x, y);
    RED_GRAY;
    printf("%c%c%c%c%c",2,2,2,2,2);
    gotoxy(x, y+1);
    printf("%c%c%c%c%c",2,2,2,2,2);
    BLACK_WHITE;
}
room(double x,double y)  //��СΪ4*3  ��*��
{   BLACK_WHITE;
    gotoxy(x+1, y);
    BLACK_DYELLOW;
    printf("%c%c",95,95);
    gotoxy(x, y+1);
    BLACK_CYAN;
    printf("%c%c%c%c",30,30,30,30);
    gotoxy(x, y+2);
    RED_DRED;
    printf("%c",859);
    gotoxy(x+1, y+2);
    printf("%c%c",863,863);
    gotoxy(x+3, y+2);
    printf("%c",861);
    BLACK_WHITE;

}

car1(double x,double y)                 //7*4  ��*��
{    BLACK_YELLOW;
    gotoxy(x+3,y);
    printf("%c",798);                //��ͷ
    gotoxy(x+1,y+1);
    BLACK_GRAY;
    printf("%c",783);                //��ǰ����
    gotoxy(x+2,y+1);
    BLACK_RED;
    printf("%c%c%c",514,514,514);    //ǰ����
    gotoxy(x+5,y+1);
    BLACK_GRAY;
    printf("%c",783);                //��ǰ����
    gotoxy(x+3,y+2);
    BLACK_PURPLE;
    printf("%c",535);                //�г���
    BLACK_GRAY;
    gotoxy(x,y+3);                   //�����
     printf("%c",783);
     BLACK_RED;
     gotoxy(x+1,y+3);                //�����
     printf("%c",529);
     gotoxy(x+2,y+3);                //����
      printf("%c%c%c",514,514,514);
      gotoxy(x+5,y+3);               //�Һ���
      printf("%c",528);
      BLACK_GRAY;
      gotoxy(x+6,y+3);               //�Һ���
      printf("%c",783);
      BLACK_WHITE;
}
car2(double x,double y)                    //7*4  ��*��
{    BLACK_GREEN;
    gotoxy(x+3,y);
    printf("%c",798);                //��ͷ
    gotoxy(x+1,y+1);
    BLACK_BLUE;
    printf("%c",783);                //��ǰ����
    gotoxy(x+2,y+1);
    BLACK_YELLOW;
    printf("%c%c%c",514,514,514);    //ǰ����
    gotoxy(x+5,y+1);
    BLACK_BLUE;;
    printf("%c",783);                //��ǰ����
    gotoxy(x+3,y+2);
    BLACK_PURPLE;
    printf("%c",535);                //�г���
    BLACK_BLUE;;
    gotoxy(x,y+3);                   //�����
     printf("%c",783);
     BLACK_PURPLE;
     gotoxy(x+1,y+3);                //�����
     printf("%c",529);
     gotoxy(x+2,y+3);                //����
      printf("%c%c%c",514,514,514);
      gotoxy(x+5,y+3);               //�Һ���
      printf("%c",528);
      BLACK_BLUE;;
      gotoxy(x+6,y+3);               //�Һ���
      printf("%c",783);
      BLACK_WHITE;
}
carhandle(double *x,double *y) //�����ֱ�����
{
    if(GetAsyncKeyState(0x27)&&*x<=107)        //�������
           {
               *x=(*x+1);


               //PlaySound("b.wav", NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP );

           }
            if(GetAsyncKeyState(0x26)&&*y>=0)    //�������
           {
               *y=(*y-1);
              //PlaySound("fadong.wav", NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP );
           }
            if(GetAsyncKeyState(0x28)&&*y<=39)   //�������
           {
               *y=(*y+1);
                      // use default creation flags
            //PlaySound("car.wav", NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP );
           }
            if(GetAsyncKeyState(0x25)&&*x>=6)      //�������
           {
                *x=(*x-1);
                //PlaySound("car.wav", NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP );
           }
}

void hp(double x,double y,double z)
{    int i;
     for(i=0;i<z;i++)
     {
       gotoxy(x,y++);

       RED_RED;
       printf("hphp");

     }
     BLACK_WHITE;
}

void fen(double x,double y,double z)
{    gotoxy(x,y);
     printf("����");
     gotoxy(x,y+1);
     printf("%.3lf",z);
}
void xue(double x,double y,double z)
{    gotoxy(x,y);
     printf("HP");
     gotoxy(x,y+1);
     printf("%.3lf",z);
}
void shijian(double x,double y,double z)
{    gotoxy(x,y);
     printf("ʱ��");
     gotoxy(x,y+1);
     printf("%.0lfs",z);
}

cak()
{   sizeofscreen(1200,700);//������Ļ��С


    clock_t start,end;  //��ʱ����
    double t;
    double x=50,y=39;//������������
    double *px=&x,*py=&y;//�����ֱ�ָ��
    car1(x,y);//�趨������ʼλ��
    double tree1x=0,tree1y=0;      //��������
    double tree2x=0,tree2y=15;
    double tree3x=115,tree3y=0;
    double tree4x=115,tree4y=15;
    double ymax=38;//������󳤶� ����
    double speed=1;//������ʻ�ٶ�
    double hinderx,hindery;//�ϰ����������  ����
    double hinderwallx,hinderwally;//        ǽ
    double hindercarx,hindercary;
    double h=30;           // Ѫ��
    double score=0;        //����
    int flag=0;//�ж���ͣ��־


    srand((unsigned)time(NULL));
    hinderx=rand()%112+4;
    hinderwallx=rand()%112+4;   //��������ϰ���
    hindery=0;
    hinderwally=16;
    hindercary=25;
    start=clock();

    CreateThread(
            NULL,              // default security attributes
            0,                 // use default stack size
            ThreadProc1,        // thread function
            NULL,             // argument to thread function
            0,                 // use default creation flags
            NULL);
           CreateThread(
            NULL,              // default security attributes
            0,                 // use default stack size
            ThreadProc2,        // thread function
            NULL,             // argument to thread function
            0,                 // use default creation flags
            NULL);

  A:  while(1)
    {
      end=clock();

     t=(end - start)/CLOCKS_PER_SEC;
    //system("cls");
    carhandle(px,py);//�ֱ��ٿ�

         hp(125,0,h);
         fen(130,0,score);
         xue(130,5,h);
         shijian(130,10,t);

         if(tree1y>ymax)
         {
             tree1y=0;
         }
         if(tree2y>ymax)
         {
             tree2y=0;
         }
         if(tree3y>ymax)

         {
             tree3y=0;
         }
         if(tree4y>ymax)
         {
             tree4y=0;
         }
         if(hindery>ymax)
         {
             hinderx=rand()%95+4;
             hindery=0;
             score++;

         }




         if(hinderwally>ymax)
         {   hinderwallx=rand()%95+4;
            hinderwally=0;
            score++;
         }
         if(hindercary>ymax)
         {
             hindercarx=rand()%95+4;
             hindercary=0;
             score++;
         }


         if((x>=hinderx)&&(x<=hinderx+16)&&(y>=hindery)&&(y<=hindery+5))
         {
            h=h-0.5;
            CreateThread(
            NULL,              // default security attributes
            0,                 // use default stack size
            ThreadProc3,        // thread function
            NULL,             // argument to thread function
            0,                 // use default creation flags
            NULL);

         }
         if((x>=hinderwallx)&&(x<=hinderwallx+4)&&(y>=hinderwally)&&(y<=hinderwally+4))
         {
            h=h-0.1;
            CreateThread(
            NULL,              // default security attributes
            0,                 // use default stack size
            ThreadProc3,        // thread function
            NULL,             // argument to thread function
            0,                 // use default creation flags
            NULL);

         }
         if((x>=hindercarx)&&(x<=hindercarx+4)&&(y>=hindercary)&&(y<=hindercary+7))
         {
            h=h-0.1;
            CreateThread(
            NULL,              // default security attributes
            0,                 // use default stack size
            ThreadProc3,        // thread function
            NULL,             // argument to thread function
            0,                 // use default creation flags
            NULL);

         }
         if(t==30)
         {   speed=1.5;
         }
         if(t==60)
         {
             speed=2;
         }
         if(h<=0)
         {
             break;
         }


         if(GetAsyncKeyState(27)&&h>0)    //��Esc���ж���Ϸ
         {
             flag=1;
             p.score=score;

             break;

         }








         tree(tree1x,tree1y);
         tree1y=speed+tree1y;

         tree(tree2x,tree2y);
         tree2y+=speed;

         tree(tree3x,tree3y);
         tree3y+=speed;

         tree(tree4x,tree4y);
         tree4y+=speed;
         room(hinderx,hindery);
         room(hinderx+4,hindery);
         room(hinderx+8,hindery);
          room(hinderx+12,hindery);
          room(hinderx+16,hindery);

          wall(hinderwallx,hinderwally);
          car2(hindercarx,hindercary);
            hinderwally=hinderwally+speed;
            hindercary=hindercary+speed;

            hindery=hindery+speed;
         car1(x,y);


      system("cls");

    }

    if(flag==1)
    {
        scoreoutputStop(10,10);
        flag=0;
        goto A;

    }

    p.score=score;
    return ;
}

shuoming()

{   while(1)
   {


    puts("��Ϸ˵����");
    puts("������Ϸ�󣬰��ϣ������£������󣨡����ң������� ");
    puts("���������ƶ�,��Esc����Ϸ��ͣ");
    puts("��ESC�˳�");
    if(GetAsyncKeyState(27))
    {return;
    }
    system("cls");
   }
}


int main()
{
    char *MENU1[4]={"��ʼ��Ϸ","��Ϸ����","������У�δ���ţ�","�˳���Ϸ"};//����˵�
    char choose1;
    int i=0;//�����û���ѡ��Ĺ���
    CHOOSE(i,MENU1);

    for(;;)
    {
       choose1=getch();//��������ѡ��
       fflush(stdin);
       if(choose1=='j')//��ʾ�û�ѡ�����
       {
          system("cls");
          switch(i)
          {
             case 0:
                  input(10,10);
                  cak();
                  scoreoutput(10,10);
                  fflush(stdin);
                  break;
             case 1:
                  shuoming();
                  fflush(stdin);
                  break;
             case 3:
                  return 0;
          }
       }
       switch(choose1)
       {
          case 'w':
               system("cls");
               if(i==0)
               {
                  CHOOSE(i=3,MENU1);
               }
               else
               {
                  CHOOSE(i=i-1,MENU1);
               }
               break;
          case 's':
               system("cls");
               if(i==3)
               {
                  CHOOSE(i=0,MENU1);
               }
               else
               {
                   CHOOSE(i=i+1,MENU1);
               }
               break;
          default :
                  system("cls");
                  CHOOSE(i,MENU1);
                  break;
       }

    }
    system("pause");
    return 0;
}
