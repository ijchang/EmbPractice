#include "stdint.h" 
#include "stdio.h"
#include "stdarg.h"
/*add main.c*/

#define NUMARGS(...) (sizeof(uint32_t[]){__VA_ARGS__})/sizeof(uint32_t)

#define SUM(var1, ...) (sum(var1, NUMARGS(__VA_ARGS__), __VA_ARGS__))

void sum(uint32_t var1, uint32_t numargs, ...);

int main(void)
{
    uint8_t a;
    uint32_t b,c;
    a = 0x8;
    b = 0xaaaaaaaa;
    c = 0xbbbbbbbb;
    SUM(0xb, a);
    SUM(0xb, a, b);
    SUM(0xb, a, b, c);
    return 1;
}

void sum(uint32_t var1, uint32_t numargs, ...)
{
    uint32_t var = 0;
    va_list ap;
    
    printf("var1 = 0x%x\n", var1);
    printf("numOfArg=%d\n", numargs);
    va_start(ap, numargs);
    while(numargs--)
    {
        var = va_arg(ap, uint32_t);
        printf("var = 0x%x\n", var);
    };

    return;
}
