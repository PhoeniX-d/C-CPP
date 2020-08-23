/*
*   Write a program which accept two strings from user and append N characters
*   of second string after first string(Implement strncat()).
*   
*   Input : FirStr SecStr 4 Output : FirStrSecS 
*/

#include<stdio.h>
#define MAXLEN      20

void StrNCat(char *, char*, int);

int main()
{
    char cStr1[MAXLEN * 2] = {'\0'};
    char cStr2[MAXLEN] = {'\0'};
    int iN = 0;

    printf("Enter the 1st string\n"); 
    scanf("%[^\n]", cStr1);

    printf("Enter the 2nd string\n"); 
    scanf(" %[^\n]", cStr2);

    printf("Enter the number of char to append\n");
    scanf(" %d", &iN);

    StrNCat(cStr1, cStr2, iN);

    printf("Output String:\t%s\n", cStr1);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrNCat
//  Input       :char*, char*, int
//  Returns     :void
//  Description :append N characters of second string after
//               first string(Implement strncat())
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
////////////////////////////////////////////////////////////
void StrNCat(char* cStr1, char* cStr2, int iN)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }

    while(*cStr1 != '\0')
    {
        cStr1++;
    }
    while(*cStr2 != '\0' && iN != 0)
    {
        *cStr1 = *cStr2;
        cStr2++;
        cStr1++;
        iN--;
    }
    *cStr1 = '\0';
}
