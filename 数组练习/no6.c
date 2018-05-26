#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
     int a[10][10],b[10][10],i,j;
     printf("a[][]:\n");
     srand(time(NULL));
     
     for(i=0;i<10;i++)
       {  
         for(j=0;j<10;j++)
         
             {
                          a[i][j]=rand()%200;
                          printf("%5d  ",a[i][j]);
                          b[j][i]=a[i][j];
             }
             
             printf("\n");
       }
       printf("\n\n\nb[][]:\n");
     for(i=0;i<10;i++)
      {     for(j=0;j<10;j++)
      {printf("%5d  ",b[i][j]);             
      }
      printf("\n");      
      }      
     
     system("pause");
     
     
     
     
     } 
