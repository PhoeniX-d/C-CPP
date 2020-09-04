/*
*   Write a program which accept file name from user and print two
*   characters after every fifty bytes by using library functions
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE		25

void PrintChar(char[]);

int main(int argc, char* argv[])
{
    /* create char array to store file name
	char fname[NAMESIZE]={'\0'};
    */
    if(argc != 2)
    {
        printf("FileName Required\n");
        return 1;
    }
	/* accept file name from user 
	printf("\nEnter file name with extension:\n");
	scanf("%s",fname);
    */
    PrintChar(argv[1]);
    return 0;
}

////////////////////////////////////////////////////////////////////
//
//  Name        :PrintChar
//  Input       :char*, char
//  Returns     :void
//  Description :print two characters after every fifty bytes by
//               using library functions
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////////////
void PrintChar(char *cFileName)
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
	//create FILE pointer
	FILE *fp = NULL;
	int iCnt = 1;
    char ch = '\0';
    //open file by using fopen()
	fp = fopen(cFileName, "r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}
    
	while(iCnt <= 2)
    {
        ch = fgetc(fp);
        if(ch == EOF)
            break;
        printf("%c", ch);
        iCnt++;
        if(iCnt == 3)
        {
            if((fseek(fp, 48, SEEK_CUR)) == -1)
            {
                printf("\nThere is no enough charactes in the file to seek from end.\n");
		        return;
            }
            iCnt = 1;
            printf("\n");
        }        
    }
    fclose(fp);
}
