/* Program to print number of digits in a number */

#include<stdio.h>

int CountDig(long);

int main()
{
	long iNo = 0;
	printf("Enter the number\n");
	scanf("%ld", &iNo);
    printf("Total number of digits are %d", CountDig(iNo));
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :CountDig
//  Input       :long
//  Returns     :int
//  Desription  :counts number of digits in a number
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
int CountDig(
              	long iNo		//Given Num
             )
{
	int i = 0, iCnt = 0;	
	// filter
	if(iNo == 0)
		return 1;
	//	updater
	if(iNo < 0)
		iNo = -iNo;
	while(iNo > 0)
	{
        iNo = iNo / 10;
        iCnt++;
    }
    return iCnt;
}
