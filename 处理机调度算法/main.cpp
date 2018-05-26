#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char id;        //������
	int cputime;    //����ʱ��
    int needtime;   //��������ʱ��
	int priority;   //������

	int startime;
	int endtime=0;
}PCB;		//����PCB�ṹ��

int jobNum = 4;		//��ҵ����
int batch = 2;		//��������ҵ����

PCB pcb[4];			//pcb������������������ҵ����Ϣ�����С������ҵ����
PCB memory[2];		//memory�����������汻���뵽�����е�������ҵ��Ϣ�����С������������ҵ����
PCB wait[2];		//wait�������������ѵ�����ҵ����û�ܱ����뵽�����е���ҵ�����С����jobNum-batch

int memoryNum = 0;	//�����������е���ҵ��������ʼ��Ϊ0
int waitNum = 0;	//�ȴ����������ҵ��������ʼ��Ϊ0

int MaxTime = 1000;	//�����������ʱ��100

float totalTime = 0;	//�����ܵ���תʱ��

void sort(PCB *pcb,int count,char key);
void process(int currentTmp, int nextTmp);

int main( void )
{
	PCB *tmp=(PCB*)malloc(sizeof(PCB));

	char id;
	int cputime, needtime, priority;
	int i, j;
	int current, next;

	printf("���������(char)������ʱ��(int)����������ʱ��(int)��������(int). ��������ʱ�����ȵ���������롿\n");
	for(i=0;i<jobNum;i++)
	{
		printf("������� %d ����ҵ�������Ϣ\n", i);
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
		printf("��ҵ %c �ĵ���ʱ��,��������ʱ��,�������ֱ�Ϊ%d, %d, %d��\n", pcb[i].id, pcb[i].cputime, pcb[i].needtime, pcb[i].priority);
	}

//���������ҵ
	for(i = 0; i < jobNum; i++)
	{
		current=pcb[i].cputime;
		if(i==jobNum-1)		//˵�������һ����ҵ
			next = MaxTime;
		else
			next = pcb[i+1].cputime;	//������һ�����̵����ʱ�䡣ע�ⲻ��Խ��

		//�Ƚ���ҵ�ŵ�wait�У�������
		wait[waitNum] = pcb[i];
		waitNum ++;
		if(waitNum > 1)
			sort(wait, waitNum, 'P');

		while(memoryNum < 2 && waitNum>0)		//����ǰ��������ҵ����С��2����ѵ�ǰ���̷��뵽������
		{
			memory[memoryNum] = wait[0];
			memory[memoryNum].cputime = current;
			memoryNum++;
			waitNum--;
			for(j = 1; j<=waitNum; j++)
				wait[j-1] = wait[j];
			sort(memory,memoryNum, 'P');
		}
       // printf("ʱ��:%f,����:%c%c%c%c%c%c\n",totalTime,memory[0].id,memory[1].id,memory[2].id,wait[0].id,wait[1].id,wait[2].id);
		process(current, next);		//����processʱ��memoryNum����Ϊ1
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

		while(memoryNum < 2 && waitNum>0)		//����ǰ��������ҵ����С��2����ѵ�ǰ���̷��뵽������
		{
			memory[memoryNum] = wait[0];
			memory[memoryNum].cputime = current;
			memoryNum++;
			waitNum--;
			for(j = 1; j<=waitNum; j++)
				wait[j-1] = wait[j];
			sort(memory,memoryNum, 'P');
		}
       // printf("ʱ��:%f,����:%c%c%c%c%c%c\n",totalTime,memory[0].id,memory[1].id,memory[2].id,wait[0].id,wait[1].id,wait[2].id);
		process(current, next);		//����processʱ��memoryNum����Ϊ1
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






 //�����������Ľ���������г���ͬʱ�����ڴ��е�������ҵ���С�������ҵ�����ڴ��ʱ�̼�����ʱ�̡�ƽ����תʱ��

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

//ѡ�������㷨����keyΪ'P'�����ȼ�������������ף�����Ϊ'N'������ʱ����ж���ҵ��������
void sort(PCB *pcb,int count, char key)
{
	if(key=='P')
    {
        PCB cache;//���ݽ���������
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
        PCB cache;//���ݽ���������
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
