
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

/***********************宏定义**********************/
#define PI 3.1415926										//圆周率
#define WIDTH 1000											//屏幕宽度，流星出生区域
#define HEIGHT 800											//屏幕高度，流星出生区域
#define V 20												//流星速度，单次移动的像素数
#define LENGTH	20											//流星字符数
#define DELAY 30											//延时
#define NUM 45												//流星个数


/******************定义流星结构体*******************/
struct meteor
{
	int x0;
	int y0;
	int yh;
	char str[LENGTH];
}me[NUM] = {0};

/*********************函数声明**********************/
char AsciiRand();
void Move(char *p);
void InitMeteor(struct meteor *me);
int color(int y, int y0, int yh);
void Meteors(struct meteor me[]);

/***********************主函数**********************/
int main(void)
{
	//接收键盘输入的变量
	char c = '\0';

	//初始化 WIDTH * HEIGHT的绘图窗口
	initgraph(WIDTH, HEIGHT);

	//获得窗口句柄
	HWND hwnd = GetHWnd();

	//修改窗口名称
	SetWindowText(hwnd, "黑客帝国数字流星雨");

	//最大化显示窗口
	ShowWindow (hwnd, SW_SHOWMAXIMIZED);

	//弹出提示
	MessageBox(hwnd, TEXT("点击【确定】开始演示流星雨效果，Esc键退出"), TEXT("提示"), MB_OK | MB_ICONWARNING);

	//设置随机种子
	srand((unsigned)time(NULL));

	//对NUM个流星体初始化
	for(int i = 0; i < NUM; i++)
	{
		InitMeteor(&me[i]);
	}

	while(c != 27)
	{
		//开始批量绘图
		BeginBatchDraw();

		//绘制一帧动画
		Meteors(me);
		
		//执行未完成的绘制任务
		FlushBatchDraw();

		//延时
		Sleep(DELAY); 

		//清屏
		cleardevice();

		for(int i = 0; i < NUM; i++)
		{
			//流星向下移动一步（V个像素）
			me[i].yh += V;
			Move(me[i].str);

			//若某个流星完全走出画面，则初始化
			if(me[i].yh > HEIGHT + LENGTH * V)
			{
				InitMeteor(&me[i]);
			}
		}

		//如果Esc键按下退出
		if(kbhit())
		{
			c = getch();
		}
	}

	//结束批量绘图
	EndBatchDraw();
	
	//打开源程序下载地址
	system("start http://code.google.com/p/c-programming-language/downloads/list"); 

	//结束绘图环境
	closegraph();
	return 0;
}

/***********************函数体**********************/

//产生随机可见ASCII码
char AsciiRand()
{
	return ((char)(rand() % (126 -33) + 33));
}

//字符后移，可以使显示时字符相对屏幕位置不变
void Move(char *p)
{
	char *pt = p + LENGTH;
	while(pt > p) 
	{
		*(--pt) = *(pt - 1);	
	}
	*p = AsciiRand(); 
}

//对一颗流星初始化
void InitMeteor(struct meteor *me)
{
	me->x0 = rand() % WIDTH;
	me->yh = me->y0 = rand() % HEIGHT;

	for(int i = 0; i < LENGTH; i++)
	{
		*(me->str + i) = AsciiRand();	
	}
}

//确定流星的颜色
int color(int y, int y0, int yh)
{
	int color;

	//出生点之前的流星体置成黑色
	if(y < y0)
	{
		color = 0;
	}

	//流星颜色自头至尾按照余弦函数递减
	else
	{	
		//尾迹消失
		color = (int)(255* cos((yh - y) * PI / ( 2 * LENGTH * V)));

		//尾迹不消失
		//color = 255;
	}
	return color;
}


//打印一帧流星的画面
void Meteors(struct meteor me[])
{
	//设置格式：背景透明，字符高度，字体粗细，字体
	setbkmode(TRANSPARENT);
	setfont(12, 12, "宋体");

	//开始打印一帧图像
	int y;
	for(int n = 0; n < NUM; n++)
	{
		for(int j = 0; j < LENGTH; j++)
		{
			//流星中第j个字符的纵坐标
			y = me[n].yh - j * V;

			//设置颜色，流星的头部是白色的
			setcolor(RGB(255 * (0 == j), color(y, me[n].y0, me[n].yh), 255 * (0 == j)));
		
			//打印字符
			outtextxy(me[n].x0, y, me[n].str[j]);
		}		
	}
}

