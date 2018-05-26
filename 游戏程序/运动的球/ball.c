/////////////////////////////////////////////////////////////////////// 
//�������ƣ�printf()���������˶����� 
//���뻷����Visual C++ 6.0��Easyx��  
//�����д��Geodesic 
//�����£�2012-05-07
///////////////////////////////////////////////////////////////////////// 
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

//������ʱʱ�䣬�˶����Ŀ�Ⱥ͸߶�
#define DELAY 100
#define WIDTH 80
#define HEIGHT 24

//����ȫ�ֱ�����λ�ú��ٶ�
int X = 0, Y =0;
int Vx = 1, Vy = 1;

//��������
void Ball();
void HideCursor();
void GotoXy(int x, int y);

//������
int main(void)
{
	//���ռ������ݵı���
	char ch = '\0';

	//�޸Ĵ�������
	system("title printf()���������˶�����");

	//���ع��
	HideCursor();


	//��ͼ��ESC�˳�
	while(ch != 27){
		Ball();
		if(kbhit())
			ch = getch();
	}

	//��������
	system("cls");
	printf("�����������\n");
	Sleep(1000);
	system("start http://code.google.com/p/c-programming-language/downloads/list"); 
	
	return 0;
}


//������Ĺ켣
void Ball()
{
	//����
	GotoXy(X, Y);
	printf("��");

	//��ʱ
	Sleep(DELAY);
	
	//����
	GotoXy(X, Y);
	printf("  ");

	//���練��
	if((WIDTH - 2) == X && Vx > 0 || 0 == X && Vx < 0)
		Vx *= -1;
	if((HEIGHT - 1) == Y && Vy > 0 || 0 == Y && Vy < 0)
		Vy *= -1;

	//������һ�����ڵ�λ��
	X += 2 * Vx;
	Y += Vy;
}


//���ع�꣬ͷ�ļ�<windows.h>
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};	//��ߵ�0�����겻�ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//����ƶ���ͷ�ļ�<windows.h>
void GotoXy(int x, int y)
{
	HANDLE hout;	//����������hout
	COORD coord;	//����ṹ��coord
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);		//��ñ�׼�������Ļ�����
	SetConsoleCursorPosition(hout, coord);		//�ƶ����
}

