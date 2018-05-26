
#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "WINMM.LIB")



 main()
{
      PlaySound("music//pengzhuang.wav", NULL,SND_FILENAME|SND_SYNC);
}
