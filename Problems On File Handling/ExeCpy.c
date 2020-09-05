/*
*   Write a program which accept executable file name from user and create
*   same executable on “D” drive with name “demo.exe”
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define NMEMB            1

void ExeCpy(char[], char[]);

int main(int argc, char* argv[])
{
    //char cFname1[NAMESIZE] = {'\0'};
    //char cFname2[NAMESIZE] = {'\0'};

    /*
    printf("\nEnter source file name with extension\t:");
    scanf("%s", cFname1);

    printf("\nEnter destination file name with extension\t:");
    scanf("%s", cFname2);
    */
    if(argc != 3)
    {
        printf("Required filename and word for occurance count!!");
        return -1;
    }

    ExeCpy(argv[1], argv[2]);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :ExeCpy
//  Input       :char[], char[]
//  Returns     :void
//  Description :copies contents of file to other one
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void ExeCpy(char cFileName1[], char cFileName2[])
{
    if(cFileName1 == NULL || cFileName2 == NULL)
    {
        printf("Invalid Input\n");
        exit(1);
    }

    FILE *fp1 = NULL, *fp2 = NULL;
    char ch = '\0';
    //open file by using fopen()
	fp1 = fopen(cFileName1, "rb");
	
	//check whether file is open or not.
	if(fp1 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName1);
		exit(1);
	}

    /* creat file using fopen() */
    fp2 = fopen(cFileName2, "wb+");

    //check whether file is open or not.
	if(fp2 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName2);
		exit(1);
	}

    while((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }
    printf("File Successfully copied\n");
    fclose(fp1);
    fclose(fp2);
}