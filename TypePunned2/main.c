#include "stdint.h" 
#include "stdio.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128

uint32_t swap(uint32_t Data32); 
void copy_array(int n, uint8_t* restrict a, uint8_t * restrict b);

int main(void)
{
    uint32_t data = 0x3F4FFFFF;
    uint32_t srcData = 0xFFFFFFFF;
    uint32_t dstData = 0;

//    printf("%x\n", swap(data));
    copy_array(4, (uint8_t*)&srcData, (uint8_t*)&srcData);

    printf("%x\n", srcData);
    
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

void copy_array(int n, uint8_t* restrict a, uint8_t* restrict b)
{
    while(n-- > 0)
        *a++ = *b++;
}
