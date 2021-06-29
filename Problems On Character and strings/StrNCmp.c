/*
*   Write a program which accept two strings from user and compare only first N
*   characters of two strings. If both strings are equal till first N characters then
*   return 0 otherwise return difference between first mismatch character
*   (Implement strncmp()).
*   
*   Input : FirStr FirNew 3 Output : Both strings are equal
*/

#include<stdio.h>

#define ERROR     -999
#define MAXLEN      30

int StrNCmp(const char *, const char*, int);

int main()
{
    char cStr1[MAXLEN] = {'\0'};
    char cStr2[MAXLEN] = {'\0'};
    int iRet = 0, iN = 0;

    printf("Enter the string 1\n"); 
    scanf("%[^\n]", cStr1);

    printf("Enter the string 2\n"); 
    scanf(" %[^\n]", cStr2);

    printf("Enter N\n");
    scanf(" %d", &iN);

    iRet = StrNCmp(cStr1, cStr2, iN);

    if(iRet == 0)
    {
        printf("Strings are equal\n");
    }
    else
    {
        printf("Strings are unequal\n");
    }    
    return 0;
}// end of main()

////////////////////////////////////////////////////////////
//
//  Name        :StrNCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :Implementation of strncmp()
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
////////////////////////////////////////////////////////////
int StrNCmp(const char* cStr1, const char* cStr2, int iN)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    if(iN < 0)
    {
        iN = -iN;
    }
    while(*cStr1 == *cStr2 && iN != 0)
    {
        if(*cStr1 == '\0' && iN != 0)
        {
            break;
        }
        cStr1++;
        cStr2++;
        iN--;
    }
    if(*cStr1 == *cStr2)
        return 0;
    else
        return *cStr1 - *cStr2;
}// end of StrNCmp()
