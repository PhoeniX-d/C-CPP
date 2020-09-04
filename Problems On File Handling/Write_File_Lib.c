/*
*   Program to accept filename and open file in append mode
*   and write enterd string at end of file
*   size_t fwrite(void* src, size_t size, size_t nmemb, FILE *fp)
*/
#define BLOCKSIZE    5
#define NAMESIZE    16
#define NMEMB        1

#include <stdio.h>

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Enter the file name along with some data to write into that file\n");
        return -1;
    }
    int iRet = 0;
    /*char cFname[NAMESIZE] = {'\0'};
    char cBuffer[] = "Hello";*/
    FILE *fp = NULL;

    /*printf("Enter name of file:\n");
    scanf("%s", cFname);*/

    /* Open file using fopen() in readonly mode */
    if((fp = fopen(argv[1], "a")) == NULL)
    {
        printf("Unable to open that file\n");
        return -1;
    }
    printf("File Opened successfully\n");
    /* read file using fread() */
    if(iRet = fwrite((void *)argv[2], strlen(argv[2]), NMEMB, fp) != NMEMB)
    {
        printf("Unable to read file\n");
        fclose(fp);
        return -1;
    }
    printf("Data written successfully\n");

    if(fclose(fp))
    {
        printf("File not closed successfully\n");
        return -1;
    }
    return 0;
}