/*
*   Program to accept fname and a character from user and count occurance of that character
*   int that file
*/

#include<stdio.h>
#include<fcntl.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16

int CountOccur(char *, char);

int main(int argc, char* argv[])
{
    //char cFname[NAMESIZE] = {'\0'};
    char cAlp = '\0';
    int iRet = 0;
    /*
    printf("Enter the file name:\n");
    scanf("%s", cFname);
    */
    if(argc != 2)
    {
        printf("Required filename!!");
        return -1;
    }
    printf("Enter the character:\n");
    scanf(" %c", &cAlp);

    iRet = CountOccur(argv[1], cAlp);
    if(iRet != 0)
    {
        printf("Number of occurance of \'%c\' is %d\n", cAlp, iRet);
    }
    else
    {
        printf("Enterd character not found\n");
    }
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :CountOccur
//  Input       :char*, char
//  Returns     :int
//  Description :counts number of occurance of a character
//               returns -1 if not found
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
int CountOccur(char* cFileName, char ch)
{
    int iFd = 0, iCnt = 0, i = 0, iRead = 0;
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    if((iFd = open(cFileName, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    while((iRead = read(iFd, cBuffer, BLOCKSIZE)) > 0)
    {
        for (i = 0; i < iRead; i++)
        {
            if(cBuffer[i] == ch)
            {
                iCnt++;
            }
        }
        memset(cBuffer, 0, BLOCKSIZE);
    }
    close(iFd);
    if(iCnt == 0)
        return -1;
    else
        return iCnt;
}