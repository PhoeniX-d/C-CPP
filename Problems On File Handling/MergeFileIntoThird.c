/*  
*   Program to merge two files into third
*/

#include<stdlib.h>
#include<stdio.h>
#define NAMESIZE        16

void MergeFile(char*, char*, char*);

int main()
{
    char sFile1[NAMESIZE] = {'\0'};
    char sFile2[NAMESIZE] = {'\0'};
    char sDest[NAMESIZE] = {'\0'};

    printf("Enter First file name\t\t:");
    scanf("%s", sFile1);

    printf("Enter second file name\t\t:");
    scanf("%s", sFile2);

    printf("Enter destination file name\t:");
    scanf("%s", sDest);

    MergeFile(sFile1, sFile2, sDest);

    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :MergeFile
//  Input       :char*, char*, char*
//  Returns     :void
//  Description :Merge two files into third file
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
//////////////////////////////////////////////////////////
void MergeFile(char sFile1[], char sFile2[], char sDest[])
{
    if(sFile1 == NULL || sFile2 == NULL || sDest == NULL)
    {
        printf("Invalid inputs\n");
        return;
    }

    FILE *fp1 = NULL, *fp2 = NULL, *fp3 = NULL;
    fp1 = fopen(sFile1, "r");
    fp2 = fopen(sFile2, "r");
    fp3 = fopen(sDest, "w");

    if(fp1 == NULL)
    {
        printf("Cannot open file %s", sFile1);
        return;
    }

    if(fp2 == NULL)
    {
        printf("Cannot open file %s", sFile2);
        return;
    }

    if(fp3 == NULL)
    {
        printf("Cannot open file %s", sDest);
        return;
    }
    char c = '\0';
    while((c = fgetc(fp1)) != EOF)
    {
        fputc(c, fp3);
    }

    while((c = fgetc(fp2)) != EOF)
    {
        fputc(c, fp3);
    }
    printf("Successfully Files merged\n");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
