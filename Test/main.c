#include "stdint.h" 
#include "stdio.h"
#include "string.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128

int main(void)
{
    //uint8_t a = 3 __attribute__((unused));
    //uint8_t b;
    uint8_t b[3] = {1, 2, 3};
    uint8_t *p_b = &b[0];
    //a = 4;
    //b = 4;
    *(p_b++) = 4;
    *(p_b++) = 5;

    printf("b[0] = %d\n", b[0]);
    printf("b[1] = %d\n", b[1]);

    return 0;
}


