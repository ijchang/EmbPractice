#include "stdint.h" 
#include "stdio.h"
/*add main.c*/

int main(void)
{
    int i = 3;
    int*ptr = &i;//ptr is a pointer to an integer(an interger is of type int). It can also point to an array of integer.
    int I[2];//I is an array of integers
    int*ptrI = &I[0];//ptrI is a pointer to an array of integers

    char*s1 = "foo";//s1 is a string(a string is of type char*, meaning it is a pointer to an array of characters)
    char**ptrs1 = &s1;//ptrs1 is a pointer to a string(a string is of type char*), meaining it is a pointer to a pointer to an array of characters. It can point to an array of strings.
    char*S1[2] = {"foo1", "foo2"};//S is an array of strings, or an array of pointers to characters
    char*S2[2] = {"foo3", "foo4"};
    char**ptrS1 = &S1[0];//ptrS1 is a pointer to an array of strings
    char**ptrS2 = &S2[0];
    int array[3] = {0};
    //int*ptr = NULL;
    //
    char***ptrSS; //ptrSS is a pointer to a pointer to an array of strings. ==> prtSS is a pointer to an array of array of strings..
    char**SS[2] = {ptrS1, ptrS2};

    ptrSS = &SS[0];
    
    ptr = array;

    printf("S1[0]=%s\n", **ptrSS);
    printf("S1[1]=%s\n", *(*ptrSS+1));
    printf("S2[0]=%s\n", *(*(ptrSS+1)));
    printf("S2[1]=%s\n", *(*(ptrSS+1)+1));

    printf("i=%d\n", *ptr);
    printf("I[0]=%d\n", *ptrI);
    //printf("%s\n", *ptrS);
    printf("sizeOf Char**=%ld\n", sizeof(char**));
    printf("sizeOf Char*=%ld\n", sizeof(char*));
    printf("*ptr=%d\n", *ptr);
    printf("s1=%s\n", *ptrs1);



    return 1;
}

