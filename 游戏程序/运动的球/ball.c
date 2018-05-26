/////////////////////////////////////////////////////////////////////// 
//程序名称：printf()动画——运动的球 
//编译环境：Visual C++ 6.0，Easyx库  
//程序编写：Geodesic 
//最后更新：2012-05-07
///////////////////////////////////////////////////////////////////////// 
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

//定义延时时间，运动区的宽度和高度
#define DELAY 100
#define WIDTH 80
#define HEIGHT 24

//定义全局变量，位置和速度
int X = 0, Y =0;
int Vx = 1, Vy = 1;

//函数声明
void Ball();
void HideCursor();
void GotoXy(int x, int y);

//主函数
int main(void)
{
	//接收键盘数据的变量
	char ch = '\0';

	//修改窗口名称
	system("title printf()动画——运动的球");

	//隐藏光标
	HideCursor();


	//作图，ESC退出
	while(ch != 27){
		Ball();
		if(kbhit())
			ch = getch();
	}

	//结束程序
	system("cls");
	printf("更多程序下载\n");
	Sleep(1000);
	system("start http://code.google.com/p/c-programming-language/downloads/list"); 
	
	return 0;
}


//计算球的轨迹
void Ball()
{
	//画球
	GotoXy(X, Y);
	printf("■");

	//延时
	Sleep(DELAY);
	
	//擦球
	GotoXy(X, Y);
	printf("  ");

	//触界反弹
	if((WIDTH - 2) == X && Vx > 0 || 0 == X && Vx < 0)
		Vx *= -1;
	if((HEIGHT - 1) == Y && Vy > 0 || 0 == Y && Vy < 0)
		Vy *= -1;

	//计算下一个周期的位置
	X += 2 * Vx;
	Y += Vy;
}


//隐藏光标，头文件<windows.h>
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};	//后边的0代表光标不可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//光标移动，头文件<windows.h>
void GotoXy(int x, int y)
{
	HANDLE hout;	//定义句柄变量hout
	COORD coord;	//定义结构体coord
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);		//获得标准输出（屏幕）句柄
	SetConsoleCursorPosition(hout, coord);		//移动光标
}

