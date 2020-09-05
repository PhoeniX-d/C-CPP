/*
*   Write a program which accept file name from user and copy the contents
*   in some other file in reverse order.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE     1024
#define NAMESIZE        16
#define NMEMB            1

void FileCpy(char[], char[]);

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

    FileCpy(argv[1], argv[2]);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :FileCpy
//  Input       :char[], char[]
//  Returns     :void
//  Description :copies contents of file to other one
//               returns -1 if not found
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void FileCpy(char cFileName1[], char cFileName2[])
{
    if(NULL == cFileName1 || NULL == cFileName2)
    {
        printf("Invalid Inputs\n");
        return;
    }
    int iSize = 0;
    FILE *fp1 = NULL, *fp2 = NULL;
    char cBuffer[BLOCKSIZE], ch = '\0', *cWBuffer = NULL;
    cWBuffer = (char *)malloc(sizeof(char) * BLOCKSIZE);
    memset(cBuffer, 0, BLOCKSIZE);
    memset(cWBuffer, 0, BLOCKSIZE);

    //open file by using fopen()
	fp1 = fopen(cFileName1, "r");
	fp2 = fopen(cFileName2, "w");

	//check whether file is open or not.
	if(fp1 == NULL && fp2 == NULL)
	{
		printf("\n Can not open file %s.\n", cFileName1);
		exit(1);
	}
    rewind(fp1);
    while(fread(cBuffer, NMEMB, BLOCKSIZE, fp1))
    {
        iSize = iSize + strlen(cBuffer);
        if(iSize >= BLOCKSIZE)
        {
            cWBuffer = (char *)realloc(cWBuffer, BLOCKSIZE + iSize);
        }
        strcat(cWBuffer, cBuffer);
    }
    strrev(cWBuffer);
    if(fwrite(cWBuffer, NMEMB, strlen(cWBuffer), fp2))
    {
        printf("File Successfully copied\n");
    }
    else
    {
        printf("Unable to perform copy\n");
    }    
    fclose(fp1);
    fclose(fp2);
}