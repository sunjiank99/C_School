
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

/***********************�궨��**********************/
#define PI 3.1415926										//Բ����
#define WIDTH 1000											//��Ļ��ȣ����ǳ�������
#define HEIGHT 800											//��Ļ�߶ȣ����ǳ�������
#define V 20												//�����ٶȣ������ƶ���������
#define LENGTH	20											//�����ַ���
#define DELAY 30											//��ʱ
#define NUM 45												//���Ǹ���


/******************�������ǽṹ��*******************/
struct meteor
{
	int x0;
	int y0;
	int yh;
	char str[LENGTH];
}me[NUM] = {0};

/*********************��������**********************/
char AsciiRand();
void Move(char *p);
void InitMeteor(struct meteor *me);
int color(int y, int y0, int yh);
void Meteors(struct meteor me[]);

/***********************������**********************/
int main(void)
{
	//���ռ�������ı���
	char c = '\0';

	//��ʼ�� WIDTH * HEIGHT�Ļ�ͼ����
	initgraph(WIDTH, HEIGHT);

	//��ô��ھ��
	HWND hwnd = GetHWnd();

	//�޸Ĵ�������
	SetWindowText(hwnd, "�ڿ͵۹�����������");

	//�����ʾ����
	ShowWindow (hwnd, SW_SHOWMAXIMIZED);

	//������ʾ
	MessageBox(hwnd, TEXT("�����ȷ������ʼ��ʾ������Ч����Esc���˳�"), TEXT("��ʾ"), MB_OK | MB_ICONWARNING);

	//�����������
	srand((unsigned)time(NULL));

	//��NUM���������ʼ��
	for(int i = 0; i < NUM; i++)
	{
		InitMeteor(&me[i]);
	}

	while(c != 27)
	{
		//��ʼ������ͼ
		BeginBatchDraw();

		//����һ֡����
		Meteors(me);
		
		//ִ��δ��ɵĻ�������
		FlushBatchDraw();

		//��ʱ
		Sleep(DELAY); 

		//����
		cleardevice();

		for(int i = 0; i < NUM; i++)
		{
			//���������ƶ�һ����V�����أ�
			me[i].yh += V;
			Move(me[i].str);

			//��ĳ��������ȫ�߳����棬���ʼ��
			if(me[i].yh > HEIGHT + LENGTH * V)
			{
				InitMeteor(&me[i]);
			}
		}

		//���Esc�������˳�
		if(kbhit())
		{
			c = getch();
		}
	}

	//����������ͼ
	EndBatchDraw();
	
	//��Դ�������ص�ַ
	system("start http://code.google.com/p/c-programming-language/downloads/list"); 

	//������ͼ����
	closegraph();
	return 0;
}

/***********************������**********************/

//��������ɼ�ASCII��
char AsciiRand()
{
	return ((char)(rand() % (126 -33) + 33));
}

//�ַ����ƣ�����ʹ��ʾʱ�ַ������Ļλ�ò���
void Move(char *p)
{
	char *pt = p + LENGTH;
	while(pt > p) 
	{
		*(--pt) = *(pt - 1);	
	}
	*p = AsciiRand(); 
}

//��һ�����ǳ�ʼ��
void InitMeteor(struct meteor *me)
{
	me->x0 = rand() % WIDTH;
	me->yh = me->y0 = rand() % HEIGHT;

	for(int i = 0; i < LENGTH; i++)
	{
		*(me->str + i) = AsciiRand();	
	}
}

//ȷ�����ǵ���ɫ
int color(int y, int y0, int yh)
{
	int color;

	//������֮ǰ���������óɺ�ɫ
	if(y < y0)
	{
		color = 0;
	}

	//������ɫ��ͷ��β�������Һ����ݼ�
	else
	{	
		//β����ʧ
		color = (int)(255* cos((yh - y) * PI / ( 2 * LENGTH * V)));

		//β������ʧ
		//color = 255;
	}
	return color;
}


//��ӡһ֡���ǵĻ���
void Meteors(struct meteor me[])
{
	//���ø�ʽ������͸�����ַ��߶ȣ������ϸ������
	setbkmode(TRANSPARENT);
	setfont(12, 12, "����");

	//��ʼ��ӡһ֡ͼ��
	int y;
	for(int n = 0; n < NUM; n++)
	{
		for(int j = 0; j < LENGTH; j++)
		{
			//�����е�j���ַ���������
			y = me[n].yh - j * V;

			//������ɫ�����ǵ�ͷ���ǰ�ɫ��
			setcolor(RGB(255 * (0 == j), color(y, me[n].y0, me[n].yh), 255 * (0 == j)));
		
			//��ӡ�ַ�
			outtextxy(me[n].x0, y, me[n].str[j]);
		}		
	}
}

