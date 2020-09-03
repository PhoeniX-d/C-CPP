/*
*   Program to accept fname and read file after entered offset and display on
*   console
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSZIE     1024
#define NAMESIZE        16
#define TRUE             1
#define FALSE            0

typedef char BOOL;
BOOL Display(char *, int);

int main(int argc, char* argv[])
{
    char cFname[NAMESIZE] = {'\0'};
    int iOffset = 0;
    BOOL bRet = FALSE;

    printf("Enter the file name:\n");
    scanf("%s", cFname);

    printf("Enter the offset:\n");
    scanf("%d", &iOffset);

    Display(cFname, iOffset);

    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :char*, int, int
//  Returns     :BOOL
//  Description :read file after particular offser and display data
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
////////////////////////////////////////////////////////////////////
BOOL Display(char *cFileName, int iOffset)
{
    int iFd = 0, iRet = 0;
    char cBuffer[BLOCKSZIE];
    memset(cBuffer, '\0', BLOCKSZIE);
    
    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return FALSE;
    }
    /* lseek for Random access */
    if(lseek(iFd, iOffset, SEEK_SET) == iOffset)
    {
        printf("File seeked %d bytes\n\n", iOffset);
    }
    while((iRet = read(iFd, cBuffer, BLOCKSZIE)) > 0)
    {
        write(1, cBuffer, iRet);
        memset(cBuffer, 0, BLOCKSZIE);
    }
    close(iFd);
    return TRUE;
}