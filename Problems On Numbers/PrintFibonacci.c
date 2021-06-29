/* Program to print fibonaci numbers upto given number */

#include<stdio.h>

void Fibonacci(int);

int main()
{
	int iNo = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    Fibonacci(iNo);
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :Fibonacci
//  Input       :int
//  Returns     :void
//  Desription  :computes fibonacci numbers upto given number
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
void Fibonacci(
                	int iNo		//Given Num
                )
{
    int iFirst = 0, iSecond = 1, iThird = 0, i = 0;
    iNo = (iNo < 0) ? -iNo : iNo;
    for (i = 1; i <= iNo; i++)
    {
        printf("%d ", iFirst);
        iThird = iFirst + iSecond;
        iFirst = iSecond;
        iSecond = iThird;
    }
}
