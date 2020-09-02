/*
*   Program to accept fname and read data 10 bytes and display on
*   console
*/

#include<stdio.h>
#include<fcntl.h>

#define BLOCKSIZE     1024
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
//  Description :Display read file data
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void Display(char* cFileName)
{
    int iFd = 0, iRet = 0;
    char cBuffer[BLOCKSIZE] = {'\0'};
    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return;
    }
    if((iRet = read(iFd, cBuffer, BLOCKSIZE)) < 0)
    {
        printf("Unable to read file\n");
        close(iFd);
        return;
    }
    printf("Data Successfully read:\n%s\n", cBuffer);
}