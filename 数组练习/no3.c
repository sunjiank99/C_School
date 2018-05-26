#include<stdio.h>
void main()


{  puts("please input the number of election participant");



int n,a[20],sum1=0,sum2=0,sum3=0,sumnull=0,i;

scanf("%d",&n);


puts("please input the elector's number (1-2-3)");

for(i=0;i<n;i++)

 {scanf("%d",&a[i]);

if(a[i]==1)

    sum1=sum1+1;

else if(a[i]==2)

    sum2=sum2+1;

else if(a[i]==3)


     sum3=sum3+1;
  else

     sumnull=sumnull+1;
 }

  printf("elector 1 has :%d\nelector2 has :%d\nelector 3 has:%d\n invalid has :%d",sum1,sum2,sum3,sumnull);


  system("pause");


}

















