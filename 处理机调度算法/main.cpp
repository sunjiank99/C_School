#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char id;        //进程名
	int cputime;    //到达时间
    int needtime;   //所需运行时间
	int priority;   //优先数

	int startime;
	int endtime=0;
}PCB;		//定义PCB结构体

int jobNum = 4;		//作业数量
int batch = 2;		//批处理作业个数

PCB pcb[4];			//pcb数组用来保存所有作业的信息，其大小等于作业数量
PCB memory[2];		//memory数组用来保存被调入到主存中的所有作业信息，其大小等于批处理作业个数
PCB wait[2];		//wait数组用来保存已到达作业，但没能被调入到主存中的作业。其大小等于jobNum-batch

int memoryNum = 0;	//调入至主存中的作业个数。初始化为0
int waitNum = 0;	//等待被调入的作业个数。初始化为0

int MaxTime = 1000;	//定义最大的完成时间100

float totalTime = 0;	//保存总的周转时间

void sort(PCB *pcb,int count,char key);
void process(int currentTmp, int nextTmp);

int main( void )
{
	PCB *tmp=(PCB*)malloc(sizeof(PCB));

	char id;
	int cputime, needtime, priority;
	int i, j;
	int current, next;

	printf("输入进程名(char)，到达时间(int)，所需运行时间(int)，优先数(int). 【按到达时间由先到后进行输入】\n");
	for(i=0;i<jobNum;i++)
	{
		printf("请输入第 %d 个作业的相关信息\n", i);
		scanf("%c%d%d%d",&id,&cputime,&needtime,&priority);
		tmp->id=id;
		tmp->cputime =cputime;
		tmp->needtime=needtime;
		tmp->priority=priority;
		pcb[i]=*tmp;
		fflush(stdin);
	}

	for(i=0;i<jobNum;i++)
	{
		printf("作业 %c 的到达时间,所需运行时间,优先数分别为%d, %d, %d：\n", pcb[i].id, pcb[i].cputime, pcb[i].needtime, pcb[i].priority);
	}

//逐个处理作业
	for(i = 0; i < jobNum; i++)
	{
		current=pcb[i].cputime;
		if(i==jobNum-1)		//说明是最后一个作业
			next = MaxTime;
		else
			next = pcb[i+1].cputime;	//保存下一个进程到达的时间。注意不能越界

		//先将作业放到wait中，再排序
		wait[waitNum] = pcb[i];
		waitNum ++;
		if(waitNum > 1)
			sort(wait, waitNum, 'P');

		while(memoryNum < 2 && waitNum>0)		//若当前主存中作业数量小于2，则把当前进程放入到主存中
		{
			memory[memoryNum] = wait[0];
			memory[memoryNum].cputime = current;
			memoryNum++;
			waitNum--;
			for(j = 1; j<=waitNum; j++)
				wait[j-1] = wait[j];
			sort(memory,memoryNum, 'P');
		}
       // printf("时间:%f,序列:%c%c%c%c%c%c\n",totalTime,memory[0].id,memory[1].id,memory[2].id,wait[0].id,wait[1].id,wait[2].id);
		process(current, next);		//调用process时，memoryNum至少为1
		printf("time:%d  ",current);
		printf("memory ");
		for(int i=0;i<memoryNum;i++)
        {
            printf("%c",memory[i].id);
        }
        printf("   wait ");
        for(int i=0;i<waitNum;i++)
        {
            printf("%c",wait[i].id);
        }
        puts("");


	}//end for

	for(i = 0; i < jobNum; i++)
	{
		totalTime += pcb[i].cputime;

	}

	for(current;jobNum!=0;current++)
    {
         if(waitNum > 1)
			sort(wait, waitNum, 'P');

		while(memoryNum < 2 && waitNum>0)		//若当前主存中作业数量小于2，则把当前进程放入到主存中
		{
			memory[memoryNum] = wait[0];
			memory[memoryNum].cputime = current;
			memoryNum++;
			waitNum--;
			for(j = 1; j<=waitNum; j++)
				wait[j-1] = wait[j];
			sort(memory,memoryNum, 'P');
		}
       // printf("时间:%f,序列:%c%c%c%c%c%c\n",totalTime,memory[0].id,memory[1].id,memory[2].id,wait[0].id,wait[1].id,wait[2].id);
		process(current, next);		//调用process时，memoryNum至少为1
		printf("time:%d  ",current);
		printf("memory ");
		for(int i=0;i<memoryNum;i++)
        {
            printf("%c",memory[i].id);
        }
        printf("   wait ");
        for(int i=0;i<waitNum;i++)
        {
            printf("%c",wait[i].id);
        }
        puts("");





    }

    float sum=0;
        for(int i=0;i<4;i++)
        {
            printf("%c startime:%d endtime:%d \n",pcb[i].id,pcb[i].cputime,pcb[i].endtime);
            sum+=pcb[i].endtime-pcb[i].cputime;
        }

        printf("everagetime : %f",sum/4);






 //在这里输出你的结果，包括列出不同时刻下内存中的运行作业序列、所有作业进入内存的时刻及结束时刻、平均周转时间

	return 0;
}

void process(int currentTmp, int nextTmp)
{
	  if(memoryNum>=1)
      {
          if(currentTmp-memory[0].cputime>=memory[0].needtime)
          {
              for(int i=0;i<memoryNum;i++)
              {
                  if(memory[i+1].endtime<50)
                  {


                  memory[i]=memory[i+1];
                  }
              }

              jobNum--;
              memoryNum--;


              for(int i=0;i<4;i++)
              {
                  if(memory[0].id==pcb[i].id)
                  {
                      pcb[i].endtime=currentTmp;
                  }
              }

          }

          memory[0].needtime=memory[0].needtime-(currentTmp-memory[0].cputime);

      }
}

//选择排序算法，若key为'P'则按优先级大的排在数组首，否则为'N'则按所需时间进行短作业优先排序
void sort(PCB *pcb,int count, char key)
{
	if(key=='P')
    {
        PCB cache;//数据交换缓冲区
        for(int i=0;i<count-1;i++)
        {
            for(int j=i+1;j<count;j++)
            {
                if(pcb[i].priority>pcb[j].priority)
                {
                    cache.id=pcb[i].id;
                    cache.cputime=pcb[i].cputime;
                    cache.needtime=pcb[i].needtime;
                    cache.priority=pcb[i].priority;

                    pcb[i].id=pcb[j].id;
                    pcb[i].cputime=pcb[j].cputime;
                    pcb[i].needtime=pcb[j].needtime;
                    pcb[i].priority=pcb[j].priority;

                    pcb[j].id=cache.id;
                    pcb[j].cputime=cache.cputime;
                    pcb[j].needtime=cache.needtime;
                    pcb[j].priority=cache.priority;
                }

            }
        }
    }
    if(key=='N')
    {
        PCB cache;//数据交换缓冲区
        for(int i=0;i<count-1;i++)
        {
            for(int j=i+1;j<count;j++)
            {
                if(pcb[i].needtime>pcb[j].needtime)
                {
                    cache.id=pcb[i].id;
                    cache.cputime=pcb[i].cputime;
                    cache.needtime=pcb[i].needtime;
                    cache.priority=pcb[i].priority;

                    pcb[i].id=pcb[j].id;
                    pcb[i].cputime=pcb[j].cputime;
                    pcb[i].needtime=pcb[j].needtime;
                    pcb[i].priority=pcb[j].priority;

                    pcb[j].id=cache.id;
                    pcb[j].cputime=cache.cputime;
                    pcb[j].needtime=cache.needtime;
                    pcb[j].priority=cache.priority;
                }

            }
        }
    }


}
