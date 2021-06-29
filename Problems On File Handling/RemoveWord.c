/*
*   Write a program which accept file name from user and remove all
*   occurrence of particular word in that file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

void RemoveWord(char[], char[]);

int main(int argc, char* argv[])
{
    char cFname[NAMESIZE] = {'\0'};
    char cWord[NAMESIZE] = {'\0'};

    int iRet = 0;
    
    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);

    printf("Enter the word:\n");
    scanf("%s", cWord);

    RemoveWord(cFname, cWord);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :RemoveWord
//  Input       :char[], char[]
//  Returns     :int
//  Description :Remove all occuerances of word from file
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void RemoveWord(char cFileName[], char cWord[])
{
    if(NULL == cFileName || NULL == cWord)
    {
        printf("Invalid Inputs\n");
        return;
    }
    int i = 0, j = 0, k = 0;
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    char ch = '\0', Line[BLOCKSIZE] = {'\0'};
    fpos_t loc;


    //open file by using fopen()
	fp1 = fopen(cFileName, "r");
    fp2 = fopen("dump.tmp", "w");

    //check whether file is open or not.
	if(fp1 == NULL)
	{
		printf("\n Can not open file %s\n", cFileName);
        return;
    }
    //check whether file is open or not.
	if(fp2 == NULL)
	{
		printf("\n Can not creat file dump.tmp\n");
        return;
    }
    
    while((fgets(Line, BLOCKSIZE, fp1)) != NULL)
    {
        printf("Line before removal\t:%s", Line);
        for (i = 0; Line[i] != '\0'; i++)
        {
            j = 0;
            while(cWord[j] != '\0' && cWord[j] == Line[i])
            {
                i++;
                j++;
            }
            if(j == strlen(cWord))
            {
                for (k = i - j; Line[i] != '\0'; k++, i++)
                {
                    Line[k] = Line[i];
                }
                Line[k] = '\0';
            }
        }
        printf("Line after removal\t:%s", Line);
        fputs(Line, fp2);
        memset(Line, '\0', strlen(Line));
    }
    fclose(fp1);
    fclose(fp2);
    remove(cFileName);
    rename("dump.tmp", cFileName);
}