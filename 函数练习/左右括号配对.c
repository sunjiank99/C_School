#include<stdio.h>
#include<string.h>
int yes(char a[20]);
void main()

{puts("������һ���ַ�");

char a[20];



gets(a);

if(yes(a)==0)
{puts("�������ŶԳ�");
}
else
 {puts("�������Ų��Գ�");}
 
 
 
 system("pause");
}

int yes(char a[20])

{int left=0 ,right=0,count;


for(count=0;count<strlen(a);count++)

{if(a[count]=='(')

    {left=left+1;}
    
 if(a[count]==')')
 
    {right=right+1;}
 }
if(right==left)
{return 0;}
else
{return 1;}
    
} 
