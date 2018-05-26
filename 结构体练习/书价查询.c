#include<stdio.h>

struct book
{ char name[10];
  int price;
}; 

typedef struct book B;

main()
{int count;
  B book[10];
  
  puts("please input name of 10 books");
  
  for(count=0;count<10;count++)
  {printf("%d booK:\n",count+1);
   puts("name:");
   gets(book[count].name);
   fflush(stdin);
   puts("price:");
   scanf("%d",&book[count].price);
   fflush(stdin);  
  }
  
  // refer max and min price
  B max,min;
  max=book[0];
  min=book[0];
  for(count=1;count<10;count++)
  {if(max.price<book[count].price)
    max=book[count];
   if(min.price>book[count].price)
    min=book[count]; 
  }
  // output the max and min price of the books
  printf("the max price book:   name:%s   price:%d\n",max.name,max.price);
  printf("the min price book:   name:%s   price:%d\n",min.name,min.price);
  
  
  system("pause");
}
