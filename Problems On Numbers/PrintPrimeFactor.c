/* Program to print prime factor of a number */

#include<stdio.h>

void PrimeFactor(int);

int main()
{
	int iNo = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    PrimeFactor(iNo);
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :PrimeFactor
//  Input       :int
//  Returns     :void
//  Desription  :computes prime factors of number
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
void PrimeFactor(
                	int iNo		//Given Num
                )
{
	int i = 0,iPrime = 0;	
	//	updater
	if(iNo < 0)
		iNo = -iNo;

    for (i = iNo / 2; i > 1; i--)
    {
        if(iNo % i == 0)
        {
            for (iPrime = i / 2; iPrime > 1; iPrime--)
            {
                if (i % iPrime == 0)
                {
                    break;
                }
            }
            if(iPrime == 1)
            {
                printf("%d ", i);
            }
        }
    }
    if(i == 1 && iPrime == 0)
    {
        printf("Can't have factors of prime number\n");
    }
}
