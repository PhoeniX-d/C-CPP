/*
*   Write a program which accepts two file names from user and copy
*   contents of one file at the end of second file by using library functions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define NMEMB            1

void FileCpyAppend(char[], char[]);

int main(int argc, char* argv[])
{
    //char cFname1[NAMESIZE] = {'\0'};
    //char cFname2[NAMESIZE] = {'\0'};

    /*
    printf("Enter the source file name:\n");
    scanf("%s", cFname1);

    printf("Enter the destination file name:\n");
    scanf("%s", cFname2);
    */
    if(argc != 3)
    {
        printf("Required filename and word for occurance count!!");
        return -1;
    }

    FileCpyAppend(argv[1], argv[2]);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :FileCpyAppend
//  Input       :char[], char[]
//  Returns     :void
//  Description :appends contents of file at end of other one
//               returns -1 if not found
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void FileCpyAppend(char cFileName1[], char cFileName2[])
{
    if(NULL == cFileName1 || NULL == cFileName2)
    {
        printf("Please Enter the file name properly\n");
        exit(1);
    }
    FILE *fp1 = NULL, *fp2 = NULL;
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    //open file by using fopen()
	fp1 = fopen(cFileName1, "r");
	
	//check whether file is open or not.
	if(fp1 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName1);
		exit(1);
	}

    /* creat file using fopen() */
    fp2 = fopen(cFileName2, "a");

    //check whether file is open or not.
	if(fp2 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName2);
		exit(1);
	}

    while(fread(cBuffer, NMEMB, sizeof(cBuffer), fp1))
	{
        if(fwrite(cBuffer, NMEMB, strlen(cBuffer), fp2) == 1)
        {
            printf("Unable to copy data\n");
            exit(1);
        }
        /* cleans buffer for further use */
        memset(cBuffer, 0, BLOCKSIZE);
    }
    printf("File Successfully copied\n");
    fclose(fp1);
    fclose(fp2);
}