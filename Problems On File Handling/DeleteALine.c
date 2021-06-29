/*
*   Program to Delete a particular line from file
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE     100
#define MAXLEN      256
#define NAMESIZE     16

void DeleteLine(char *, int);

int main(int argc, char* argv[])
{
    int iLine = 0;
    char sFileName[NAMESIZE] = {'\0'};

    printf("Enter the file name with extension\t:");
    scanf("%s", sFileName);

    printf("Enter Line number to be deleted \t:");
    scanf("%d", &iLine);

    DeleteLine(sFileName, iLine);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :DeleteLine
//  Input       :char[], int
//  Returns     :void
//  Description :Delete desired line from file
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void DeleteLine(char * sFileName, int iLineNo)
{
    if(sFileName == NULL)
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