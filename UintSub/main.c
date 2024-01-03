#include "stdint.h" 
#include "stdio.h"
#include "main.h"
/*add main.c*/

int var;
int var;

int main(void)
{
    uint16_t a;
    uint16_t b; 

    a = 0xFFFE;
    b = 0xFFFF;
    printf("a = 0x%0*hx\n", 4, a);
    printf("b = 0x%0*hx\n", 4, b);
    printf("a - b = 0x%x\n", (a -b));

    if((a - b) >= (uint16_t)0x7FFF)
    {
        printf("1\n");
    }
    printf("sizeOf(int)=%ld\n", sizeof(int));
    printf("sizeOf(int16_t)=%ld\n", sizeof(int16_t));
    printf("sizeOf(a-b)=%ld\n", sizeof((a-b)));

    return 1;
}

