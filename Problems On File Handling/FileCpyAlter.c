/*
*   Write a program which accept file name from user and create one new file
*   and copy alternate lines from source file in that new file by using library
*   functions
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

#define BLOCKSZIE     1024
#define NAMESIZE        16

void FileCpyAlter(char[], char[]);

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

    FileCpyAlter(argv[1], argv[2]);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :FileCpyAlter
//  Input       :int, int
//  Returns     :void
//  Description :copy contents from existing to new file
//  Author      :Pranav Choudhary
//  Last Update :3 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void FileCpyAlter(char cFileName1[], char cFileName2[])
{
    if(NULL == cFileName1 || NULL == cFileName2)
    {
        printf("Please Enter the file name properly\n");
        exit(2);
    }
    FILE *fp1 = NULL, *fp2 = NULL;
    char ch = '\0';

    //open file by using fopen()
	fp1 = fopen(cFileName1, "r");
	
	//check whether file is open or not.
	if(fp1 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName1);
		exit(1);
	}

    /* creat file using fopen() */
    fp2 = fopen(cFileName2, "w");

    //check whether file is open or not.
	if(fp2 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName2);
		exit(1);
	}

    while((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
        if(ch == '\n')
        {
            ch = fgetc(fp1);
            while(ch != '\n' && ch != EOF)
            {
                ch = fgetc(fp1);
            }
        }
    }
    printf("File Successfully copied\n");
    fclose(fp1);
    fclose(fp2);
}