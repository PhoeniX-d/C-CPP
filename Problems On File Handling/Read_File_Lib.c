/*
*   Program to accept name from user and Open a file
*   and read first 10 bytes
*   size_t fread(void* src, size_t size, size_t nmemb, FILE *fp)
*/
#include<stdio.h>
#define BLOCKSIZE   10
#define NAMESIZE    16
#define NMEMB        1

int main(int argc, char** argv)
{
    int iFd = 0, iRet = 0;
    char cFname[NAMESIZE] = {'\0'};
    char cBuffer[BLOCKSIZE + 1] = {'\0'};
    FILE *fp = NULL;

    printf("Enter name of file:\n");
    scanf("%s", cFname);

    /* Open file using fopen() in readonly mode */
    fp = fopen(cFname, "r");
    if(fp == NULL)
    {
        printf("Unable to open that file\n");
        return -1;
    }
    printf("File is successfully opened\n");
    
    /* read file using fread() */
    iRet = fread((void *)cBuffer, BLOCKSIZE, NMEMB, fp);
    if(iRet != NMEMB)
    {
        printf("Unable to read file\n");
        if(fclose(fp))
            printf("File not closed successfully\n");
        return -1;
    }
    printf("Data Read:\n%s\n", cBuffer);

    if(fclose(fp))
    {
        printf("File not closed successfully\n");
        return -1;
    }
    return 0;
}