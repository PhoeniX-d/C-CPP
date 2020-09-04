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

void WriteRecord(PEMPLOYEE);
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
    /*
    printf("Enter record for 5 employees\n");
    while(i < MAXRECORD)
    {
        printf("\n-------------- Employee %d --------------\n", i + 1);
        printf("Enter Name of employee:\n");
        scanf(" %[^\n]", emp[i].eName);

        printf("Enter Address of employee:\n");
        scanf(" %[^\n]", emp[i].eAdd);

        printf("Enter Id of employee:\n");
        scanf(" %d", &emp[i].eId);

        printf("Enter Department of employee:\n");
        scanf(" %[^\n]", emp[i].eDept);

        printf("Enter Salary of employee:\n");
        scanf(" %f", &emp[i].eSalary);

        fflush(stdin);
        i++;
    }*/
    //WriteRecord(emp);
    DisplayRecord(emp, argv[1]);

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
    fwrite((void *)ptrEmp, MAXRECORD, sizeof(EMPLOYEE), fp);
    fclose(fp);
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