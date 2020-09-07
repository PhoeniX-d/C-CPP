/*
*   Write a program which accept file name from user and reverse
*   occurrence of particular word in that file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define TRUE             1
#define FALSE            0
typedef int BOOL;

BOOL ReplaceOccur(char[], char[]);

int main(int argc, char* argv[])
{
    //char cFname[NAMESIZE] = {'\0'};
    char cWord[NAMESIZE] = {'\0'};

    int iRet = 0;
    BOOL bRet = FALSE;

    /*
    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);
    */
    if(argc != 3)
    {
        printf("Required filename and word for occurance count!!");
        return -1;
    }
   /* printf("Enter the word:\n");
    scanf(" %s", cWord);*/

    bRet = ReplaceOccur(argv[1], argv[2]);
    if(bRet == TRUE)
    {
        printf("Occurance replaced successfully\n");
    }
    else
    {
        printf("Word not found\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :ReplaceOccur
//  Input       :char[], char[]
//  Returns     :BOOL
//  Description :counts number of occurance of a word.
//               returns -1 if not found
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
BOOL ReplaceOccur(char cFileName[], char cWord[])
{
    if(NULL == cFileName || NULL == cWord)
    {
        printf("Invalid Inputs\n");
        return FALSE;
    }
    int iCnt = 0, i = 0, j = 0;
    FILE *fp = NULL;
    BOOL bRet = FALSE;
    
    char *cWd = (char *)malloc(sizeof(char) * strlen(cWord));
    strcpy(cWd, cWord);
    strrev(cWd);
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);
    fpos_t pos;
    
    //open file by using fopen()
	fp = fopen(cFileName, "r+");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		return FALSE;
	}
    while((fgets(cBuffer, BLOCKSIZE, fp)) != NULL)
	{
        for (i = 0; cBuffer[i] != '\0'; i++)
        {
            j = 0;
            iCnt++;
            while(cWord[j] != '\0' && cWord[j] == cBuffer[i])
            {
                i++;
                j++;
                iCnt++;
            }
            if(j == strlen(cWord))
            {
                fgetpos(fp, &pos);
                fseek(fp, iCnt - j - 1 ,SEEK_SET);
                fputs(cWd, fp);
                fsetpos(fp, &pos);
                bRet = TRUE;
            }
        }
        memset(cBuffer, 0, BLOCKSIZE);
    }
    fclose(fp);
    free(cWd);
    return bRet;
}