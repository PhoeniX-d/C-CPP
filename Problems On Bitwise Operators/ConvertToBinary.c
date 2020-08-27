/*
*   Program to Display Binary representation of enterd number
*/
#include<stdio.h>
#define MAXLEN      32
typedef unsigned int UINT;

void PrintBin(UINT);

int main()
{
    UINT uNum = 0;
    printf("Enter the number\n");
    scanf("%lu", &uNum);
    printf("Output:\n");
    PrintBin(uNum);

    return 0;
}
//////////////////////////////////////////////////////////////
//
//  Name        :PrintBin
//  Input       :UINT
//  Returns     :void
//  Description :Converts UINT to equivalent binary
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////
void PrintBin(UINT uNum)
{
    char cBin[MAXLEN] = {0}, i = 0, j = 0;
    while(uNum != 0)
    {
        cBin[i] = uNum % 2;
        uNum = uNum / 2;
        i++;
    }
    for (j = 31; j >= 0; j--)
    {
        printf("%d", cBin[j]);
        if(j % 4 == 0)
        {
            printf(" ");
        }
    }
}
