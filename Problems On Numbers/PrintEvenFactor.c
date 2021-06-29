/* Program to print Even factor of a number */

#include<stdio.h>

void EvenFactor(int);

int main()
{
	int iNo = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    EvenFactor(iNo);
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :EvenFactor
//  Input       :int
//  Returns     :void
//  Desription  :computes Even factors of number
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
///////////////////////////////////////////////////////////////
void EvenFactor(
                	int iNo		//Given Num
                )
{
	int i = 0,iEven = 0;
	char cFlag = -1;	
	//	updater
	if(iNo < 0)
		iNo = -iNo;
    for (i = 1; i <= iNo / 2; i++)
    {
        if(iNo % i == 0 && i % 2 == 0 || i == 1)
        {
        	cFlag = 1;
            printf("%d ", i);
        }
        else
        	cFlag = 0;
    }
    if(cFlag == 0)
    	printf("Prime numbers did not have even factors\n");
}
