/* Program to compute factors of a number and display it in reverse order */

#include<stdio.h>

void DescFactor(int);

int main()
{
	int iNo = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
    DescFactor(iNo);
    return 0;
}

///////////////////////////////////////////////////////////////////////
//
//  Name        :DescFactor
//  Input       :int
//  Returns     :void
//  Desription  :compute factors of a number and display it in reverse
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
///////////////////////////////////////////////////////////////////////
void DescFactor(
                	int iNo		//Given Num
                )
{
	int i = 0;
	//	updater
	if(iNo < 0)
		iNo = -iNo;

    for (i = iNo / 2; i >= 1; i--)
    {
        if(iNo % i == 0 )
        {
            printf("%d ", i);
        }
    }
}
