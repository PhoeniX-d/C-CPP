/* 
*   Program to accept student information and store it into a file 
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAXRECORD 16
#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct
{
    char szName[30];
    char szAdd[20];
    char cDiv;
    int iRollNo;
    char szDept[10];
    float fMarks;
} STUDENT, *PSTUDENT;

BOOL GetInfo(PSTUDENT);
BOOL WriteInfo(char *, PSTUDENT, int, char);

int main()
{
    int iRecords = 0, i = 0, fd = 0;
    STUDENT student[MAXRECORD];
    char szFilename[MAXRECORD], cRes = '\0';
    printf("Enter the number of records to Write\t:");
    scanf("%d", &iRecords);
    if (iRecords > MAXRECORD)
    {
        printf("Maximum 10 records can be entered\n");
        return -1;
    }
    if (iRecords < 0)
    {
        iRecords = -iRecords;
    }
    while (iRecords != i)
    {
        printf("\n---------- Enter details for record %d ----------\n", i + 1);
        if ((GetInfo(&student[i])) == FALSE)
        {
            return -1;
        }
        i++;
    }

    printf("Do you want to add this info in existig file(enter e) or create new file(enter n)?\n");
    scanf(" %c", &cRes);
    printf("%c\n", cRes);
    printf("Enter the filname with extenstion\t:");
    scanf("%s", szFilename);
    WriteInfo(szFilename, student, iRecords, cRes);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :GetInfo
//  Input       :PSTUDENT
//  Returns     :BOOL
//  Description :Get student information from user
//  Author      :Pranav Choudhary
//  Last Update :2 Oct 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
BOOL GetInfo(PSTUDENT pstudent)
{
    if (pstudent == NULL)
    {
        printf("Invalid Inputs to GetInfo\n");
        return FALSE;
    }
    printf("Enter the Name\t\t:");
    scanf(" %[^\n]", pstudent->szName);
    printf("Enter the Address\t:");
    scanf(" %[^\n]", pstudent->szAdd);
    printf("Enter the RollNo\t:");
    scanf(" %d", &pstudent->iRollNo);
    printf("Enter the Div\t\t:");
    scanf(" %c", &pstudent->cDiv);
    printf("Enter the Dept\t\t:");
    scanf(" %[^\n]", pstudent->szDept);
    printf("Enter the Marks\t\t:");
    scanf(" %f", &pstudent->fMarks);
    return TRUE;
}

//////////////////////////////////////////////////////////
//
//  Name        :WriteInfo
//  Input       :PSTUDENT, int
//  Returns     :BOOL
//  Description :Writes student information into a file
//  Author      :Pranav Choudhary
//  Last Update :2 Oct 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
BOOL WriteInfo(char *szFilename, PSTUDENT pstudent, int iSize, char cRes)
{
    if (pstudent == NULL || (iSize < 0 && iSize > MAXRECORD) || szFilename == NULL)
    {
        printf("Invalid Inputs for WriteInfo");
        return FALSE;
    }
    int fd = 0;
    if (cRes == 'n')
    {
        printf("Inside New file cration\n");
        if ((fd = creat(szFilename, 0666)) == -1)
        {
            printf("File already exists or cannot creat such file\n");
            return FALSE;
        }
    }
    else if (cRes == 'e')
    {
        if ((fd = open(szFilename, O_APPEND | O_WRONLY)) == -1)
        {
            printf("File does not exists or cannot opne such file\n");
            return FALSE;
        }
    }
    printf("fd = %d\n", fd);
    write(fd, pstudent, sizeof(STUDENT) * iSize);
    close(fd);
    return TRUE;
}
