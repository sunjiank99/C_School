#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define ElemType int
typedef struct LNode
{
   ElemType num;

   struct LNode *next;
}LNode;


int CreateLNode(LNode *L)

{
       int input;
        LNode *p;
       L=(LNode *)malloc(sizeof(LNode)); //申请链表头结点
       if(!L)
       {
           puts("申请头结点失败");
           return 0;
       }

       p=L->next;
       scanf("%d",&input);

       while(input>=0)
       {
          p=(LNode *)malloc(sizeof(LNode));
          if(!p)
          {
              puts("申请空间失败 ");
              return 0;
          }
          p->num=input;
          p=p->next;
          scanf("%d",&input);
       }
       return  1;
}


main()
{
    LNode L;
    if(CreateLNode(&L))
    {
       puts("success");
    }


}



