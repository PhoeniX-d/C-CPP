/*
*	Write a program which accept file name from user and print its 
*   last 10 characters by using library functions. 
*/

#include<stdio.h>
#include<stdlib.h>

#define NAMESIZE		25

void PrintLastTenChar(char[]);

int main()
{
	//create char array to store file name
	char fname[NAMESIZE]={'\0'};

	//accept file name from user
	printf("\nEnter file name with extension\t:");
	scanf("%s",fname);

	PrintLastTenChar(fname);

	return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :PrintLastTenChar
//  Input       :char*
//  Returns     :void
//  Description :print last 10 characters by using 
//               library functions
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void PrintLastTenChar(char *cFileName)
{
	if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
	//create FILE pointer
	FILE *fp = NULL;
	char ch;

	//open file by using fopen()
	fp = fopen(cFileName, "r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	/*
	*	seek to 10 position in reverse(-ve value) 
	*	from end(SEEK_END) of file(fp)
	*/
	if(fseek(fp,-10,SEEK_END) == -1)
	{
		printf("\nThere is no enough charactes in the file to seek from end.\n");
		return;
	}

	printf("\nLast 10 characters are:\n");
	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
	}
	fclose(fp);
}