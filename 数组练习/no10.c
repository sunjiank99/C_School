#include "stdio.h" 

  

int func(int c,int a[],int x,int l) 

{ 

    int n; 

  

    if(l!=1) 

    { 

        for(n=0;n<5;n++)//��5��û��ɱͷ�� 

        { 

            while(a[x%c]==1) x=x+1; 

            x=x+1; 

        }       

        a[(x-1)%c]=1;//����5��ɱͷ 

        printf("%d\t",(x-1)%c+1); 

        return func(c,a,(x-1)%c,l-1);//������һ�� 

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

    printf("��ɱͷ��˳���ǣ�");  

    printf("\n\n%d",func(37,a,0,37));
    
    system("pause");
    } 
         
      
      
      
      
      
      
            
      
    
      
    
                     
                      
     
     
     
     
     
     
     
