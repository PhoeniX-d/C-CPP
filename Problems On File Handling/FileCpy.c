/*
*   Program to accept 2 filenames from user one is existing and other is
*   new and copy contents from existing to new file
*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define TRUE             1
#define FALSE            0

typedef char BOOL;
BOOL FileCpy(int, int);

int main(int argc, char* argv[])
{
    char cFname1[NAMESIZE] = { '\0' };
    char cFname2[NAMESIZE] = { '\0' };
    int iFd1 = 0, iFd2 = 0;
    BOOL bRet = FALSE;

    printf("\nEnter existing file name with extension\t:");
    scanf("%s", cFname1);

    printf("\nEnter destination file name with extension\t:");
    scanf(" %s", cFname2);

    if ((iFd1 = open(cFname1, O_RDONLY)) == -1)
    {
        printf("Unable to open %s file\n", cFname1);
        return -1;
    }
    if((iFd2 = creat(cFname2, 0666)) == -1)
    {
        printf("Unable to creat %s file\n", cFname2);
        return -1;
    }
    bRet = FileCpy(iFd1, iFd2);
    if(bRet == TRUE)
    {
        printf("File Copied successfully\n");
    }
    else
    {
        printf("Failure in file copying\n");
    }

    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :FileCpy
//  Input       :int, int
//  Returns     :BOOL
//  Description :copy contents from existing to new file
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
BOOL FileCpy(int iFd1, int iFd2)
{
    
    int iRead = 0, iWritten = 0;
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    while ((iRead = read(iFd1, cBuffer, BLOCKSIZE)) > 0)
    {
        write(iFd2, cBuffer, iRead);
        if((iWritten = write(iFd2, cBuffer, iRead)) < 0)
        {
            printf("Unable to write data to file\n");
            return FALSE;
        }
        memset(cBuffer, 0, BLOCKSIZE);
    }
    close(iFd1);
    close(iFd2);
    return TRUE;
}