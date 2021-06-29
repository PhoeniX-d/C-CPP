/* 
*   Program to read student marks from a file
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

BOOL ReadInfo(char*, char*);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Please Pass file name which contains student info!!\n");
        return -1;
    }
    char szName[20] = {'\0'};
    printf("Enter the name of student\t:");
    scanf("%[^\n]", szName);
    ReadInfo(argv[1], szName);
    return 0;
}

/////////////////////////////////////////////////////////////////
//
//  Name        :ReadInfo
//  Input       :char[]
//  Returns     :BOOL
//  Description :Reads info of specified student stored in a file
//  Author      :Pranav Choudhary
//  Last Update :2 Oct 2020 by Pranav Choudhary
//
/////////////////////////////////////////////////////////////////
BOOL ReadInfo(char* szFilename, char *szStudentName)
{
    if(szFilename == NULL || szStudentName == NULL)
    {
        printf("Invalid Inputs for ReadInfo\n");
        return FALSE;
    }
    int fd = 0, flag = 0;
    if((fd = open(szFilename, O_RDONLY)) == -1)
    {
        printf("Unable to open file\n");
        return FALSE;
    }
    PSTUDENT ps = (PSTUDENT)malloc(sizeof(STUDENT));
    while(read(fd, ps, sizeof(STUDENT)) > 0)
    {
        if(strcmp(szStudentName, ps->szName) == 0)
        {
            printf("Name\t\t:%s\n", ps->szName);
            printf("Address\t\t:%s\n", ps->szAdd);
            printf("Roll No\t\t:%d\n", ps->iRollNo);
            printf("Division\t:%c\n", ps->cDiv);
            printf("Dept.\t\t:%s\n", ps->szDept);
            printf("Marks\t\t:%f\n", ps->fMarks);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Student with name %s not found!!\n", szStudentName);
    }
    close(fd);
    return TRUE;    
}
