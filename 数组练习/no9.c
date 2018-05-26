#include<stdio.h>
#include<string.h>
void main()
{
    puts("please input a paragraph of character");
    while(1)
    {


    char a[10],b[10];


    gets(a);
    memset(b,0,10*sizeof(char));


    int i,n;
    n=strlen(a);

    for(i=0;i<n;i++)

    {  b[n-1-i]=a[i];



    }








    if(strcmp(a,b)==0)

    {puts(" it is fret ");
    }

    else
    {puts(" it is not fret");
    }
    fflush(stdin);
    }
    }






