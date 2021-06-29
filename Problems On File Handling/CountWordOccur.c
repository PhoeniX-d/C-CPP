/*
*   Write a program which accept file name from user and print number of
*   occurrence of particular word in that file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

int CountOccur(char[], char[]);

int main(int argc, char* argv[])
{
    //char cFname[NAMESIZE] = {'\0'};
    char cWord[NAMESIZE] = {'\0'};

    int iRet = 0;
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

    iRet = CountOccur(argv[1], argv[2]);
    if(iRet != 0)
    {
        printf("Number of occurance of \'%s\' is %d\n", argv[2], iRet);
    }
    else
    {
        printf("Enterd word not found\n");
    }
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :CountOccur
//  Input       :char[], char[]
//  Returns     :int
//  Description :counts number of occurance of a word.
//               returns -1 if not found
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
int CountOccur(char cFileName[], char cWord[])
{
    if(NULL == cFileName || NULL == cWord)
    {
        printf("Invalid Inputs\n");
        return -1;
    }
    int iCnt = 0, i = 0, j = 0;
    FILE *fp = NULL;
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
    while((fgets(cBuffer, BLOCKSIZE, fp)) != NULL)
	{
        for (i = 0; cBuffer[i] != '\0'; i++)
        {
            j = 0;
            while(cWord[j] != '\0' && cWord[j] == cBuffer[i])
            {
                i++;
                j++;
            }
            if(j == strlen(cWord))
            {
                iCnt++;
            }
        }
        memset(cBuffer, 0, BLOCKSIZE);
    }
    fclose(fp);
    return iCnt;
}