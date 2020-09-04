/*
*   Write application which accept file name from user and display size of file.
*   Input : Demo.txt
*   Output : File size is 56 bytes 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE		25

int SizeOf(char[]);

int main(int argc, char* argv[])
{
	//char cFname[NAMESIZE] = {'\0'};
    int iRet = 0;
    /*
    printf("Enter the file name:\n");
    scanf("%s", cFname);
    */
    if(argc != 2)
    {
        printf("File Name Required!!\n");
        return 0;
    }
    iRet = SizeOf(argv[1]);
    if(iRet != 0 || iRet != -1)
    {
        printf("Size of file %s :\n%d\n", argv[1], iRet);
    }
    else
    {
        printf("Cannot compute size\n");
    } 
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :SizeOf
//  Input       :char*
//  Returns     :int
//  Description :computes sizeof file
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
int SizeOf(char *cFileName)
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return -1;
    }
	//create FILE pointer
	FILE *fp = NULL;
	int iSize = 1;
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
        iSize = iSize + strlen(cBuffer);
        memset(cBuffer, 0, BLOCKSIZE);
    }
	fclose(fp);
    return iSize;
}