#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10
#define SElemType char
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    SElemType *top;
    SElemType *base;
    int stacksize;
}SqStack;


int InitStack(SqStack *S)    //��ʼ��ջ
{
      S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S->base)
     {
         puts("��ʼ��ջʧ�� ");
         return 0;
     }

     S->stacksize=STACK_INIT_SIZE;
     S->top=S->base;
     return 1;
}

SElemType GetTop(SqStack *S)   //����ջ��Ԫ��
{
   if(S->top==S->base)
   {
       puts("");
       exit(0);
   }
   return *(S->top-1);

}

int Push(SqStack *S,SElemType e)  //������Ԫ��
{
    if((S->top-S->base)>S->stacksize)
    {
        S->base=(SElemType *)realloc(S->base,(STACKINCREAMENT+S->stacksize)*sizeof(SElemType));
        if(!S->base)
        {
            puts("ջ�����ڴ�ʧ��");
            return 0;
        }

        S->top=S->base+S->stacksize;
        S->stacksize=S->stacksize+STACKINCREAMENT;
    }
    *(S->top++)=e;
    return 1;
}

int Pop(SqStack *S,SElemType *e)  //ɾ��ջ��Ԫ�ز���e����
{
     if(S->base==S->top)
     {
         puts("ɾ��ջ��Ԫ�ش���");
         return 0;
     }

     *e=*(S->top-1);

     S->top--;
     return 1;
}


main()
{
    char e,top;
    SqStack S;
    if(InitStack(&S))
    {
       puts("��ʼ��ջ�ɹ�");

    }
         scanf("%c",&e);
         fflush(stdin);
    while(e!='@')
    {
        if(Push(&S,e))
            {
                printf("����%c�ɹ�\n",e);
            }
        else
            {
                printf("����%cʧ��",e);
                return 0;
            }
          scanf("%c",&e);
          fflush(stdin);
    }
    for(;S.top!=S.base;)
    {
        e=GetTop(&S);
       printf("ջ��Ԫ����%c",e);
       if(Pop(&S,&e))
       {
            printf("ɾ��ջ��Ԫ��%c\n",e);
       }
       else
        {
           printf("ɾ��ջ��Ԫ��%cʧ��",e);
        }


    }

}





