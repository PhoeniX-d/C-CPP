/*
*	Program to calculate percentage of marks
*/

#include<stdio.h>
#define ERR		-1.0

float Percentage(int, int);

int main()
{
	int iTotal = 0, iObt = 0;
	float fPer = 0.0f;
	printf("Enter Total marks\n");
	scanf("%d", &iTotal);
	printf("Enter obtained marks\n");
	scanf("%d", &iObt);
	fPer = Percentage(iTotal, iObt);
	if(fPer == ERR)
		printf("Please Enter valid total marks\n");		
	else
		printf("Percentage is %f%\n", fPer);
	return 0;
}

/* computes percentage of marks */
float Percentage(
                 	int iTotal,
                 	int iObt
                 )
{
	float fPer = 0.0f;
	if(iTotal < 0)
		iTotal = -iTotal;
	if(iObt < 0)
		iObt = -iObt;
	if(iTotal == 0 || iTotal < iObt )
		return ERR;
	fPer = (float)iObt / iTotal * 100.0;
	return fPer;
}