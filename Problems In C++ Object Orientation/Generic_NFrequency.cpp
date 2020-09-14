/*
*   Program to find occurances of particular elements from N elements
*/

#include <iostream>
#include <string.h>
#include <stdio.h>

#define MAXLEN      10

using namespace std;

template<class T>
int NOccurances(T*, int, T);

int main()
{
    int iN, *iArr = NULL, iRet = 0, i = 0, iVal;
    float *fArr = NULL, fVal;
    char *cArr = NULL, cVal;
    char command[MAXLEN] = {'\0'};

    while(true)
    {
        cout << "\nGeneric Programming :>";
        fflush(stdin);
        scanf("%s", command);
        if(strcasecmp(command, "int") == 0)
        {
            cout << "Enter number of elements\t\t:";
            cin >> iN;
            iArr = new int[iN];
            cout << "Enter elements\n";
            for(i = 0; i < iN; i++)
            {
                cin >> iArr[i];
            }
            cout << "Enter number to be searched\t\t:";
            cin >> iVal;
            iRet = NOccurances(iArr, iN, iVal);
            if(iRet != -1)
            {
                cout << "Number of Occurances of " << iVal << "\t\t:"  << iRet << endl;
            }
            else
            {
                cout << "Element not found\n";
            }
            delete[] iArr;
        }
        else if(strcasecmp(command, "float") == 0)
        {
            cout << "Enter number of elements\t\t:";
            cin >> iN;
            if(iN < 0)
                iN = -iN;
            fArr = new float[iN];
        
            cout << "Enter elements\n";
            for(i = 0; i < iN; i++)
            {
                cin >> fArr[i];
            }
            cout << "Enter float number to be searched\t:";
            cin >> fVal;
            iRet = NOccurances(fArr, iN, fVal);
            if(iRet != -1)
            {
                cout << "Number of Occurances of " << fVal << "\t\t:" << iRet << endl;
            }
            else
            {
                cout << "Element not found\n";
            }
            delete[] fArr;
        }
        else if(strcasecmp(command, "char") == 0)
        {
            cout << "Enter number of elements\t\t:";
            cin >> iN;
            if(iN < 0)
                iN = -iN;
            cArr = new char[iN]; 
            cout << "Enter elements\n";
            for(i = 0; i < iN; i++)
            {
                cin >> cArr[i];
            }

            cout << "Enter character to be searched\t\t:";
            cin >> cVal;  
            iRet = NOccurances(cArr, iN, cVal);
            if(iRet != -1)
            {
                cout << "Number of Occurances of " << cVal << "\t\t:" << iRet << endl;
            }
            else
            {
                cout << "Element not found\n";
            }
            delete[] cArr;
        }
        else if(strcasecmp(command, "exit") == 0)
        {
            break;
        }        
        else if(strcasecmp(command, "clear") == 0)
        {
            system("clear");
        }
    }
    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :NOccurances
//  Input       :T[], int, T
//  Returns     :T
//  Description :Counts number of occurances of particular element
//  Author      :Pranav Choudhary
//  Date        :14 Sept 2020
//
///////////////////////////////////////////////////////////////////
template<class T>
int NOccurances(T tArr[], int iN, T tVal)
{
    if(tArr == NULL)
    {
        cout << "Invalid Input\n";
    }
    int i = 0, iCnt = 0;
    for(i = 0; i < iN; i++)
    {
        if(tArr[i] == tVal)
        {
           iCnt++;
        }
    }
    if(iCnt == 0)
    {
        return -1;
    }
    else
    {
        return iCnt;
    }    
}