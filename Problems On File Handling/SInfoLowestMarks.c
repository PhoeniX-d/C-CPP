/* 
*   Program to read info of student whose marks are lowest from a file
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

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

/////////////////////////////////////////////////////////////////
//
//  Name        :ReadInfo
//  Input       :char[]
//  Returns     :BOOL
//  Description :Reads info of student whose marks are lowest
//               stored in a file
//  Author      :Pranav Choudhary
//  Last Update :2 Oct 2020 by Pranav Choudhary
//
/////////////////////////////////////////////////////////////////
BOOL ReadInfo(char* szFilename)
{
    if(szFilename == NULL)
    {
        printf("Invalid Inputs for ReadInfo\n");
        return FALSE;
    }
    int fd = 0, flag = 1;
    if((fd = open(szFilename, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return FALSE;
    }
    int i = 0;
    float fMin = 100.0f;
    PSTUDENT ps = (PSTUDENT)malloc(sizeof(STUDENT));
    STUDENT temp[MAXRECORD];
    while(read(fd, ps, sizeof(STUDENT)) > 0)
    {
        if(ps->fMarks < fMin)
        {
            fMin = ps->fMarks;
        }
        strcpy(temp[i].szName, ps->szName);
        strcpy(temp[i].szAdd, ps->szAdd);
        strcpy(temp[i].szDept, ps->szDept);
        temp[i].cDiv = ps->cDiv;
        temp[i].iRollNo = ps->iRollNo;
        temp[i].fMarks = ps->fMarks;
        i++;
    }
    for(int j = 0; j < i; j++)
    {
        if(temp[j].fMarks == fMin)
        {
            printf("\n---------- Student With lowest marks ----------\n");
            printf("Name\t\t:%s\n", temp[j].szName);
            printf("Address\t\t:%s\n", temp[j].szAdd);
            printf("Roll No\t\t:%d\n", temp[j].iRollNo);
            printf("Division\t:%c\n", temp[j].cDiv);
            printf("Dept.\t\t:%s\n", temp[j].szDept);
            printf("Marks\t\t:%f\n", temp[j].fMarks);
        }
    }
    close(fd);
    return TRUE;    
}
