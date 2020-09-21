/*
*   Program to find endianness of a Processor
*/

#include<stdio.h>

int main()
{
    /* Take some random integer */
    int iNo = 10, i = 0; 
    /* Take character pointer */
    char *pchar = NULL;
    /* Now store address of iNo into pchar */
    pchar = (char*)&iNo;
    if(*(pchar + 0) == iNo)
    {
        printf("Little Endian");
    }
    else if(*(pchar + 3) == iNo)
    {
        printf("Big Endian");
    }
    return 0;
}