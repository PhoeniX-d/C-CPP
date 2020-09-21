/*
*   Program to convert decimal number to binary number
*/
#include<stdio.h>

void DecToBin(int, int[]);

int main()
{
    int iNo = 0, iBin[32] = {0};
    printf("\nEnter the number\t:");
    scanf("%d", &iNo);
    printf("Binary equivalent is\t:");
    DecToBin(iNo, iBin);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", iBin[i]);
        if(i % 4 == 0)
        {
            printf(" ");
        }       
    }
    printf("\n");
    return 0;
}

void DecToBin(int iNo, int iBin[])
{
    static int i = 0;
    if(iNo != 0)
    {
        iBin[i] = iNo % 2;
        iNo = iNo / 2;
        i++;
        DecToBin(iNo, iBin);
    }
}