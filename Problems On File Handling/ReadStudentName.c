/* 
*   Program to read student names from a file
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define MAXRECORD   10
#define TRUE         1
#define FALSE        0
typedef int BOOL;

typedef struct 
{
    char szName[30];
    char szAdd[20];
    char cDiv;
    int  iRollNo;
    char szDept[10];
    float fMarks;
}STUDENT , *PSTUDENT;

BOOL ReadInfo(char*);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Please Pass file name which contains student info!!\n");
        return -1;
    }
    ReadInfo(argv[1]);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :ReadInfo
//  Input       :char[]
//  Returns     :BOOL
//  Description :Reads names of students stored in a file
//  Author      :Pranav Choudhary
//  Last Update :2 Oct 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
BOOL ReadInfo(char* szFilename)
{
    if(szFilename == NULL)
    {
        printf("Invalid Inputs for ReadInfo\n");
        return FALSE;
    }
    int fd = 0;
    if((fd = open(szFilename, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return FALSE;
    }
    PSTUDENT ps = (PSTUDENT)malloc(sizeof(STUDENT));
    int i = 1;
    printf("\n---------- Name of Student ----------\n");
    while(read(fd, ps, sizeof(STUDENT)) > 0)
    {
        printf("Name\t\t:%s\n", ps->szName);
        i++;
    }
    close(fd);
    return TRUE;    
}
