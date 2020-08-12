/* Program to print word according to number*/
#include<stdio.h>

void DisplayWord(int);

int main()
{
    int iNo = 0;
    printf("Enter the digit[0 - 9]");
    scanf("%d", &iNo);
    DisplayWord(iNo);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:DisplayWord
//	Input		:int
//	Returns		:void
//	Description	:print word according to number
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
void DisplayWord(
    int iNo
)
{
    if(iNo < 0)
        iNo = -iNo;
    
    switch(iNo)
    {
        case 0:
            printf("zero\n");
            break;
        case 1:
            printf("one\n");
            break;
        case 3:
            printf("three\n");
            break;
        case 4:
            printf("four\n");
            break;
        case 5:
            printf("five\n");
            break;
        case 6:
            printf("six\n");
            break;
        case 7:
            printf("seven\n");
            break;
        case 8:
            printf("eight\n");
            break;
        case 9:
            printf("nine\n");
            break;
        default:
            printf("Invalid");
    }
}
