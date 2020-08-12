/* Program to print digits on even position */

#include<stdio.h>

void EvenPosDig(long);

int main()
{
	long lNo = 0, lRet = 0;
	printf("Enter the number\n");
	scanf("%ld", &lNo);
    EvenPosDig(lNo);
    return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:EvenPosDig
//	Input		:long
//	Returns		:void
//	Description	:prints digits on even position
//  Author      :Pranav P. Choudhary
//  Data        :1 Augest 2020
//
//////////////////////////////////////////////////////////
void EvenPosDig(
               	long lNo		//Given Num
                )
{
    int iCnt = 1;
    char cSign = 1;
    long lRev = 0L;
    //	updater
	if(lNo < 0)
    {
		lNo = -lNo;
        cSign = -1;
    }
	while(lNo > 0)
	{
        lRev = lRev * 10 + (lNo % 10);
        lNo = lNo / 10;
    }
    while(lRev != 0)
    {
        if(iCnt % 2 == 0)
        {
            printf("%d ", lRev % 10);
        }
        lRev = lRev / 10;
        iCnt++;        
    }
}
