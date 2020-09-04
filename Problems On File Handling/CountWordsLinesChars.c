/*
*   Write a program which accept file name from user and print number of
*   words, lines, chracters in that file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

void CountWordLineChar(char[]);

int main(int argc, char* argv[])
{
    //char cFname[NAMESIZE] = {'\0'};
    char cWord[NAMESIZE] = {'\0'};

    int iRet = 0;
    /*
    printf("Enter the file name:\n");
    scanf("%s", cFname);
    */
    if(argc != 2)
    {
        printf("Required filename and word for occurance count!!");
        return -1;
    }
   /* printf("Enter the word:\n");
    scanf(" %s", cWord);*/

    CountWordLineChar(argv[1]);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :CountWordLineChar
//  Input       :char[]
//  Returns     :void
//  Description :counts number of words, lines, characters
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void CountWordLineChar(char cFileName[])
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
    int iW = 0, iC = 0, iL = 0, i = 0, j = 0;
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
            if(cBuffer[i] == ' ')
            {
                while((cBuffer[i] == ' ' || cBuffer[i] == '\t') && (cBuffer[i] != '\0'))
                {
                    i++;
                }
            }
            else
            {
                while(cBuffer[i] != ' ' && cBuffer[i] != '\0')
                {
                    if(cBuffer[i] == '\n')
                    {
                        iL++;
                    }
                    i++;
                }
                iW++;
            }
        }
        iC = iC + strlen(cBuffer);
        /* clean buffer to get further data */
        memset(cBuffer, 0, BLOCKSIZE);
    }

    printf("Number of characters in %s are:\n%d\n", cFileName, iC);
    printf("Number of words in %s are:\n%d\n", cFileName, iW);
    printf("Number of lines in %s are:\n%d\n", cFileName, iL);

    fclose(fp);
}