/*
*   Write application which accept file name from user and display size of file.
*   Input : Demo.txt
*   Output : File size is 56 bytes 
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

int SizeOf(char *);

int main(int argc, char* argv[])
{
    //char cFname[NAMESIZE] = {'\0'};
    int iRet = 0;
    /*
    printf("Enter the file name:\n");
    scanf("%s", cFname);
    */
    if(argc != 2)
    {
        printf("File Name Required!!\n");
        return 0;
    }
    iRet = SizeOf(argv[1]);
    if(iRet != 0 || iRet != -1)
    {
        printf("Size of file %s :\n%d\n", argv[1], iRet);
    }
    else
    {
        printf("Cannot compute size\n");
    } 
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :SizeOf
//  Input       :char*
//  Returns     :int
//  Description :computes sizeof file
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
int SizeOf(char* cFileName)
{
    int iFd = 0, iRet = 0, iSize = 0;
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    while((iRet = read(iFd, cBuffer, BLOCKSIZE)) > 0)
    {
        iSize = iSize + iRet;
        memset(cBuffer, 0, BLOCKSIZE);
    }
    close(iFd);
    return iSize;
}