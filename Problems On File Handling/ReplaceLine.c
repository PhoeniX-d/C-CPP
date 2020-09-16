/*
*   Program to replace a particular line from file with entered text
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE     100
#define MAXLEN      256
#define NAMESIZE     16

void RepalceLine(char*, int, char*);

int main(int argc, char* argv[])
{
    int iLine = 0;
    char sFileName[NAMESIZE] = {'\0'};
    char sText[MAXLEN] = {'\0'};

    printf("Enter the file name with extension\t:");
    scanf("%s", sFileName);

    printf("Enter Line number to be repalced \t:");
    scanf(" %d", &iLine);

    printf("Enter replacement text:\n");
    scanf(" %[^\n]", sText);

    RepalceLine(sFileName, iLine, sText);
    return 0;
}

//////////////////////////////////////////////////////////////
//
//  Name        :RepalceLine
//  Input       :char[], int
//  Returns     :void
//  Description :repalce desired line from file with some text
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
/////////////////////////////////////////////////////////////
void RepalceLine(char sFileName[], int iLineNo, char sText[])
{
    if(sFileName == NULL || sText == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iLineNo < 0)
        iLineNo = -iLineNo;

    char Line[MAXLEN] = {'\0'};
    int i = 0, j = 0;
    FILE *fp1 = fopen(sFileName, "r");
    if(fp1 == NULL)
    {
        printf("Cannot open file\t:%s\n", sFileName);
        return;
    }
    FILE *fp2 = fopen("temp.txt", "w");
    if(fp2 == NULL)
    {
        printf("Cannot creat file\t:temp\n");
        return;
    }
    while(!(feof(fp1)) && i != MAXLINE)
    {
        memset(Line, '\0', MAXLEN);
        fgets(Line, MAXLEN, fp1);
        Line[strlen(Line) - 1] = '\0';
        if(!feof(fp1))
        {
            i++;
            if(i != iLineNo)
            {
                fprintf(fp2, "%s\n", Line);
            }
            else
            {
                j = iLineNo;
                fprintf(fp2, "%s\n", sText);
            }
        }       
    }
    if(j != iLineNo)
    {
        printf("Expected Line number is not in %s\n", sFileName);
    }
    fclose(fp1);
    fclose(fp2);
    remove(sFileName);
    rename("temp.txt", sFileName);
}