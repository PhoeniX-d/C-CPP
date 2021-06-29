/* Program to toggle case of character */

#include<stdio.h>

char ToggleCase(char);

int main()
{
	char cCh = '\0', cRet = '\0';
	printf("Enter the character\n");
	scanf("%c", &cCh);
    cRet = ToggleCase(cCh);
    printf("%c", cRet);
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :ToggleCase
//  Input       :char
//  Returns     :char
//  Desription  :toggles case of chracter
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
///////////////////////////////////////////////////////////////
char ToggleCase(
                	char cCh		//Given Num
                )
{
    if(cCh >= 'a' && cCh <= 'z') 
        return (cCh - 32);
    else if(cCh >= 'A' && cCh <= 'Z')
        return (cCh + 32);
    else
    {
        printf("Please enter an alphabet\n");
        return cCh;
    }
}
