/* Program to print Prod of digits in a number */

#include<stdio.h>

int ProdDig(long);

int main()
{
	long lNo = 0;
	printf("Enter the number\n");
	scanf("%ld", &lNo);
    printf("Product of Even digits in number is %d", ProdDig(lNo));
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :ProdDig
//  Input       :long
//  Returns     :int
//  Desription  :computes Product of even digits in a number
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
int ProdDig(
              	long lNo		//Given Num
             )
{
	int i = 0, iProd = 1;	
	//	updater
	if(lNo < 0)
		lNo = -lNo;

	while(lNo > 0)
	{
        if((lNo % 10) % 2 == 0 && (lNo % 10) != 0)
        {
            iProd = iProd * (lNo % 10);
        }
        lNo = lNo / 10;
    }
    return (iProd == 1) ? 0 : iProd;
}
