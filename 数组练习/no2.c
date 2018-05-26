#include<stdio.h>
void main()
{

  int a[10],b[10],i;

  puts("please input 10 integer");


  for(i=0;i<10;i++)

    scanf("%d",&a[i]);


  for(i=0;i<9;i++)


    {
        b[i]=a[i]+a[i+1];

    printf("%-4d   ",b[i]);

    if((i+1)%3==0)

        printf("\n");

    }

    system("pause");












}
