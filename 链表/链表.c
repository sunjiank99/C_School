#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Horse Horse;

struct Horse
{ int age;
  int height;
  char name[20];
  char father[20];
  char mother[20];
  Horse *next;
};

int main(void)
{
  Horse *first=NULL;
  Horse *current=NULL;
  Horse *previous=NULL;
  char test='\0';
  
  for(;;)
  {printf("do you want to enter details of a %s horse (Y or N )?",first!=NULL?"nother":"");
   scanf("%c",&test);
   if(tolower(test)=='n')
   {break;}
   
   current=(Horse*)malloc(sizeof(Horse));
   
   if(first==NULL)
   {first=current;}
   if(previous!=NULL)
   {previous->next=current;}
   
   printf("Enter the name of the horse: ");
   scanf("%s",current->name);
   printf("how old is %s?",current->name);
   scanf("%d",&current->age);
   printf("how high is %s?",current->name);
   scanf("%d",&current->height);
   printf("who is %s's father?",current->name);
   scanf("%s",current->father);
   printf("who is %s's mother?",current->name);
   scanf("%s",current->mother);
   current->next=NULL;
   previous=current;
   fflush(stdin);
  }
  printf("\n");
  current=first;
  while(current!=NULL)
  { printf("%s is %d years old,%d hands high,",current->name,current->age,current->height);
    printf("and has %s and %s as parents.\n",current->father,current->mother);
    previous=current;
    current=current->next;
    free(previous);
    previous=NULL;
  }
  first=NULL;
  system("pause");
  return 0;
}   
   
   
   
