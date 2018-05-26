#include<stdio.h>
#include<stdlib.h>
#define QElemType int
typedef struct QNode
{
    QElemType data;
    struct QNode *next;

}QNode,*QueuePtr;
typedef struct
{
      QueuePtr front;   //ͷָ��
      QueuePtr rear;     //βָ��
}LinkQueue;

int  InitQueue(LinkQueue *Q)  //��ʼ������
{
      Q->front=Q->rear=(QNode *)malloc(sizeof(QNode));
      if(!Q->front)
      {
          puts("���г�ʼ������");
          return 0;
      }
      Q->front->next=NULL;
      return 1;
}


int DestroyQueue(LinkQueue *Q)  //ɾ������
{
    QueuePtr p;
    while(Q->front)
    {
        p=Q->front->next;
        free(Q->front);
        Q->front=p;
    }
    free(Q->rear);
    return 1;
}

int EnQueue(LinkQueue *Q,QElemType e)//����eԪ��
{
    QueuePtr p;
    p=(QNode *)malloc(sizeof(QNode));
    if(!p)
    {
        puts("����ʧ��");
        return 0;
    }

    p->data=e;
    p->next=NULL;
	Q->rear->next=p;
     Q->rear=p;
     return 1;
}

int DeQueue(LinkQueue *Q,QElemType *e)  //ɾ����ͷԪ�أ���e����
{
    QueuePtr p;
    if(Q->rear==Q->front)
    {
       return 0;
    }

    p=Q->front;
    *e=p->data;
    Q->front=Q->front->next;
    if(Q->rear==p){Q->rear=Q->front;}
    free(p);
    return 1;
}
main()
{    int e=0;
    LinkQueue Q;
    if(InitQueue(&Q))
    {
        puts("��ʼ�����гɹ�");
    }
    puts("���������Ԫ��");

    while(e!=-1)
    {
        scanf("%d",&e);
        fflush(stdin);
        EnQueue(&Q,e);

    }

    while(Q.front)
    {
        printf("%d ",Q.front->data);
        Q.front=Q.front->next;
    }




}




