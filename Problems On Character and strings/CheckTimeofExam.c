/*
*   Program to check Time for exam according to Division
*/
#include<stdio.h>

void CheckExamTime(char);

int main()
{
    char cAlp = '\0';
    printf("Enter the Division\n");
    scanf("%c", &cAlp);
    CheckExamTime(cAlp);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckExamTime
//  Input       :char
//  Returns     :BOOL
//  Description :check Time for exam according to Division
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
void CheckExamTime(char ch)
{
    if(ch == 'a' || ch == 'A')
    {
        printf("Your Exam at 7 AM\n");
    }
    else if(ch == 'b' || ch == 'B')
    {
        printf("Your Exam at 8:30 AM\n");
    }
    else if(ch == 'c' || ch == 'C')
    {
        printf("Your exam at 9:20 AM\n");
    }
    else if(ch == 'd' || ch == 'D')
    {
        printf("Your exam at 10:30 AM\n");
    }
    else
    {
        printf("Enter valid division\n");
    }
    
}