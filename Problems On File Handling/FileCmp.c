/*
*   Write a program which accepts two file names from user and compare
*   contents of those files by using library functions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define NMEMB            1
#define TRUE             1
#define FALSE            0
typedef int BOOL;

BOOL FileCmp(char[], char[]);

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
        printf("Required 2 filename!!");
        return -1;
    }
    BOOL bRet = FALSE;

    bRet = FileCmp(argv[1], argv[2]);
    if(bRet == TRUE)
    {
        printf("Both files are equal\n");
    }
    else
    {
        printf("Both files are not equal\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :FileCmp
//  Input       :char[], char[]
//  Returns     :BOOL
//  Description :compare contents of those files by using 
//               library functions. end of other one
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
BOOL FileCmp(char cFileName1[], char cFileName2[])
{
    if(NULL == cFileName1 || NULL == cFileName2)
    {
        printf("Please Enter the file name properly\n");
        exit(1);
    }
    int i = 0;
    FILE *fp1 = NULL, *fp2 = NULL;
    char ch1 = '\0', ch2 = '\0';

    fp1 = fopen(cFileName1, "r");
	if(fp1 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName1);
		exit(1);
	}

    fp2 = fopen(cFileName2, "r");
	if(fp2 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName2);
		exit(1);
	}

    rewind(fp1);
    rewind(fp2);

    while(1)
	{
		//read single characters from both the files.
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
		
		//check whether end of file is reached or not.
		if(ch1 == EOF || ch2 == EOF || ch1 != ch2)
		{
			break;
		}
	}
    _fcloseall();
    if(ch1 != EOF || ch2 != EOF)
	{
		return FALSE;
	}
    return TRUE;    
}