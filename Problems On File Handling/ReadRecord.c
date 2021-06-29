/*
*   Write a program which accept information of 5 students from user and
*   insert that information into file by using library functions
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXRECORD       4

typedef struct _employee
{
    char    eName[50];
    int     eId;
    float   eSalary;
    char    eDept[20];
    char    eAdd[50];
} EMPLOYEE, *PEMPLOYEE;

void DisplayRecord(PEMPLOYEE, char[]);

int main(int argc, char* argv[])
{
    EMPLOYEE emp[MAXRECORD];
    int i = 0;
    if(argc != 2)
    {
        printf("Enter Employee Name to be searched\n");
        return -1;
    }
    DisplayRecord(emp, argv[1]);

    return 0;
}

/////////////////////////////////////////////////////////////////
//
//  Name        :DisplayRecord
//  Inputs      :PEMPLOYEE, char[]
//  Returns     :void
//  Description :Displays Record (Reads)
//  Author      :Pranav Choudhary
//  Date        :4 Sept 2020
//
//////////////////////////////////////////////////////////////////
void DisplayRecord(PEMPLOYEE ptrEmp, char cName[])
{
    if(ptrEmp == NULL || cName == NULL)
    {
        printf("Invalid Inputs\n");
        return;
    }
    FILE *fp = NULL;
	fp = fopen("EmployeeInfo.txt","rb");
	if(fp == NULL)
	{
		printf("\n can not open file.");
		return;
	}
	memset(ptrEmp, 0, sizeof(EMPLOYEE) * MAXRECORD);
	fread(ptrEmp, sizeof(EMPLOYEE), MAXRECORD, fp);

	for(int i = 0; i < MAXRECORD; i++)
	{
        if(strcmp(ptrEmp->eName, cName) == 0)
        {
            printf("\n-------------- Employee %d --------------\n", i + 1);
            printf("\nName Of Employee:\t\t%s\n", ptrEmp->eName);
            printf("Address Of Employee:\t\t%s\n", ptrEmp->eAdd);
            printf("Dept Of Employee:\t\t%s\n", ptrEmp->eDept);
            printf("Id Of Employee:\t\t\t%d\n", ptrEmp->eId);
            printf("Salary Of Employee:\t\t%f\n", ptrEmp->eSalary);
        }
        ptrEmp++;
	}
	fclose(fp);
}