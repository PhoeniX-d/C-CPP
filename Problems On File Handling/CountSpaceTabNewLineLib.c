/*
*   Write a program which accept file name from user and count number of
*   white spaces, tabs, new lines by using library functions
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE		25

int CountEscapes(char[]);

int main(int argc, char* argv[])
{
	int iRet = 0;
    /* create char array to store file name
	char fname[NAMESIZE]={'\0'};
    */
    if(argc != 2)
    {
        printf("FileName Requited\n");
        return -1;
    }
	/* accept file name from user 
	printf("\nEnter file name with extension\t:");
	scanf("%s",fname);
    */

	iRet = CountEscapes(argv[1]);
    if(iRet == 0 || iRet == -1)
    {
        printf("No escape sequence in file %s\n", argv[1]);
    }
    else
    {
        printf("Number of escape sequences in file %s:\n%d\n", argv[1], iRet);
    }
    
	return 0;
}

////////////////////////////////////////////////////////////////////
//
//  Name        :CountEscapes
//  Input       :char*
//  Returns     :void
//  Description :count number of occurrences of spaces, tabs, new
//               lines by using library   
//               functions
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////////////
int CountEscapes(char *cFileName)
{
	if(NULL == cFileName)
	{
		printf("Invalid Inputs\n");
		return -1;
	}
	//create FILE pointer
	FILE *fp = NULL;
	int iEscapes = 0, i = 0;
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
    
	while((fgets(cBuffer,BLOCKSIZE, fp)) != NULL)
	{
        for(i = 0; cBuffer[i] != '\0'; i++)
        {
            if(cBuffer[i] == ' ' || cBuffer[i] == '\n' || cBuffer[i] == '\t')
            {
                iEscapes++;
            }
        }
        memset(cBuffer, 0, BLOCKSIZE);
    }
    fclose(fp);
    return iEscapes;
}
