#include "stdint.h" 
#include "stdio.h"

//By adding 'restrict' keyword in front of the input parameters in copy_array,
//the assembly code of copy_array reduces a lot. This is because compiler does not need to 
//worry about if the memory addresses pointed by a and b would be overlapped and hence does a more
//aggressive compilation.
//main.s is the assembly code w/o 'restirct' keyword; mainR.s is w/i 'restrict' keyword

void copy_array(int n, uint8_t* restrict a, uint8_t* restrict b);

int main(void)
{
    uint32_t srcData = 0xFFFFFFFF;
    uint32_t dstData = 0;

    copy_array(4, (uint8_t*)&srcData, (uint8_t*)&srcData);

    printf("%x\n", srcData);
    
    return 0;
}

void copy_array(int n, uint8_t* restrict a, uint8_t* restrict b)
{
    while(n-- > 0)
        *a++ = *b++;
}
