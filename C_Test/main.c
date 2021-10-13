#include "stdint.h" 
#include "stdio.h"
#include "string.h"
#include "limits.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128
typedef struct
{
    char* str;
    uint16_t len;
}trace_T;

trace_T trace[3] = {{"trace1", sizeof("trace1")}, {"test", 3}, {"test", 4}};

void TRACE1(char* p_str, uint16_t len, uint16_t var1);

int main(void)
{
    //uint8_t a = 3 __attribute__((unused));
    //uint8_t b;
/*
    uint8_t b[3] = {1, 2, 3};
    uint8_t *p_b = &b[0];
    int16_t c = -16;
    //a = 4;
    //b = 4;
    *(p_b++) = 4;
    *(p_b++) = 5;

    printf("b[0] = %d\n", b[0]);
    printf("b[1] = %d\n", b[1]);
    printf("c = %d\n", c);
    printf("sizeof(int)=%ld\n", sizeof(int));
    printf("INT_MIN=%d\n", INT_MIN);
*/
    /*
    char str[6] = "TEST=";
    //char *ptr1 = &str[20];
    *ptr1 = 0x31;
    uint8_t *ptr2 = (uint8_t*)&str[5];

    *ptr2=0x02;
    
    ptr2 = (uint8_t*)&str[0];
    printf("%x\n", *ptr2);
    ptr2 = (uint8_t*)&str[1];
    printf("%x\n", *ptr2);
    ptr2 = (uint8_t*)&str[2];
    printf("%x\n", *ptr2);
ptr2 = (uint8_t*)&str[3];
    printf("%x\n", *ptr2);
ptr2 = (uint8_t*)&str[4];
    printf("%x\n", *ptr2);
ptr2 = (uint8_t*)&str[5];
    printf("%x\n", *ptr2);
*/
    //char *text_base = "text_base";

  //  uint8_t text_full[strlen(text_base)+10];

    //text_full[0] = 0;
    //printf("text_full[0] = %d\n", text_full[0]);

    TRACE1(trace[0].str, trace[0].len, 10);
    //uint16_t len = sizeof("trace");
    //(void) len;

    return 0;
}

void TRACE1(char* p_str, uint16_t len, uint16_t var1)
{
    char str[len + sizeof(uint16_t)];

    str[0] = *p_str;
    printf("str=%x\n", str[0]);
    printf("strlen=%ld\n", sizeof(p_str));
    printf("input len=%d\n", len);
}
