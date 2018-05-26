#include<stdio.h>
#include"color.h"

struct playerinf
{
         char name[5];
         double score;

};
struct playerinf p;
void gotoxy(int x,int y)    //???????
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(hOut,pos);
}

void scoreoutput(double x,double y)
{
      gotoxy(x,y);
      RED_BLUE;
      printf("亲爱的          %s",p.name);
      gotoxy(x,y+1);
      printf("您的总分:       %lf.0分",p.score);
      gotoxy(x,y+5);
      prinf("按任意键退出");
      BLACK_WHITE;
      return ;
}

main()
{
      input(5,5);



}

