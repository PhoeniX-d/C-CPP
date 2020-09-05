/*
*   Program to accept name from user and creat a file
*   int creat(char* filename, int mode);
*/
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char** argv)
{
    int iFd = 0;
    char cFname[16] = {'\0'};

    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);

    /* creat file using creat() in readonly mode */
    iFd = creat(cFname, 0777);
    if(iFd == -1)
    {
        printf("Unable to creat that file\n");
        return -1;
    }
    printf("File is successfully created with file descriptor:%d\n", iFd);
    if(close(iFd))
    {
        printf("File not closed successfully\n");
        return -1;
    }
    return 0;
}