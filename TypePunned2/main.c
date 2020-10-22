#include "stdint.h" 
#include "stdio.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128

uint32_t swap(uint32_t Data32); 

int main(void)
{
    uint32_t data = 0x3F4FFFFF;

    printf("%x\n", swap(data));
    
    return 0;
}

uint32_t swap(uint32_t Data32)
{
    uint16_t* pData;
    uint16_t lh;
    uint16_t hh;

    pData = (uint16_t*)&Data32;

    lh = pData[0];
    hh = pData[1];

    pData[1] = lh;
    pData[0] = hh;

    return Data32;
}
