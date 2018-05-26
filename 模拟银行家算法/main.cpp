using namespace std;

#include "stdio.h"
#define MAXPROCESS 50		//最大进程数
#define MAXRESOURCE 100		//最大资源数

int available[MAXRESOURCE];					//可用资源数组
int max[MAXPROCESS][MAXRESOURCE];			//最大需求矩阵
int allocation[MAXPROCESS][MAXRESOURCE];	//分配矩阵
int need[MAXPROCESS][MAXRESOURCE];			//需求矩阵

int request[MAXPROCESS][MAXRESOURCE];		//进程需要资源数
int finish[MAXPROCESS];						//系统是否有足够的资源分配给该进程

int p[MAXPROCESS];							//记录序列
int flagp=0;
int Safeflag=0;
int m,n;									//m个进程,n个资源


void Init();
int Safe();
void Bank();
void Init2();
int SafeTest();
int SafeAl(int m,int n,int i);


int Factorial(int m)
{
    int returnVal=1;
    if(m==0)
    {
        return 1;
    }
    else
    {


    for(int i=m;i>=1;i--)
    {
        returnVal=returnVal*i;

    }


    }

    return returnVal;
}

int main()
{     Init();
      //Init2();
      SafeTest();
      //Init();
      //Init();
      //Bank();
      return 0;
}

void Init()                  //初始化算法
{
      int i,j;
	  printf("请输入进程的数目:");
	  scanf("%d",&m);
	  printf("请输入资源的种类:");
	  scanf("%d",&n);
	  printf("请输入每个进程最多所需的各资源数,按照 %d x %d 矩阵输入\n", m, n);
      for(i=0;i<m;i++)
		  for(j=0;j<n;j++)
			  scanf("%d", &max[i][j]);

	  printf("请输入每个进程已分配的各资源数,也按照 %d x %d 矩阵输入\n", m, n);

      for(i=0;i<m;i++)
      {
          for(j=0;j<n;j++)
          {
			  scanf("%d", &allocation[i][j]);
              need[i][j]=max[i][j]-allocation[i][j];
              if(need[i][j]<0)
              {
				  printf("您输入的第 %d 个进程所拥有的第 %d 个资源数错误,请重新输入:\n", i+1, j+1);
                  j--;
                  continue;
              }
          }
      }
	  printf("请输入各个资源现有的数目:\n");

      for(i=0;i<n;i++)
      {
		  scanf("%d", &available[i]);
      }


      Bank();
}

void Init2()                  //初始化算法
{

	  m=5;
	  n=3;

	  max[0][0]=7;max[0][1]=5;max[0][2]=3;
	  max[1][0]=3;max[1][1]=2;max[1][2]=2;
      max[2][0]=9;max[2][1]=0;max[2][2]=2;
      max[3][0]=2;max[3][1]=2;max[3][2]=2;
      max[4][0]=4;max[4][1]=3;max[4][2]=3;


	  printf("请输入每个进程已分配的各资源数,也按照 %d x %d 矩阵输入\n", m, n);

      allocation[0][0]=0;allocation[0][1]=1;allocation[0][2]=0;
	  allocation[1][0]=2;allocation[1][1]=0;allocation[1][2]=0;
      allocation[2][0]=1;allocation[2][1]=0;allocation[2][2]=2;
      allocation[3][0]=2;allocation[3][1]=1;allocation[3][2]=1;
      allocation[4][0]=0;allocation[4][1]=0;allocation[4][2]=2;

        for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {

              need[i][j]=max[i][j]-allocation[i][j];
              if(need[i][j]<0)
              {
				  printf("您输入的第 %d 个进程所拥有的第 %d 个资源数错误,请重新输入:\n", i+1, j+1);
                  j--;
                  continue;
              }
          }
      }

	  printf("请输入各个资源现有的数目:\n");

     available[0]=3;available[1]=3;available[2]=2;



}

void Bank()                  //银行家算法
{
        int flagNeed=0;
        int flagAvailable=0;

        int Sourceflag=0;


      puts("请输入资源号码");
      scanf("%d",&Sourceflag);
      printf("请输入%d号资源的Request矩阵 长度%d",Sourceflag,n);

      for(int i=0;i<n;i++)
      {
          scanf("%d",&request[Sourceflag][i]);
      }

                for(int i=0;i<n;i++)
            {

                if(request[Sourceflag][i]>need[Sourceflag][i])
                {
                        flagNeed=0;
                        break;
                }
                else
                {
                    flagNeed=1;
                }

            }

            if(flagNeed)
            {
                  for(int i=0;i<n;i++)
                {

                if(request[Sourceflag][i]>available[i])
                {
                        flagAvailable=0;
                        break;
                }
                else
                {
                    flagAvailable=1;
                }

                }


                if(flagAvailable)
                {
                      for(int i=0;i<n;i++)
                      {
                          available[i]=available[i]-request[Sourceflag][i];
                          allocation[Sourceflag][i]=allocation[Sourceflag][i]+request[Sourceflag][i];
                          need[Sourceflag][i]=need[Sourceflag][i]-request[Sourceflag][i];
                      }
                      SafeTest();
                }
                else
                {
                    printf("尚无足够资源  P%d必须等待",Sourceflag);
                }
            }
            else
            {
                puts("出错，所需资源超过最大值");
            }
}





int Safe()                                      //安全性算法
{   int flagSafe=0;
    int flagp=0;
    int Factorialval=Factorial(m);
    //初始化安全标志
    for(int i=0;i<m;i++)
    {
        finish[i]=0;  //0为false
    }

    for(int i=0;i<Factorialval;i++)
    {
        //flagSafe 取值
        for(int i=0;i<m;i++)
        {
            if(finish[i]==0)
            {
                 flagSafe=0;
                 break;
            }
            else
            {
                flagSafe=1;

            }
        }
        //如果安全则推出循环
        if(flagSafe)
        {
            break;
        }



        for(int i=0;i<m;i++)
        {
            int allFully=0;

            //如果进程安全标志为false
            if(!finish[i])
            {
                  //查看available是否满足need 资源
                  for(int j=0;j<n;j++)
                    {
                        if(need[i][j]>available[j])
                        {
                            allFully=0;
                            break;
                        }
                        else
                        {
                            allFully=1;

                        }
                    }

                    //如果available可以满足need  资源
                    if(allFully==1)
                    {   //运行并释放资源
                        for(int j=0;j<n;j++)
                        {
                            available[j]=available[j]+allocation[i][j];
                        }

                        finish[i]=1;

                        p[flagp]=i; //记录安全序列
                        flagp++;


                    }


            }
        }
    }



    if(flagSafe)
    {
        printf("安全\n 安全序列为：");
        for(int i=0;i<flagp;i++)
        {
            printf("%d",p[i]);
        }
    }
    else
        {
           printf("不安全");
        }
   return 0;
}


int SafeTest()
{
    Safeflag=0;
    for(int i=0;i<m;i++)
    {
        finish[i]=0;  //0为false
    }


    SafeAl(m,n,0);


    if(Safeflag)
    {
        puts("安全");
        puts("安全序列为");
        for( int i=0;i<m;i++)
        {
            printf("%d",p[i]);
        }
    }
    else
    {
        puts("不安全");
    }




}

int SafeAl(int m, int n,int k)
{
  int i=k;
   for(int i=0;i<m;i++)
    {
        if(finish[i])
        {
            Safeflag=1;
        }
        else
        {
            Safeflag=0;
            break;
        }
    }

    if(Safeflag)
    {
        return 0;
    }
    else
    {




  if(i<m)
  {


    if(finish[i]==0)
    {

                  int allFully=0;
    //查看available是否满足need 资源

                  for(int j=0;j<n;j++)
                    {
                        if(need[i][j]>available[j])
                        {
                            allFully=0;
                            break;
                        }
                        else
                        {
                            allFully=1;

                        }
                    }
                    //如果available满足need
                 if(allFully)
                 {
                     for(int j=0;j<n;j++)
                     {   //释放资源
                         available[j]=available[j]+allocation[i][j];

                     }

                     finish[i]=1;
                     p[flagp]=i;
                     flagp++;
                     SafeAl(m,n,0);

                 }
                 else
                 {
                     SafeAl(m,n,i+1);
                 }

    }
    else
        {
                  SafeAl(m,n,i+1);

        }


  }else
  {
      return 0;
  }
    }


    return 0;

}
