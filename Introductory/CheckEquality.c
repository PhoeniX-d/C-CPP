/*
*	Program to check number is Equal or not
*/
#include<stdio.h>
#define TRUE	1
#define FALSE	0
typedef char BOOL;

// declaration isEqual
BOOL isEqual(int, int);

// entry point
int main()
{
	int iNum1 = 0, iNum2 = 0;
	BOOL bRet = FALSE;
	printf("Enter the number\n");
	scanf("%d", &iNum1);
	printf("Enter the number\n");
	scanf("%d", &iNum2);
	bRet = isEqual(iNum1, iNum2);
	if(bRet == TRUE)
	{
		printf("Equal\n");
	}
	else
	{
		printf("UnEqual\n");
	}
	return 0;
}

// defination isEqual
BOOL isEqual(int iNum1, int iNum2)
{
	return ((iNum1 == iNum2) ? TRUE : FALSE);
}