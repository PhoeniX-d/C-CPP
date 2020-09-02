/*
*   Program to accept name from user and Open a file
*   FILE *fp = fopen(char* filename, char* mode)
*/
#include<stdio.h>

int main(int argc, char** argv)
{
    FILE *Fp = NULL;
    char cFname[16] = {'\0'};

    printf("Enter name of file:\n");
    scanf("%s", cFname);

    /* Open file using fopen() in readonly mode */
    Fp = fopen(cFname, "r");
    if(Fp == NULL)
    {
        printf("Unable to open that file\n");
        return -1;
    }
    printf("File is successfully opened\n");
    if(fclose(Fp))
    {
        printf("File not closed successfully\n");
        return -1;
    }
    return 0;
}