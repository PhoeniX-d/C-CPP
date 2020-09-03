/*
*   Write a program which accept file name from user and display contents of
*   file by using library functions.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE		25

void PrintFile(char[]);

int main(int argc, char* argv[])
{
	/* create char array to store file name
	char fname[NAMESIZE]={'\0'};
    */
    if(argc != 2)
    {
        printf("FileName Requited\n");
        return 1;
    }
	/* accept file name from user 
	printf("\nEnter file name with extension:\n");
	scanf("%s",fname);
    */

	PrintFile(argv[1]);
	return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :PrintFile
//  Input       :char*
//  Returns     :void
//  Description :print contents of a file by using 
//               library functions
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void PrintFile(char *cFileName)
{
	//create FILE pointer
	FILE *fp = NULL;
	int iNo = 1;
	char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    //open file by using fopen()
	fp = fopen(cFileName, "r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	printf("\nContents of %s are:\n", cFileName);
	while((fgets(cBuffer,BLOCKSIZE, fp)) != NULL)
	{
		printf("%s", cBuffer);
        memset(cBuffer, 0, BLOCKSIZE);
    }
	fclose(fp);
}