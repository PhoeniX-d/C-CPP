/*
*   Program to accept fname and read whole file and display on
*   console
*/

#include<stdio.h>
#include<fcntl.h>

#define BLOCKSIZE      512 
#define NAMESIZE        16

void Display(char *);

int main()
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
//  Description :read and display whole file
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void Display(char* cFileName)
{
    int iFd = 0, iRet = 0;
    char cBuffer[BLOCKSIZE];

    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return;
    }
    while((iRet = read(iFd, cBuffer, BLOCKSIZE)) != 0)
    {
        write(1, cBuffer, iRet);
        memset(cBuffer, '\0', BLOCKSIZE);
    }
    free(cBuffer);
    close(iFd);
}