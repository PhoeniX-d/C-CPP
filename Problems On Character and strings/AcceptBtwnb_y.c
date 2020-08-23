/*
*   program which accepts a string from user which contains a characters
*   from ‘b’ to ‘y’.
*   Input : mn jn kn kazfd Output : mn jn kn k 
*/
#include<stdio.h>
#define MAXLEN      30

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n");
    scanf("%[^az]", cArr);
    printf("Accepted string is:\n%s\n", cArr);
    
    return 0;
}