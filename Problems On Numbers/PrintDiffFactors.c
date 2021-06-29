/* Program to compute difference between factor and non factors of a number */

#include<stdio.h>

int Difference(int);

int main()
{
	int iNo = 0, iRet = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    iRet = Difference(iNo);
    printf("Difference between factors and non factors = %d\n", iRet);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Name        :Difference
//  Input       :int
//  Returns     :int
//  Desription  :compute difference between factor and non factors of a number
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
///////////////////////////////////////////////////////////////////////////////
int Difference(
                	int iNo		//Given Num
                )
{
	int i = 0, iFsum = 0, iNfsum = 0;
	//	updater
	if(iNo < 0)
		iNo = -iNo;

    for (i = 1; i < iNo; i++)
    {
        if(iNo % i == 0 )
        {
            iFsum = iFsum + i;
        }
        else
        {
            iNfsum = iNfsum + i;
        }
    }
    return iFsum - iNfsum;
}
