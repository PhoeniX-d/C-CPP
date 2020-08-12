/* Program to print sum of digits in a number */

#include<stdio.h>

int SumDig(long);

int main()
{
	long iNo = 0;
	printf("Enter the number\n");
	scanf("%ld", &iNo);
    printf("Summation of digits in number is %d", SumDig(iNo));
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :SumDig
//  Input       :long
//  Returns     :int
//  Desription  :computes summation of digits in a number
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
int SumDig(
              	long iNo		//Given Num
             )
{
	int i = 0, iSum = 0;	
	//	updater
	if(iNo < 0)
		iNo = -iNo;

	while(iNo > 0)
	{
        iSum = iSum + (iNo % 10);
        iNo = iNo / 10;
    }
    return iSum;
}
