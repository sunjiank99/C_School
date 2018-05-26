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


int InitStack(SqStack *S)    //初始化栈
{
      S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S->base)
     {
         puts("初始化栈失败 ");
         return 0;
     }

     S->stacksize=STACK_INIT_SIZE;
     S->top=S->base;
     return 1;
}

SElemType GetTop(SqStack *S)   //返回栈顶元素
{
   if(S->top==S->base)
   {
       puts("");
       exit(0);
   }
   return *(S->top-1);

}

int Push(SqStack *S,SElemType e)  //插入新元素
{
    if((S->top-S->base)>S->stacksize)
    {
        S->base=(SElemType *)realloc(S->base,(STACKINCREAMENT+S->stacksize)*sizeof(SElemType));
        if(!S->base)
        {
            puts("栈新增内存失败");
            return 0;
        }

        S->top=S->base+S->stacksize;
        S->stacksize=S->stacksize+STACKINCREAMENT;
    }
    *(S->top++)=e;
    return 1;
}

int Pop(SqStack *S,SElemType *e)  //删除栈顶元素并用e返回
{
     if(S->base==S->top)
     {
         puts("删除栈顶元素错误");
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
       puts("初始化栈成功");

    }
         scanf("%c",&e);
         fflush(stdin);
    while(e!='@')
    {
        if(Push(&S,e))
            {
                printf("插入%c成功\n",e);
            }
        else
            {
                printf("插入%c失败",e);
                return 0;
            }
          scanf("%c",&e);
          fflush(stdin);
    }
    for(;S.top!=S.base;)
    {
        e=GetTop(&S);
       printf("栈顶元素是%c",e);
       if(Pop(&S,&e))
       {
            printf("删除栈顶元素%c\n",e);
       }
       else
        {
           printf("删除栈顶元素%c失败",e);
        }


    }

}





