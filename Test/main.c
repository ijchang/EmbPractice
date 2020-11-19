#include "stdint.h" 
#include "stdio.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128

int main(void)
{
    uint8_t index;
    uint32_t data;

    for(index = 0; index < 5; ++index)
    {
        data = index;
    }

    printf("data = %d\n", data);
    printf("index = %d\n", index);

    switch(data)
    {
        printf("eeeee\n");

        case 4:
            printf("dddd\n");
        break;

        default:
        break;
    }
    return 0;
}


