#include<stdio.h>
void main()


{puts("please input the number of player");


int n,i,j,a[5][20],sum[20];
memset(sum,0,20*sizeof(int));

scanf("%d",&n);

for(i=0;i<n;i++)

    {

     printf("please input NO.%d grade\n",i+1);
     for(j=0;j<5;j++)

     {

      scanf("%d",&a[i][j]);

      sum[i]=a[i][j]+sum[i];
     }

    }


 for(i=0;i<n;i++)


        printf("NO%d grade is %d\n",i+1,sum[i]);


 system("pause");








}
