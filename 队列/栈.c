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
      QueuePtr front;   //头指针
      QueuePtr rear;     //尾指针
}LinkQueue;

int  InitQueue(LinkQueue *Q)  //初始化队列
{
      Q->front=Q->rear=(QNode *)malloc(sizeof(QNode));
      if(!Q->front)
      {
          puts("队列初始化错误");
          return 0;
      }
      Q->front->next=NULL;
      return 1;
}


int DestroyQueue(LinkQueue *Q)  //删除队列
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

int EnQueue(LinkQueue *Q,QElemType e)//插入e元素
{
    QueuePtr p;
    p=(QNode *)malloc(sizeof(QNode));
    if(!p)
    {
        puts("插入失败");
        return 0;
    }

    p->data=e;
    p->next=NULL;
	Q->rear->next=p;
     Q->rear=p;
     return 1;
}

int DeQueue(LinkQueue *Q,QElemType *e)  //删除队头元素，用e返回
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
        puts("初始化队列成功");
    }
    puts("请输入队列元素");

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




