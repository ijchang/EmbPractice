#include "stdint.h" 
#include "stdio.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128

void cmemset(int16_t* p16, int32_t* p32); 

int main(void)
{
    uint32_t data;

    cmemset((int16_t*)&data, (int32_t*)&data);
    
    return 0;
}

void cmemset(int16_t* p16, int32_t* p32)//if p16 is changed to int8_t*, then the printf result is the same for both -O1 and -O2
{
    *p16 = 2;
    *p32 = 128;
    printf("%d\n", *p16);
}
