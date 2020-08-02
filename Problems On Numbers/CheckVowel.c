/* Program to check input character id vowel or not */

#include<stdio.h>
#define TRUE     1
#define FALSE    0
typedef int BOOL;

BOOL ChkVowel(char);

int main()
{
	char cCh = '\0';
    BOOL bRet = FALSE;
	printf("Enter the character\n");
	scanf("%c", &cCh);
    bRet = ChkVowel(cCh);
    (bRet == TRUE) ? printf("Its a Vowel\n"):printf("Its not a Vowel\n");
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :ChkVowel
//  Input       :char
//  Returns     :BOOL
//  Desription  :checks input character id vowel or not
//  Author      :Pranav P. Choudhary
//  Date        :2 August 2020
//
///////////////////////////////////////////////////////////////
BOOL ChkVowel(
                	char cCh		//Given Num
                )
{
   switch(cCh)
   {
        case 'a' :
        case 'A' :
        case 'E' :
        case 'e' :
        case 'i' :
        case 'I' :
        case 'o' :
        case 'O' :
        case 'u' :
        case 'U' : return TRUE;
        default  : return FALSE;
   }
}
