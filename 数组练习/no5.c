#include<stdio.h>
#include<string.h>

void order(int a[10],int*max,int*min);

void main()

{
    int a[10],i,c=0,d=0,e,*max=&c,*min=&d;
    int num1,num2;

    for(i=0;i<10;i++)

        {
            scanf("%d",&a[i]);
        }
        order(a,max,min);
        
        

   
   
     for(i=0;i<10;i++)
     {if(*max==a[i])
     a[i]=*min;
     else if(*min==a[i])
     a[i]=*max;
     printf("%d  ",a[i]);
}




        system("pause");






}

void order( int a[10],int*max,int*min)
{   int b[10];
    memcpy(b,a,10*sizeof(int));
    int i,j,k,t;

    for(i=0;i<9;i++)
    {


        k=i;
        for(j=i+1;j<10;j++)

        {if(b[k]>b[j])
        {k=j;}
    if(k!=i)
    {
        t=b[i];
        b[i]=b[k];
        b[k]=t;


    }k=i;
    }
    }
    printf("the max is %d\the min is %d \n",b[9],b[0]);
    
    *max=b[9];
    *min=b[0];










}

