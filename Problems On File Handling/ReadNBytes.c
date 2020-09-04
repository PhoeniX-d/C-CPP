/*
*   Write a program which accepts file name and one count from user and read
*   that number of characters from starting position.
*   Input : Demo.txt 12
*   Output : Display first 12 characters from Demo.txt 
*/

#include<stdio.h>
#include<fcntl.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

void Display(char *, int);

int main()
{
    char cFname[NAMESIZE] = {'\0'};
    int iBytes = 0;
    printf("Enter the file name:\n");
    scanf("%s", cFname);
    printf("Enter the number of bytes\n");
    scanf(" %d", &iBytes);

    Display(cFname, iBytes);

    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :char* , int
//  Returns     :void
//  Description :Display read file data upto N bytes
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void Display(char* cFileName, int iBytes)
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
    if(iBytes < 0)
    {
        iBytes = -iBytes;
    }
    
    int iFd = 0, iRet = 0;
    char *cBuffer = (char*)malloc(sizeof(char) * iBytes + 1);
    memset(cBuffer, 0, (iBytes + 1));

    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return;
    }
    if((iRet = read(iFd, cBuffer, iBytes)) < 0)
    {
        printf("Unable to read file\n");
        close(iFd);
        return;
    }
    printf("Data Successfully read:\n%s\n", cBuffer);
    free(cBuffer);
    close(iFd);
}