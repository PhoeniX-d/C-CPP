/*
*   Program to accept filename from user along with a string
*   and append that string at end of file
*/

#include <stdio.h>
#include <fcntl.h>

#define BLOCKSZIE 1024
#define MAXSZIE 30
#define NAMESIZE 16

void AppendString(char *, char *);

int main(int argc, char *argv[])
{
    char cFname[NAMESIZE] = {'\0'};
    char cString[MAXSZIE] = {'\0'};

    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);

    printf("Enter the string\t:");
    scanf(" %[^\n]", cString);

    AppendString(cFname, cString);

    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :AppendString
//  Input       :char*, char*
//  Returns     :void
//  Description :Append string at end of file
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void AppendString(char *cFileName, char *cString)
{
    if (NULL == cFileName || NULL == cString)
    {
        printf("Invalid Inputs\n");
        return -1;
    }
    int iFd = 0, iWritten = 0;
    char cBuffer[BLOCKSZIE];
    memset(cBuffer, '\0', BLOCKSZIE);

    if ((iFd = open(cFileName, O_WRONLY | O_APPEND)) == -1)
    {
        printf("Unable to open file\n");
        return;
    }

    if ((iWritten = write(iFd, cString, strlen(cString))) > 0)
    {
        printf("String appended successfully\n");
    }
    else
    {
        printf("Unable to write\n");
    }
    close(iFd);
}