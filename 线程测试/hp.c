#include <windows.h>
#include <stdio.h>
//#include <strsafe.h>

DWORD WINAPI ThreadProc1( LPVOID lpParam ) 
{

 int i=0,j=0;
    while(1)
 {
  printf("hello,this thread 1 ...\n");
  
  //延时
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
  
  //延时
  for(i=0;i<200000000;i++)
  {
   ;
  }
 }
} 

void main()
{
      int i=0;
    //创建线程1
       CreateThread( 
            NULL,              // default security attributes
            0,                 // use default stack size  
            ThreadProc1,        // thread function 
            NULL,             // argument to thread function 
            0,                 // use default creation flags 
            NULL);           // returns the thread identifier 

    //创建线程2
        CreateThread( 
            NULL,              // default security attributes
            0,                 // use default stack size  
            ThreadProc2,        // thread function 
            NULL,             // argument to thread function 
            0,                 // use default creation flags 
            NULL);           // returns the thread identifier

  //让主线程进入循环，主线程若退出，子线程1，2会被系统“杀死”
        while(1)
  {
  printf("hello,this thread 0 ...\n");
  
  //延时
  for(i=0;i<200000000;i++)
  {;}

  }
}
