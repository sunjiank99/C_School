#include <windows.h>
#include <stdio.h>
//#include <strsafe.h>

DWORD WINAPI ThreadProc1( LPVOID lpParam ) 
{

 int i=0,j=0;
    while(1)
 {
  printf("hello,this thread 1 ...\n");
  
  //��ʱ
  for(i=0;i<200000000;i++)
  {
   ;
  }
 }
} 

DWORD WINAPI ThreadProc2( LPVOID lpParam ) 
{

 int i=0,j=0;
    while(1)
 {
  printf("hello,this thread 2 ...\n");
  
  //��ʱ
  for(i=0;i<200000000;i++)
  {
   ;
  }
 }
} 

void main()
{
      int i=0;
    //�����߳�1
       CreateThread( 
            NULL,              // default security attributes
            0,                 // use default stack size  
            ThreadProc1,        // thread function 
            NULL,             // argument to thread function 
            0,                 // use default creation flags 
            NULL);           // returns the thread identifier 

    //�����߳�2
        CreateThread( 
            NULL,              // default security attributes
            0,                 // use default stack size  
            ThreadProc2,        // thread function 
            NULL,             // argument to thread function 
            0,                 // use default creation flags 
            NULL);           // returns the thread identifier

  //�����߳̽���ѭ�������߳����˳������߳�1��2�ᱻϵͳ��ɱ����
        while(1)
  {
  printf("hello,this thread 0 ...\n");
  
  //��ʱ
  for(i=0;i<200000000;i++)
  {;}

  }
}
