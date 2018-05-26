#include<stdio.h>

main()
{ puts("please input an number");
  int number,a[4],n;
  scanf("%d",&number);
  while(number!=6174)
  { a[0]=number/1000;
    a[1]=number/100%10;
    a[2]=number/10%10;
    a[3]=number%10;
    number = difference(a);
  }
  printf("%d",number);
  system("pause");
}
difference(int a[4])
{ int i,j,t,k,max,min,sul;
for(i=0;i<3;i++)
{    t=i;
                for(j=i+1;j<4;j++)
                {if(a[i]<a[j])
                  { t=j;
                  } 
                 if(t!=i)
                 { k=a[j];
                   a[j]=a[i];
                   a[i]=k;
                 }
                 t=i;
                 }
}
 max=a[0]*1000+a[1]*100+a[2]*10+a[3];
 min=a[3]*1000+a[2]*100+a[1]*10+a[0];   
 sul=max-min;
 printf("max %d  min %d  sul %d\n",max,min,sul);
 return sul;
              
}



               
               

