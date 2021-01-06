#include "stdint.h" 
#include "stdio.h"
#include "string.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128

int main(void)
{
    uint8_t a = 3 __attribute__((unused));
    //uint8_t b;

    a = 4;
    //b = 4;

    return 0;
}


