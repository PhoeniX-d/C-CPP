/*
*   Write a program which accept number from user and print number of
*   digits of that number in recursive manner.
*   Input : 458752 Output : 6
*/

#include<stdio.h>

int NumLen(long long int);

int main()
{
    long long int iNum = 0;
    int iRet = 0;
    printf("Enter the number\t:");
    scanf("%lld", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    
    iRet = NumLen(iNum);
    printf("Number of digits\t:%d\n", iRet);
    return 0;
}
//////////////////////////////////////////////////////////////
//
//  Name        :NumLen
//  Input       :long long int
//  Returns     :void
//  Description :count digits in number using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
int NumLen(long long int iNo)
{
    static int iLen = 0;   /* Initialized only once */
    if(iNo != 0)
    {
        iLen++;
        NumLen(iNo / 10);   /*  Recursive calls NumLen() until i becomes iNo */
    }
    return iLen;
}