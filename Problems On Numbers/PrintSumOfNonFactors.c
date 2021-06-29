/* Program to compute sum of non factors of a number */

#include<stdio.h>

int SumNonFactor(int);

int main()
{
	int iNo = 0, iRet = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    iRet = SumNonFactor(iNo);
    printf("Summation of Non factors = %d\n", iRet);
    return 0;
}

////////////////////////////////////////////////////
//
//  Name        :SumNonFactor
//  Input       :int
//  Returns     :int
//  Desription  :compute summation of non factors of a number
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
////////////////////////////////////////////////////
int SumNonFactor(
                	int iNo		//Given Num
                )
{
	int i = 0, iSum = 0;
	//	updater
	if(iNo < 0)
		iNo = -iNo;

    for (i = 1; i <= iNo / 2; i++)
    {
        if(iNo % i != 0 )
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}
