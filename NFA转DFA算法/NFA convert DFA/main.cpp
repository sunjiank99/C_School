using namespace std;
#include<fstream>
#include<iostream>
#include<cstring>
#include<string>



char readcache[512];//�ļ���ȡ������
char ch;
char taken[15];//��ȡ��������

struct state
{
	char name;
	string stateinfo;
};

int main()
{   
	//��ȡ�����ļ�
	FILE *fp;
	fp = fopen("test.txt", "rb+");

	char str[8];
	while (fgets(str, 8, fp))
	{
		strcat(readcache, str);
		

	}
	fclose(fp);

	
	
	int p = 0;
	ch = readcache[p];

	int inputColumnNum=0;
	int inputRowNum=0;
	int readRowEnd = 0; //��һ�ж�û����
	while (ch!=NULL)
	{
		ch = readcache[p];
		if (ch == '}'&&readRowEnd!=1)
		{
			inputColumnNum++; //������1
		}
		if (ch == '\n'&&readcache[p+1]!='\r')
		{
			
			inputRowNum++;//������1
			readRowEnd = 1;

		}
		p++;
	}

	inputColumnNum++;

	string **stateTrueList=new string*[inputRowNum];//
	//������������ڴ�
	for (int i = 0; i < inputRowNum; i++)
	{   
		stateTrueList[i] = new string[inputColumnNum];
	}

	//��ȡװ������
	int m = 0;
	p = 0;
	ch = readcache[p];
	int TrueListi = 0;
	int TrueListj = 0;//��ȡʱ��stateTrueList������
	while (ch != NULL)
	{
		
		
		if (ch != ' '&&ch != '\r'&&ch != '\n')
		{  
			for (int n = 0; n < 15; n++)
			{
				taken[n] = NULL;
			}

			m = 0;
			while (ch != ' '&&ch != '\r'&&ch != '\n')//ʶ�𵥴�ת��token
			{
				taken[m++] = ch;
				
				if (p == 0)
				{
					p++;
					ch = readcache[p];
				}
				else
				{

					ch = readcache[p++];
				}
			}
			taken[m++] = '\0';
			stateTrueList[TrueListi][TrueListj] = taken;
			//cout << stateTrueList[TrueListi][TrueListj] << endl;
			TrueListj++;
			
		}
		else
		{
			if (ch == '\n'&&readcache[p] != '\r')
			{

				TrueListi++;//������1
				TrueListj = 0;

			}
			ch = readcache[p++];
		}

		

	}

	//����״̬�ĸ���
	int sonStateNum = 0;
	state state[10];
	state[0].name = 'A';
	 state[0].stateinfo = stateTrueList[0][0];
	sonStateNum++;

	//char *str;

	for (int i=0; i < sonStateNum;i++)
	{   
		p = 0;
		ch = state[i].stateinfo[p];
		while (ch != NULL)
		{
			
			if (ch != ','&&ch != '{'&&ch != '}')//�ҵ����ַ�
			{    

				//��stateTrueList���в�����һ��״̬
				for (int k = 0; k < inputRowNum; k++)
				{  
					if (stateTrueList[k][0][0] == ch) //�ҵ���Ӧ״̬��
					{
						string statecache = "{";  //����������µ�״̬ ����
						for (int j = 1; j < inputColumnNum; j++)
						{    
							
								int stateptr = 0;//stateTrueList��״̬����ָ��
								char statech;

								statech = stateTrueList[k][j][stateptr];

								while (statech != NULL)
								{

									if (statech != ','&& statech != '{'&& statech != '}')//�ҵ����ַ�
									{
										if (stateTrueList[k][j][stateptr + 1] != '}')
										{


											char ss[2];
											ss[0] = statech;
											ss[1] = '\0';
											statecache.append(ss);
											statecache.append(",");
										}
										else if (state[i].stateinfo[p + 1] == '}')
										{


											char ss[2];
											ss[0] = statech;
											ss[1] = '\0';
											statecache.append(ss);
											statecache.append("}");

										}


									}

									stateptr++;
									statech = stateTrueList[k][j][stateptr];

								}
						

							   int certained = 0;
							   //�ж�״̬�Ƿ��Ѿ���state�������Ƿ����
							   for (int ii = 0; ii < sonStateNum; ii++)
							   {
								   if (statecache == state[ii].stateinfo)
								   {
									   certained = 1;
									   break;
								   }
							   }
							   if (certained != 1) //sertain!=1˵�������������µ�״̬
							   {
								   sonStateNum++;
								   int ascall = state[sonStateNum - 2].name;
								   state[sonStateNum-1].name = ascall + 1;
								   state[sonStateNum-1].stateinfo = statecache;

							   }


						}
					}
				}

			}

			p++;
			ch = state[i].stateinfo[p];
		}
	
	}



	//�����γɸ�����״̬

	
	 

	

	system("pause");




}