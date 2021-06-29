/*
*   Program to accept name from user and Open a file
*   and read first 10 bytes
*   int read(int fd, char* buffer, int size)
*/
#include<stdio.h>
#include<fcntl.h>
#define BLOCKSIZE   10
#define NAMESIZE    16

int main(int argc, char** argv)
{
    int iFd = 0, iRet = 0;
    char cFname[NAMESIZE] = {'\0'};
    char cBuffer[BLOCKSIZE + 1] = {'\0'};

    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);

    /* Open file using open() in readonly mode */
    iFd = open(cFname, O_RDONLY);
    if(iFd == -1)
    {
        printf("Unable to open that file\n");
        return -1;
    }
    printf("File is successfully opened with file descriptor:%d\n", iFd);

    /* Read file using read() using file descriptor */
    iRet = read(iFd, cBuffer, BLOCKSIZE);
    if(iRet < 0)
    {
        printf("Unable to read file\n");
        if(close(iFd))
            printf("File not closed successfully\n");
        return -1;
    }
    printf("Number of Bytes read:\n%d\n", iRet);
    printf("Data Read:\n%s\n", cBuffer);

    if(close(iFd))
    {
        printf("File not closed successfully\n");
        return -1;
    }
    return 0;
}