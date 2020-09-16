/*
*   Program to print source code of same program
*/
#include<stdio.h>
#include<stdlib.h>

void PrintSource(FILE *);

int main()
{
    FILE *fp = NULL;
    fp = fopen(__FILE__, "r");
    if(fp == NULL)
    {
        printf("Cannot open file %s\n", __FILE__);
        return -1;
    }
    PrintSource(fp);
    fclose(fp);
    return 0;
}

//////////////////////////////////////////////////////////
//
//  Name        :PrintSource
//  Input       :FILE*
//  Returns     :void
//  Description :Prints source code of same program file
//  Author      :Pranav Choudhary
//  Last Update :16 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void PrintSource(FILE *fPtr)
{
    if(NULL == fPtr)
    {
        printf("Invalid Input\n");
        return;
    }
    char ch = '\0';
    while((ch = fgetc(fPtr))!= EOF)
    {
        fputc(ch, stdout);
    }
}