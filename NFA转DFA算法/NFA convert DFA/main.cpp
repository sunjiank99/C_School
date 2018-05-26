using namespace std;
#include<fstream>
#include<iostream>
#include<cstring>
#include<string>



char readcache[512];//文件读取缓冲区
char ch;
char taken[15];//读取单个单词

struct state
{
	char name;
	string stateinfo;
};

int main()
{   
	//读取输入文件
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
	int readRowEnd = 0; //第一行读没读完
	while (ch!=NULL)
	{
		ch = readcache[p];
		if (ch == '}'&&readRowEnd!=1)
		{
			inputColumnNum++; //列数加1
		}
		if (ch == '\n'&&readcache[p+1]!='\r')
		{
			
			inputRowNum++;//行数加1
			readRowEnd = 1;

		}
		p++;
	}

	inputColumnNum++;

	string **stateTrueList=new string*[inputRowNum];//
	//申请读入数据内存
	for (int i = 0; i < inputRowNum; i++)
	{   
		stateTrueList[i] = new string[inputColumnNum];
	}

	//读取装入数据
	int m = 0;
	p = 0;
	ch = readcache[p];
	int TrueListi = 0;
	int TrueListj = 0;//读取时候stateTrueList的行列
	while (ch != NULL)
	{
		
		
		if (ch != ' '&&ch != '\r'&&ch != '\n')
		{  
			for (int n = 0; n < 15; n++)
			{
				taken[n] = NULL;
			}

			m = 0;
			while (ch != ' '&&ch != '\r'&&ch != '\n')//识别单词转入token
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

				TrueListi++;//行数加1
				TrueListj = 0;

			}
			ch = readcache[p++];
		}

		

	}

	//求子状态的个数
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
			
			if (ch != ','&&ch != '{'&&ch != '}')//找到子字符
			{    

				//在stateTrueList表中查找下一个状态
				for (int k = 0; k < inputRowNum; k++)
				{  
					if (stateTrueList[k][0][0] == ch) //找到对应状态行
					{
						string statecache = "{";  //存放搜索到新的状态 缓存
						for (int j = 1; j < inputColumnNum; j++)
						{    
							
								int stateptr = 0;//stateTrueList子状态搜索指针
								char statech;

								statech = stateTrueList[k][j][stateptr];

								while (statech != NULL)
								{

									if (statech != ','&& statech != '{'&& statech != '}')//找到子字符
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
							   //判断状态是否已经在state数组中是否存在
							   for (int ii = 0; ii < sonStateNum; ii++)
							   {
								   if (statecache == state[ii].stateinfo)
								   {
									   certained = 1;
									   break;
								   }
							   }
							   if (certained != 1) //sertain!=1说明搜索出来了新的状态
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



	//搜索形成各个子状态

	
	 

	

	system("pause");




}