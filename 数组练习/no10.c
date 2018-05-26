#include "stdio.h" 

  

int func(int c,int a[],int x,int l) 

{ 

    int n; 

  

    if(l!=1) 

    { 

        for(n=0;n<5;n++)//轮5个没被杀头的 

        { 

            while(a[x%c]==1) x=x+1; 

            x=x+1; 

        }       

        a[(x-1)%c]=1;//将第5个杀头 

        printf("%d\t",(x-1)%c+1); 

        return func(c,a,(x-1)%c,l-1);//进入下一轮 

    }   

    else 

    { 

        while(a[x%c]==1) x=x+1; 

    }   

    return x%c+1; 

} 

int main() 

{ 

    int a[38]; 
    int i;

    for( i=0;i<37;i++) 

        a[i]=0; 

    printf("被杀头的顺序是：");  

    printf("\n\n%d",func(37,a,0,37));
    
    system("pause");
    } 
         
      
      
      
      
      
      
            
      
    
      
    
                     
                      
     
     
     
     
     
     
     
