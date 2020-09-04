/*
*   Write a program which accepts file name from user and count number of
*   spaces from that file.
*   Input : Demo.txt
*   Output : Number of spaces are 23 
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<io.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

int CountSpace(char[]);

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
    iRet = CountSpace(argv[1]);
    if(iRet != 0 || iRet != -1)
    {
        printf("Spaces in file %s :\n%d\n", argv[1], iRet);
    }
    else
    {
        printf("No spaces found in %s:\n", argv[1]);
    } 
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :CountSpace
//  Input       :char*
//  Returns     :int
//  Description :counts spaces in file
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
int CountSpace(char* cFileName)
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return -1;
    }
    if(cFileName == NULL)
    {
        printf("Please enter filename\n");
        return;
    }
    int iFd = 0, iRet = 0, iCnt = 0;
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    while((iRet = read(iFd, cBuffer, BLOCKSIZE)) > 0)
    {
        for (int i = 0; i < iRet; i++)
        {
            if(cBuffer[i] == ' ')
            {
                iCnt++;
            }
        }
        memset(cBuffer, 0, BLOCKSIZE);
    }
    close(iFd);
    return iCnt;
}