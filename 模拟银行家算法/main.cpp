using namespace std;

#include "stdio.h"
#define MAXPROCESS 50		//��������
#define MAXRESOURCE 100		//�����Դ��

int available[MAXRESOURCE];					//������Դ����
int max[MAXPROCESS][MAXRESOURCE];			//����������
int allocation[MAXPROCESS][MAXRESOURCE];	//�������
int need[MAXPROCESS][MAXRESOURCE];			//�������

int request[MAXPROCESS][MAXRESOURCE];		//������Ҫ��Դ��
int finish[MAXPROCESS];						//ϵͳ�Ƿ����㹻����Դ������ý���

int p[MAXPROCESS];							//��¼����
int flagp=0;
int Safeflag=0;
int m,n;									//m������,n����Դ


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

void Init()                  //��ʼ���㷨
{
      int i,j;
	  printf("��������̵���Ŀ:");
	  scanf("%d",&m);
	  printf("��������Դ������:");
	  scanf("%d",&n);
	  printf("������ÿ�������������ĸ���Դ��,���� %d x %d ��������\n", m, n);
      for(i=0;i<m;i++)
		  for(j=0;j<n;j++)
			  scanf("%d", &max[i][j]);

	  printf("������ÿ�������ѷ���ĸ���Դ��,Ҳ���� %d x %d ��������\n", m, n);

      for(i=0;i<m;i++)
      {
          for(j=0;j<n;j++)
          {
			  scanf("%d", &allocation[i][j]);
              need[i][j]=max[i][j]-allocation[i][j];
              if(need[i][j]<0)
              {
				  printf("������ĵ� %d ��������ӵ�еĵ� %d ����Դ������,����������:\n", i+1, j+1);
                  j--;
                  continue;
              }
          }
      }
	  printf("�����������Դ���е���Ŀ:\n");

      for(i=0;i<n;i++)
      {
		  scanf("%d", &available[i]);
      }


      Bank();
}

void Init2()                  //��ʼ���㷨
{

	  m=5;
	  n=3;

	  max[0][0]=7;max[0][1]=5;max[0][2]=3;
	  max[1][0]=3;max[1][1]=2;max[1][2]=2;
      max[2][0]=9;max[2][1]=0;max[2][2]=2;
      max[3][0]=2;max[3][1]=2;max[3][2]=2;
      max[4][0]=4;max[4][1]=3;max[4][2]=3;


	  printf("������ÿ�������ѷ���ĸ���Դ��,Ҳ���� %d x %d ��������\n", m, n);

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
				  printf("������ĵ� %d ��������ӵ�еĵ� %d ����Դ������,����������:\n", i+1, j+1);
                  j--;
                  continue;
              }
          }
      }

	  printf("�����������Դ���е���Ŀ:\n");

     available[0]=3;available[1]=3;available[2]=2;



}

void Bank()                  //���м��㷨
{
        int flagNeed=0;
        int flagAvailable=0;

        int Sourceflag=0;


      puts("��������Դ����");
      scanf("%d",&Sourceflag);
      printf("������%d����Դ��Request���� ����%d",Sourceflag,n);

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
                    printf("�����㹻��Դ  P%d����ȴ�",Sourceflag);
                }
            }
            else
            {
                puts("����������Դ�������ֵ");
            }
}





int Safe()                                      //��ȫ���㷨
{   int flagSafe=0;
    int flagp=0;
    int Factorialval=Factorial(m);
    //��ʼ����ȫ��־
    for(int i=0;i<m;i++)
    {
        finish[i]=0;  //0Ϊfalse
    }

    for(int i=0;i<Factorialval;i++)
    {
        //flagSafe ȡֵ
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
        //�����ȫ���Ƴ�ѭ��
        if(flagSafe)
        {
            break;
        }



        for(int i=0;i<m;i++)
        {
            int allFully=0;

            //������̰�ȫ��־Ϊfalse
            if(!finish[i])
            {
                  //�鿴available�Ƿ�����need ��Դ
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

                    //���available��������need  ��Դ
                    if(allFully==1)
                    {   //���в��ͷ���Դ
                        for(int j=0;j<n;j++)
                        {
                            available[j]=available[j]+allocation[i][j];
                        }

                        finish[i]=1;

                        p[flagp]=i; //��¼��ȫ����
                        flagp++;


                    }


            }
        }
    }



    if(flagSafe)
    {
        printf("��ȫ\n ��ȫ����Ϊ��");
        for(int i=0;i<flagp;i++)
        {
            printf("%d",p[i]);
        }
    }
    else
        {
           printf("����ȫ");
        }
   return 0;
}


int SafeTest()
{
    Safeflag=0;
    for(int i=0;i<m;i++)
    {
        finish[i]=0;  //0Ϊfalse
    }


    SafeAl(m,n,0);


    if(Safeflag)
    {
        puts("��ȫ");
        puts("��ȫ����Ϊ");
        for( int i=0;i<m;i++)
        {
            printf("%d",p[i]);
        }
    }
    else
    {
        puts("����ȫ");
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
    //�鿴available�Ƿ�����need ��Դ

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
                    //���available����need
                 if(allFully)
                 {
                     for(int j=0;j<n;j++)
                     {   //�ͷ���Դ
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
