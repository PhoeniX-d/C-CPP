/* Program to compute non factors of a number */

#include<stdio.h>

void NonFactor(int);

int main()
{
	int iNo = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    NonFactor(iNo);
    return 0;
}

////////////////////////////////////////////////////
//
//  Name        :NonFactor
//  Input       :int
//  Returns     :void
//  Desription  :compute non factors of a number
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
////////////////////////////////////////////////////
void NonFactor(
                	int iNo		//Given Num
                )
{
	int i = 0;
	//	updater
	if(iNo < 0)
		iNo = -iNo;

    for (i = 1; i <= iNo / 2; i++)
    {
        if(iNo % i != 0 )
        {
            printf("%d ", i);
        }
    }
}
