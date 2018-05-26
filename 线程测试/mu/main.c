#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")
int main()
{
    PlaySound("music//a.wav", NULL,SND_FILENAME|SND_SYNC );
}
