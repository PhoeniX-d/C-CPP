/*
*   Program to Print ASCII characters upto 255
*/
#include<stdio.h>

void PrintASCII();

int main()
{
    PrintASCII();
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :PrintASCII
//  Input       :char
//  Returns     :void
//  Description :Print ASCII characters upto 255
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
void PrintASCII()
{
    int i = 0;
    printf("Decimal\t\tHexadecimal\tOctal\t     Character\n");
    for (i = 0; i < 256; i++)
    {
        printf("%3d\t\t%3X\t\t%3o\t\t%c\n", i, i, i, i);
    }
}