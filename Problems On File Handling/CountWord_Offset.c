/*
*   Write a program which accept file name from user and print number of
*   words in that file along with offset at which they occured
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define NMEMB            1

void CountWord(char[], char[]);

int main(int argc, char* argv[])
{
    //char cFname[NAMESIZE] = {'\0'};
    char cWord[NAMESIZE] = {'\0'};

    /*
    printf("\nEnter file name with extension\t:");
    scanf("%s", cFname);
    */
    if(argc != 3)
    {
        printf("Required filename and word for occurance count!!");
        return -1;
    }
   /* printf("Enter the word:\n");
    scanf(" %s", cWord);*/

    CountWord(argv[1], argv[2]);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :CountWord
//  Input       :char[], char[]
//  Returns     :void
//  Description :counts number of words along with offset 
//               at which they occured.
//               returns -1 if not found
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void CountWord(char cFileName[], char cWord[])
{
    if(NULL == cFileName || NULL == cWord)
    {
        printf("Invalid Inputs\n");
        return;
    }
    int iWcnt = 0, i = 0, j = 0;
    FILE *fp = NULL;
    char cBuffer[BLOCKSIZE];
    memset(cBuffer, 0, BLOCKSIZE);

    //open file by using fopen()
	fp = fopen(cFileName, "r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}
    while(fread(cBuffer, NMEMB, sizeof(cBuffer), fp))
	{
        for (i = 0; cBuffer[i] != '\0'; i++)
        {
            j = 0;
            while(cWord[j] != '\0' && cWord[j] == cBuffer[i])
            {
                i++;
                j++;
            }
            if(j == strlen(cWord))
            {
                iWcnt++;
                printf("\n%d occurrence of \"%s\" word is found at %d offset.", iWcnt, cWord,((i-strlen(cWord))));
            }
        }
        /* cleans buffer for further use */
        memset(cBuffer, 0, BLOCKSIZE);
    }
    printf("\n");
    fclose(fp);
}