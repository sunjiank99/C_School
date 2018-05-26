#include<stdio.h>
void main()
{
    while(1)
    {


    char a[100];


    gets(a);

    int i;

    for(i=0;a[i]!='\0';i++)

      {

        if(a[i]<='k'&&a[i]>='a')

         {a[i]=a[i]+11;}

        else if(a[i]<='z'&&a[i]>='l')

         {a[i]=a[i]-11;}

      }
    puts(a);

    system("pause");

     fflush(stdin);
    }




}
