/*
*   Program to remove empty lines from a file
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMESIZE         16
#define MAXLEN         1024  

void RemoveEmptyLines(FILE *, FILE *);

int main()
{
    char sFileName[NAMESIZE] = {'\0'};
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    printf("Enter the filename with extension\t:");
    scanf("%s", sFileName);

    fp1 = fopen(sFileName, "r");
    fp2 = fopen("temp.txt", "w");

    if(fp1 == NULL)
    {
        printf("Cannot open file %s\n", sFileName);
    }
    if(fp2 == NULL)
    {
        printf("Cannot create file temp.txt\n");
    }

    RemoveEmptyLines(fp1, fp2);

    remove(sFileName);
    rename("temp.txt", sFileName);

    return 0;
}

/////////////////////////////////////////////////////////////////
//
//  Name        :RemoveEmptyLines
//  Inputs      :FILE*, FILE*
//  Returns     :void
//  Description :Remove all empty lines from file
//  Author      :Pranav Choudhary
//  Date        :16 Sept 2020
//
//////////////////////////////////////////////////////////////////
void RemoveEmptyLines(FILE *fp1, FILE *fp2)
{
    if(fp1 == NULL || fp2 == NULL)
    {
        printf("Cannot open files:Invalid inputs\n");
        return;
    }
    char Line[MAXLEN] = {'\0'}, cFlag = 1;
    int i = 0, iLen = 0;
    while(fgets(Line, MAXLEN, fp1) != NULL)
    {
        for (i = 0; i < Line[i]; i++)
        {
            if(Line[i] != ' ' && Line[i] != '\t' && Line[i] != '\n' && 
            Line[i] != '\r' && Line[i] != ' ')
            {
                cFlag = 0;
                break;
            }
        }
        if (cFlag == 0)
        {
            cFlag = 1;
            fputs(Line, fp2);
        }
        /* Clear the buffer */
        memset(Line, 0, iLen);
    }
    fclose(fp1);
    fclose(fp2);
}
