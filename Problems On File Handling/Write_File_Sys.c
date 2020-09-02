/*
*   Program to accept filename and open file in append mode
*   and write "Hello" at end
*   int write(int fd, char* buffer, int size)
*/
#define BLOCKSIZE    5
#define NAMESIZE    16

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    int iFd = 0, iRet = 0;
    char cArr[] = "Hello";

    if((iFd = open(argv[1], O_APPEND | O_WRONLY)) == -1)
    {
        printf("Unable to open that file\n");
        return -1;
    }

    if((iRet = write(iFd, cArr, strlen(cArr))) < 0)
    {
        printf("Unable to read that file\n");
        close(iFd);
        return -1;
    }
    printf("Successfully Written % bytes\n", iRet);
    close(iFd);
    return 0;
}