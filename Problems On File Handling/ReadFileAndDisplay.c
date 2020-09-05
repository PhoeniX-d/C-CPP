/*
*   Program to accept fname and read entire file and display on
*   console
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

void Display(char *);

int main(int argc, char* argv[])
{
    char cFname[NAMESIZE] = {'\0'};
    
    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);

    Display(cFname);

    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :char*
//  Returns     :void
//  Description :read entire file and display
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void Display(char* cFileName)
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
    int iFd = 0, iRet = 0, iSize = 0;
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return;
    }
    while((iRet = read(iFd, cBuffer, BLOCKSIZE)) > 0)
    {
        write(1, cBuffer, iRet);
        iSize = iSize + iRet;
        memset(cBuffer, 0, BLOCKSIZE);
    }
    printf("%d", iSize);
    close(iFd);
}