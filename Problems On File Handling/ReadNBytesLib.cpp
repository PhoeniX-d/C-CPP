/*
*   Write a program which accept file name from user and print its first five
*   characters by using library functions
*/
#include<stdio.h>
#include<iostream>

#define BLOCKSIZE       1024
#define NAMESIZE          16
#define NMEMB              1

using namespace std;
void Display(char[], int);

int main()
{
    char cFname[NAMESIZE] = {'\0'};
    int iBytes = 0;

    cout << "Enter the filename with extension\t:";
    scanf("%s", cFname);

    cout <<"Enter number of bytes to read:\n";
    cin >> iBytes;

    Display(cFname, iBytes);

    return 0;
}
//////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :char* , int
//  Returns     :void
//  Description :Read N bytes from file and display
//  Author      :Pranav Choudhary
//  Last Update :4 Sept 2020 by Pranav Choudhary
//
///////////////////////////////////////////////////////////
void Display(char cFileName[], int iBytes)
{
    if(NULL == cFileName)
    {
        printf("Invalid Inputs\n");
        return;
    }
    if(iBytes < 0)
        iBytes = -iBytes;

    FILE *fp = NULL;
    int iRet = 0;
    char *cBuffer = new char[BLOCKSIZE];

    if(cBuffer == NULL)
    {
        cout << "Memory allocation failed\n";
        return;
    }
    memset(cBuffer, 0, BLOCKSIZE);

    fp = fopen(cFileName, "r");
    if(fp == NULL)
    {
        cout << "Cannot open file " << cFileName << endl;
        return;
    }
    iRet = fread((void *)cBuffer, iBytes, NMEMB, fp);
    if(iRet != NMEMB)
    {
        cout << "Failure in reading file\n";
        return;
    }
    cout << "Successfully " << iBytes << " read:\n" << endl << cBuffer << endl;
    free(cBuffer);
    fclose(fp);
}