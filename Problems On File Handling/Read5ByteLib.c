/*
*	Write a program which accept file name from user and print its 
*   first five characters by using library functions. 
*/

#include<stdio.h>
#include<stdlib.h>
#define NAMESIZE		25
void PrintFirstFiveChar(char[]);

int main()
{
	//create char array to store file name
	char fname[NAMESIZE]={'\0'};

	//accept file name from user
	printf("\nEnter file name with extension:\n");
	scanf("%s",fname);

	PrintFirstFiveChar(fname);

	return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :char*
//  Returns     :void
//  Description :print first five characters by using 
//               library functions
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void PrintFirstFiveChar(char *cFileName)
{
	if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
	//create FILE pointer
	FILE *fp = NULL;
	int iNo = 1;
	char ch;

	//open file by using fopen()
	fp = fopen(cFileName, "r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	printf("\nFirst five characters are:\n");
	while(iNo <= 5)
	{
		ch=fgetc(fp);
		if(ch == EOF)
		{
			break;
		}
		printf("%c", ch);
		iNo++;
	}
	printf("\n");
	fclose(fp);
}