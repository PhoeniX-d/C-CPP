/* Program to print reverse of given number */

#include<stdio.h>

long Reverse(long);

int main()
{
	long lNo = 0, lRet = 0;
	printf("Enter the number\n");
	scanf("%ld", &lNo);
	lRet = Reverse(lNo);
    printf("reverse is %ld", lRet);
    return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:Reverse
//	Input		:long
//	Returns		:long
//	Description	:return reverse og given number
//  Author      :Pranav P. Choudhary
//  Data        :1 Augest 2020
//
//////////////////////////////////////////////////////////
long Reverse(
               	long lNo		//Given Num
             )
{
	long lRev = 0;
    int i = 0, iDigit = 0;
    char cSign = 1;

    //	updater
	if(lNo < 0)
    {
		lNo = -lNo;
        cSign = -1;
    }
	while(lNo > 0)
	{
		iDigit = lNo % 10;
		lRev = lRev * 10 + iDigit;
		lNo = lNo / 10;
	}
    return lRev * cSign;
}
