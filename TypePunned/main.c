#include "stdint.h" 
#include "stdio.h"
/*add main.c*/
void cmemset(int16_t *p16, int32_t* p32);

int main(void)
{
    uint32_t data = 0;
    cmemset((int16_t*)&data, (int32_t*)&data);

    return 0;
}

void cmemset(int16_t *p16, int32_t* p32)//if p16 is changed to int8_t*, then the printf result is the same for both -O1 and -O2
{
   *p16 = 2;
    *p32 = 128;
    printf("%d\n", *p16);
}
