/*
*   Program to Find all oocurances of all words in a file
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define NAMESIZE     16
#define MAXWORDS    256
#define MAXCHARS    256
#define WORDLEN      20

/* structure to hold word and its count */
typedef struct _wordcnt
{
    char *sWord;
    int iWcnt;
}WORD;

int  CheckCount(const char*);
void FindOccur(FILE *, char*);

WORD wordtab[MAXWORDS];

int main()
{
    char sFileName[NAMESIZE] = {'\0'};
    char *sLine = (char*)malloc(sizeof(char) * MAXCHARS);
    FILE *fp = NULL;

    printf("Enter the filename with extension\t:");
    scanf("%s", sFileName);

    fp = fopen(sFileName, "r");
    if(fp == NULL)
    {
        printf("Cannot open %s\n", sFileName);
        return 1;
    }
    FindOccur(fp, sLine);
    fclose(fp);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :FindOccur
//  Input       :FILE*, char*
//  Returns     :void
//  Description :Finds all occurances of all words in file
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void FindOccur(FILE *fp, char* sLine)
{
    if(NULL == fp || NULL == sLine)
    {
        printf("Invalid Inputs\n");
        return;
    }
    char cBuffer[WORDLEN] = {'\0'};
    int i = 0, j = 0, k = 0;
    ;
    while(fgets(sLine, MAXCHARS, fp) != NULL)
    {
        for (i = 0; sLine[i] != '\0'; i++)
        {
            j = 0;
            while(isalpha(sLine[i]) && j != WORDLEN)
            {
                cBuffer[j] = sLine[i];
                j++;
                i++;
            }
            if(j != 0)
            {
                cBuffer[j] = '\0';
                k = CheckCount(cBuffer);
            }
        }
        memset(sLine, 0, MAXCHARS);
    }
    i = 0;
    while(i != k)
    {
        printf("%-20s\t->%d\n", wordtab[i].sWord, wordtab[i].iWcnt);
        i++;
    }
}
/////////////////////////////////////////////////////////
//
//  Name        :CheckCount
//  Input       :const char*
//  Returns     :int
//  Description :Check word is present in array or not, 
//               if yes then increment is count else
//               add that word in array
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
//////////////////////////////////////////////////////////
int CheckCount(const char *cBuffer)
{
    int i = 0, iFlag = 0;
    for (i = 0; i < MAXWORDS && wordtab[i].iWcnt != 0; i++)
    {
        if(strcmpi(wordtab[i].sWord, cBuffer) == 0)
        {
            wordtab[i].iWcnt++;
            iFlag = 1;
        }
    }
    if(iFlag != 1)
    {
        wordtab[i].sWord = (char *)malloc(strlen(cBuffer) + 1);
        strcpy(wordtab[i].sWord, cBuffer);
        wordtab[i].iWcnt++;
    }
    return i;
}