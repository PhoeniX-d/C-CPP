/* Program to check given number is Palindrome or not 
 * Palindrome Number is such a number whose reverse is original number
 */

#include<stdio.h>
#define TRUE	1
#define FALSE	0
typedef int BOOL;


BOOL ChkPalindrome(int);

int main()
{
	int iNo = 0;
	BOOL bRet = FALSE;
	printf("Enter the number\n");
	scanf("%d", &iNo);
	bRet = ChkPalindrome(iNo);
	
	if(bRet == TRUE)
		printf("%d is Palindrome Number\n", iNo);
	else
		printf("%d is Not a Palindrome Number\n", iNo);

	return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:ChkPalindrome
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks given number us Palindrome or not
//
//////////////////////////////////////////////////////////
BOOL ChkPalindrome(
                	int iNo		//Given Num
                 )
{
	int i = 0, iTemp = iNo, iRev = 0, iDigit = 0;
	
	//	updater
	if(iNo < 0)
		iNo = -iNo;

	while(iTemp > 0)
	{
		iDigit = iTemp % 10;
		iRev = iRev * 10 + iDigit;
		iTemp = iTemp / 10;
	}
	if(iNo == iRev)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
