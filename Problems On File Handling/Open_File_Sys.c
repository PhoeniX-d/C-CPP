/*
*   Program to accept name from user and Open a file
*   int open(char* filename, int mode);
*/
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char** argv)
{
    int iFd = 0;
    char cFname[16] = {'\0'};

    printf("Enter name of file:\n");
    scanf("%s", cFname);

    /* Open file using open() in readonly mode */
    iFd = open(cFname, O_RDONLY);
    if(iFd == -1)
    {
        printf("Unable to open that file\n");
        return -1;
    }
    printf("File is successfully opened with file descriptor:%d\n", iFd);
    if(close(iFd))
    {
        printf("File not closed successfully\n");
        return -1;
    }
    return 0;
}