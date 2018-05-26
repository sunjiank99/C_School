#include <windows.h>
#include <stdio.h>		//getchar()
#include <stdlib.h>		//rand()


const int SIZE_OF_BUFFER = 10;   //缓冲区长度
int ProductID = 0;               //产品号
int ConsumeID = 0;               //将被消耗的产品号
int in = 0;                      //产品进缓冲区时的下标
int out = 0;                     //产品出缓冲区时的下标

int g_buffer[10];               //缓冲区是个循环队列,长度等于SIZE_OF_BUFFER

int g_continue = 1;                     //控制程序结束


HANDLE g_hMutex;                            //用于线程间的互斥
HANDLE g_hFullItems;                        //缓冲区中被占用的项
HANDLE g_hEmptyItems;                       //缓冲区中的空项

DWORD  WINAPI Producer(LPVOID);              //生产者线程,dword 变量类型的内存占位
DWORD  WINAPI Consumer(LPVOID);              //消费者线程


void Produce();
void Append();
void Take();
void Consume();

int main()
{
        int i;
		const int PRODUCERS_COUNT =3;       //生产者的个数
		const int CONSUMERS_COUNT =2;       //消费者的个数

		//总的线程数
		const int THREADS_COUNT = PRODUCERS_COUNT+CONSUMERS_COUNT;


		HANDLE *hThreads = (HANDLE*)malloc(sizeof(HANDLE)*THREADS_COUNT);		//各线程的handle
		DWORD *producerID = (DWORD*)malloc(sizeof(DWORD)*PRODUCERS_COUNT);		//生产者线程的标识符
		DWORD *consumerID = (DWORD*)malloc(sizeof(DWORD)*CONSUMERS_COUNT);		//消费者线程的标识符


        //创建各个互斥信号
        g_hMutex = CreateMutex(NULL,FALSE,NULL);
        g_hFullItems = CreateSemaphore(NULL,0,SIZE_OF_BUFFER,NULL);//创建信号灯,createsemaphore常常被用作多线程同步
        g_hEmptyItems = CreateSemaphore(NULL,SIZE_OF_BUFFER, SIZE_OF_BUFFER,NULL);

		//缓冲区初始化
		for (i = 0; i< SIZE_OF_BUFFER;++i)
		{
            g_buffer[i] = -1;   //当值为-1时该项为空
        }

        //创建生产者线程
        for ( i=0;i<PRODUCERS_COUNT;++i){
            hThreads[i]
               =CreateThread(NULL,0,Producer,NULL,0,&producerID[i]);//CreateThread是window提供的API函数
            if (hThreads[i]==NULL) return -1;                       //用此函数可创建一个线程
        }
        //创建消费者线程
        for (i=0;i<CONSUMERS_COUNT;++i){
            hThreads[PRODUCERS_COUNT+i] =CreateThread(NULL,0,Consumer,NULL,0,&consumerID[i]);
            if (hThreads[i]==NULL) return -1;
        }

       while(g_continue){
            if(getchar()){  //按回车后终止程序运行
                g_continue = 0;
            }
       }

        return 0;
}

//生产者
 DWORD  WINAPI Producer(LPVOID lpPara)
    {
        while(g_continue){
            int i=rand()%5;
            Sleep(i*1000);
               WaitForSingleObject(g_hEmptyItems,INFINITE)                               ;//等待信号灯
               WaitForSingleObject(g_hMutex,INFINITE)                               ;
               system("cls");
            Produce();
            Append();
              ReleaseMutex(g_hMutex)                                ;
              ReleaseSemaphore(g_hFullItems,1,NULL)                                ;
       }
        return 0;
    }


     //消费者
    DWORD  WINAPI Consumer(LPVOID lpPara)
    {
        while(g_continue){
            int i=rand()%5;
            Sleep(i*1000);//该线程释放当前的控制权1500毫秒,让系统调度其他线程
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

   //生产一个产品。简单模拟了一下，仅输出新产品的ID号
    void Produce()
    {
		printf("\nProducing %d ...", ++ProductID);
		printf("Succeed\n");
   }


     //把新生产的产品放入缓冲区
    void Append()
    {

			  int i;
			  printf("Appending a product ...");
      g_buffer[in] = ProductID;
      in = (in+1)%SIZE_OF_BUFFER;
	  printf("Succeed\n");


      //输出缓冲区当前的状态

      for (i=0;i<SIZE_OF_BUFFER;++i)
	  {
		  printf("%d:",i);

           if (g_buffer[i]==-1)
			   printf("null");
           else
			   printf("%d",g_buffer[i]);
		     if (i==in) printf("\t<-- 生产");
			 if (i==out) printf("\t<-- 消费");
			 printf("\n");
        }
    }

   //从缓冲区中取出一个产品
   void Take()
   {
	   int i;
	   printf("\nTaking a product ...");
       ConsumeID = g_buffer[out];
       g_buffer[out]= -1;
       out = (out+1)%SIZE_OF_BUFFER;
	   printf("%d--Succeed\n", ConsumeID);

       //输出缓冲区当前的状态
       for (i=0;i<SIZE_OF_BUFFER;++i){
		   printf("%d:",i);
            if (g_buffer[i]==-1)
				 printf("null");
            else
				printf("%d",g_buffer[i]);
			if (i==in) printf("\t<-- 生产");
			if (i==out) printf("\t<-- 消费");
			printf("\n");

       }
    }

    //消耗一个产品
    void Consume()
    {
		printf("Consuming %d ", ConsumeID);
		printf("Succeed\n");
    }
