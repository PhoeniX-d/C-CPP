/*
*	Program to print name on console
*/

#include<stdio.h>
#define MAX		30
int main()
{
	char cName[MAX];
	printf("Enter the name\n");
	scanf("%[^\n]", cName);
	printf("Your Name is :");
	printf("%s\n", cName);
	return 0;
}