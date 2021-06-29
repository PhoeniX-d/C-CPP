/*
*   Program to accept fname and read entire file and store each line in an Array
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define MAXLEN         256
#define MAXLINE         70 

void StoreArray(char *);

int main(int argc, char* argv[])
{
    char cFname[NAMESIZE] = {'\0'};
    
    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);

    StoreArray(cFname);

    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :StoreArray
//  Input       :char*
//  Returns     :void
//  Description :read Lines from file and Store it in Array
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void StoreArray(char* cFileName)
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
	//create FILE pointer
	FILE *fp = NULL;
	int i = 0, j = 0, iLen = 0, iRet = 0, k = 0; 
	char cBuffer[BLOCKSIZE], Line[MAXLINE][MAXLEN];
    memset(cBuffer, 0, BLOCKSIZE);

    //open file by using fopen()
	fp = fopen(cFileName, "r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		return;
	}
	
	while((fgets(Line[i],MAXLEN, fp)) != NULL)
	{
		Line[i][strlen(Line[i]) - 1] = '\0';
		i++;
	}
	j = i;
	fclose(fp);
	for (i = 0; i < j; i++)
	{
		printf("%s\n", Line[i]);
	}
}