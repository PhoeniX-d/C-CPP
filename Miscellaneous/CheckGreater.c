/*
*	Program to check number is greater than 100 or not
*/
#include<stdio.h>
#define TRUE	1
#define FALSE	0
typedef char BOOL;

// declaration isGreater
BOOL isGreater(int);

// entry point
int main()
{
	int iNum = 0;
	BOOL bRet = FALSE;
	printf("Enter the number\n");
	scanf("%d", &iNum);
	bRet = isGreater(iNum);
	if(bRet == TRUE)
	{
		printf("Greater\n");
	}
	else
	{
		printf("Smaller\n");
	}
	return 0;
}

// defination isGreater
BOOL isGreater(int iNum)
{
	return ((iNum > 100) ? TRUE : FALSE);
}