/*
*   Program to accept fname and read N bytes and display on
*   console
*/

#include<stdio.h>
#include<fcntl.h>

#define NAMESIZE        16

void Display(char *, int);

int main()
{
    char cFname[NAMESIZE] = {'\0'};
    int iBytes = 0;
    printf("Enter the file name:\n");
    scanf("%s", cFname);

    printf("Enter the number of bytes:\n");
    scanf("%d", &iBytes);

    Display(cFname, iBytes);

    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :char*, int
//  Returns     :void
//  Description :read N bytes from file and display
//  Author      :Pranav Choudhary
//  Last Update :2 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void Display(char* cFileName, int iBytes)
{
    int iFd = 0, iRet = 0;
    char *cBuffer = (char *)malloc(sizeof(char) * iBytes + 1);
    memset(cBuffer, '\0', iBytes + 1);

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
    printf("%d bytes Data Successfully read:\n%s\n", iBytes, cBuffer);
    free(cBuffer);
}