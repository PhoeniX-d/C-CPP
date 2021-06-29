/* Program to compute product of factors of a number */

#include<stdio.h>

int MultFactor(int);

int main()
{
	int iNo = 0, iRet = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    iRet = MultFactor(iNo);
    printf("product of factors = %d\n", iRet);
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :MultFactor
//  Input       :int
//  Returns     :int
//  Desription  :compute product of factors of a number
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
///////////////////////////////////////////////////////////////
int MultFactor(
                	int iNo		//Given Num
                )
{
	int i = 0,iMult = 1;
	//	updater
	if(iNo < 0)
		iNo = -iNo;

    for (i = 1; i <= iNo / 2; i++)
    {
        if(iNo % i == 0 )
        {
            iMult = iMult * i;
        }
    }
    if(iNo == 0)
        return 0;
    else
        return iMult;
}
