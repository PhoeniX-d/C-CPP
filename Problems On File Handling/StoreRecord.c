/*
*   Write a program which accept information of 5 students from user and
*   insert that information into file by using library functions
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct _employee
{
    char    eName[50];
    int     eId;
    float   eSalary;
    char    eDept[20];
    char    eAdd[50];
} EMPLOYEE, *PEMPLOYEE;

void WriteRecord(PEMPLOYEE);
void DisplayRecord(PEMPLOYEE);

int main()
{
    EMPLOYEE emp[5];
    int iNo = 0;

    printf("Enter record for 5 employees\n");
    while(iNo < 2)
    {
        printf("---------- Employee %d----------\n", iNo + 1);
        printf("Enter Name of employee:\n");
        scanf(" %[^\n]", emp[0].eName);

        printf("Enter Address of employee:\n");
        scanf(" %[^\n]", emp[0].eAdd);

        printf("Enter Id of employee:\n");
        scanf(" %d", &emp[0].eId);

        printf("Enter Department of employee:\n");
        scanf(" %[^\n]", emp[0].eDept);

        printf("Enter Salary of employee:\n");
        scanf(" %f", &emp[0].eSalary);

        fflush(stdin);

        iNo++;
    }
    WriteRecord(emp);
    DisplayRecord(emp);

    return 0;
}

/////////////////////////////////////////////////////////////////
//
//  Name        :WriteRecord
//  Inputs      :PEMPLOYEE
//  Returns     :void
//  Description :Writes Employee record into a file
//  Author      :Pranav Choudhary
//  Date        :4 Sept 2020
//
//////////////////////////////////////////////////////////////////
void WriteRecord(PEMPLOYEE ptrEmp)
{
    if(ptrEmp == NULL)
    {
        printf("Invalid inputs\n");
        return;
    }
    FILE *fp = NULL;
    fp = fopen("EmployeeInfo.txt", "wb");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }
    printf("File Opened Successfully\n");
    fwrite((void *)ptrEmp, 2, sizeof(EMPLOYEE), fp);
    printf("Record Inserted Successfully\n");
    fclose(fp);
}

/////////////////////////////////////////////////////////////////
//
//  Name        :DisplayRecord
//  Inputs      :PEMPLOYEE
//  Returns     :void
//  Description :Displays Record (Reads)
//  Author      :Pranav Choudhary
//  Date        :4 Sept 2020
//
//////////////////////////////////////////////////////////////////
void DisplayRecord(PEMPLOYEE ptrEmp)
{
    FILE *fp = NULL;
	fp = fopen("EmployeeInfo.txt","rb");
	if(fp == NULL)
	{
		printf("\n can not open file.");
		exit(2);
	}
	memset(ptrEmp, 0, sizeof(EMPLOYEE) * 2);
	fread(ptrEmp, sizeof(EMPLOYEE), 2, fp);

	for(int i = 0; i < 2; i++)
	{
        printf("\nName Of Employee:\t\t%s\n", ptrEmp->eName);
        printf("Address Of Employee:\t\t%s\n", ptrEmp->eAdd);
        printf("Dept Of Employee:\t\t%s\n", ptrEmp->eDept);
        printf("Id Of Employee:\t\t\t%d\n", ptrEmp->eId);
        printf("Salary Of Employee:\t\t%f\n", ptrEmp->eSalary);
        ptrEmp++;
	}
	fclose(fp);
}