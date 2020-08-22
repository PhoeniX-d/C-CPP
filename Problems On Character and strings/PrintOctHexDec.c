/*
*   Program to Print Hex, Octal, Decimal equivalent
*/
#include<stdio.h>

void PrintHOD();

int main()
{
    char cAlp = '\0';
    printf("Enter the character\n");
    scanf("%c", &cAlp);
    PrintHOD(cAlp);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :PrintHOD
//  Input       :void
//  Returns     :void
//  Description :Print Hex, Octal, Decimal equivalent
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
void PrintHOD(char ch)
{
    printf("Decimal\t\tHexadecimal\tOctal\t     Character\n");
    printf("%#3d\t\t%#x\t\t%#o\t\t%#c\n", ch, ch, ch, ch);
}