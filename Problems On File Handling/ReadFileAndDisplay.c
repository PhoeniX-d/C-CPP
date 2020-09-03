/*
*   Program to accept fname and read entire file and display on
*   console
*/

#include<stdio.h>
#include<fcntl.h>
#define BLOCKSZIE     1024
#define NAMESIZE        16

void Display(char *);

int main(int argc, char* argv[])
{
    char cFname[NAMESIZE] = {'\0'};
    printf("Enter the file name:\n");
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
    int iFd = 0, iRet = 0;
    char cBuffer[BLOCKSZIE];
    memset(cBuffer, '\0', BLOCKSZIE);

    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return;
    }
    while((iRet = read(iFd, cBuffer, BLOCKSZIE)) > 0)
    {
        write(1, cBuffer, iRet);
        memset(cBuffer, 0, iRet);
    }
}