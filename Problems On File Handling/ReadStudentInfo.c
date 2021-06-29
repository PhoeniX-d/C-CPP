/* 
*   Program to read all student information from file 
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
//  Input       :char*
//  Returns     :BOOL
//  Description :Read student information from file
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
    while(read(fd, ps, sizeof(STUDENT)) > 0)
    {
        printf("\n---------- Information of Student %d ----------\n", i);
        printf("Name\t\t:%s\n", ps->szName);
        printf("Address\t\t:%s\n", ps->szAdd);
        printf("Roll No\t\t:%d\n", ps->iRollNo);
        printf("Division\t:%c\n", ps->cDiv);
        printf("Dept.\t\t:%s\n", ps->szDept);
        printf("Marks\t\t:%f\n", ps->fMarks);
        i++;
    }
    close(fd);
    return TRUE;    
}
