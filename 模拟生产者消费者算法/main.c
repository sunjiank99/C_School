#include <windows.h>
#include <stdio.h>		//getchar()
#include <stdlib.h>		//rand()


const int SIZE_OF_BUFFER = 10;   //����������
int ProductID = 0;               //��Ʒ��
int ConsumeID = 0;               //�������ĵĲ�Ʒ��
int in = 0;                      //��Ʒ��������ʱ���±�
int out = 0;                     //��Ʒ��������ʱ���±�

int g_buffer[10];               //�������Ǹ�ѭ������,���ȵ���SIZE_OF_BUFFER

int g_continue = 1;                     //���Ƴ������


HANDLE g_hMutex;                            //�����̼߳�Ļ���
HANDLE g_hFullItems;                        //�������б�ռ�õ���
HANDLE g_hEmptyItems;                       //�������еĿ���

DWORD  WINAPI Producer(LPVOID);              //�������߳�,dword �������͵��ڴ�ռλ
DWORD  WINAPI Consumer(LPVOID);              //�������߳�


void Produce();
void Append();
void Take();
void Consume();

int main()
{
        int i;
		const int PRODUCERS_COUNT =3;       //�����ߵĸ���
		const int CONSUMERS_COUNT =2;       //�����ߵĸ���

		//�ܵ��߳���
		const int THREADS_COUNT = PRODUCERS_COUNT+CONSUMERS_COUNT;


		HANDLE *hThreads = (HANDLE*)malloc(sizeof(HANDLE)*THREADS_COUNT);		//���̵߳�handle
		DWORD *producerID = (DWORD*)malloc(sizeof(DWORD)*PRODUCERS_COUNT);		//�������̵߳ı�ʶ��
		DWORD *consumerID = (DWORD*)malloc(sizeof(DWORD)*CONSUMERS_COUNT);		//�������̵߳ı�ʶ��


        //�������������ź�
        g_hMutex = CreateMutex(NULL,FALSE,NULL);
        g_hFullItems = CreateSemaphore(NULL,0,SIZE_OF_BUFFER,NULL);//�����źŵ�,createsemaphore�������������߳�ͬ��
        g_hEmptyItems = CreateSemaphore(NULL,SIZE_OF_BUFFER, SIZE_OF_BUFFER,NULL);

		//��������ʼ��
		for (i = 0; i< SIZE_OF_BUFFER;++i)
		{
            g_buffer[i] = -1;   //��ֵΪ-1ʱ����Ϊ��
        }

        //�����������߳�
        for ( i=0;i<PRODUCERS_COUNT;++i){
            hThreads[i]
               =CreateThread(NULL,0,Producer,NULL,0,&producerID[i]);//CreateThread��window�ṩ��API����
            if (hThreads[i]==NULL) return -1;                       //�ô˺����ɴ���һ���߳�
        }
        //�����������߳�
        for (i=0;i<CONSUMERS_COUNT;++i){
            hThreads[PRODUCERS_COUNT+i] =CreateThread(NULL,0,Consumer,NULL,0,&consumerID[i]);
            if (hThreads[i]==NULL) return -1;
        }

       while(g_continue){
            if(getchar()){  //���س�����ֹ��������
                g_continue = 0;
            }
       }

        return 0;
}

//������
 DWORD  WINAPI Producer(LPVOID lpPara)
    {
        while(g_continue){
            int i=rand()%5;
            Sleep(i*1000);
               WaitForSingleObject(g_hEmptyItems,INFINITE)                               ;//�ȴ��źŵ�
               WaitForSingleObject(g_hMutex,INFINITE)                               ;
               system("cls");
            Produce();
            Append();
              ReleaseMutex(g_hMutex)                                ;
              ReleaseSemaphore(g_hFullItems,1,NULL)                                ;
       }
        return 0;
    }


     //������
    DWORD  WINAPI Consumer(LPVOID lpPara)
    {
        while(g_continue){
            int i=rand()%5;
            Sleep(i*1000);//���߳��ͷŵ�ǰ�Ŀ���Ȩ1500����,��ϵͳ���������߳�
              WaitForSingleObject(g_hFullItems,INFINITE)                                ;
               WaitForSingleObject(g_hMutex,INFINITE)                                  ;
               system("cls");
            Take();
            Consume();
            ReleaseMutex(g_hMutex)                                  ;
             ReleaseSemaphore(g_hEmptyItems,1,NULL)                                 ;
        }
        return 0;
   }

   //����һ����Ʒ����ģ����һ�£�������²�Ʒ��ID��
    void Produce()
    {
		printf("\nProducing %d ...", ++ProductID);
		printf("Succeed\n");
   }


     //���������Ĳ�Ʒ���뻺����
    void Append()
    {

			  int i;
			  printf("Appending a product ...");
      g_buffer[in] = ProductID;
      in = (in+1)%SIZE_OF_BUFFER;
	  printf("Succeed\n");


      //�����������ǰ��״̬

      for (i=0;i<SIZE_OF_BUFFER;++i)
	  {
		  printf("%d:",i);

           if (g_buffer[i]==-1)
			   printf("null");
           else
			   printf("%d",g_buffer[i]);
		     if (i==in) printf("\t<-- ����");
			 if (i==out) printf("\t<-- ����");
			 printf("\n");
        }
    }

   //�ӻ�������ȡ��һ����Ʒ
   void Take()
   {
	   int i;
	   printf("\nTaking a product ...");
       ConsumeID = g_buffer[out];
       g_buffer[out]= -1;
       out = (out+1)%SIZE_OF_BUFFER;
	   printf("%d--Succeed\n", ConsumeID);

       //�����������ǰ��״̬
       for (i=0;i<SIZE_OF_BUFFER;++i){
		   printf("%d:",i);
            if (g_buffer[i]==-1)
				 printf("null");
            else
				printf("%d",g_buffer[i]);
			if (i==in) printf("\t<-- ����");
			if (i==out) printf("\t<-- ����");
			printf("\n");

       }
    }

    //����һ����Ʒ
    void Consume()
    {
		printf("Consuming %d ", ConsumeID);
		printf("Succeed\n");
    }
