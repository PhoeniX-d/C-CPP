/*
*   Write a program which accept file name from user and count number of
*   occurrences of characters in small case and in capital case by using library
*   functions
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE		25

void CntUprLwr(char[]);

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

	CntUprLwr(argv[1]);
	return 0;
}

////////////////////////////////////////////////////////////////////
//
//  Name        :CntUprLwr
//  Input       :char*
//  Returns     :void
//  Description :count number of occurrences of characters
//               in small case and in capital case by using library   
//               functions
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////////////
void CntUprLwr(char *cFileName)
{
	//create FILE pointer
	FILE *fp = NULL;
	int iUprCnt = 0, iLwrCnt = 0, i = 0;
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
            if(cBuffer[i] >= 'a' && cBuffer[i] <= 'z')
            {
                iLwrCnt++;
            }
            else if(cBuffer[i] >= 'A' && cBuffer[i] <= 'Z')
            {
                iUprCnt++;
            }
        }
        memset(cBuffer, 0, BLOCKSIZE);
    }
    printf("\nNumber of Upper letter:\n%d\n", iUprCnt);
    printf("Number of Lower letter:\n%d\n", iLwrCnt);
    fclose(fp);
}
