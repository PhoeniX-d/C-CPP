/*
*   Write generic program to accept N values and search first occurrence of any
*   specific value.
*   Input : 10 20 30 10 30 40 10 40 10 
*   Value to search : 40
*   Output : 6
*/
#include <iostream>
#include <string.h>

using namespace std;

template <class T>
int FirstOccur(T[], int, T);

int main()
{
    int iN = 0, *iArr = NULL, iRet = 0, i = 0, iVal;
    float *fArr = NULL, fVal;
    char *cArr = NULL, cVal;

    cout << "Enter number of elements\t:";
    cin >> iN;
    iArr = new int[iN];
    cout << "Enter integer elements\n";
    for (i = 0; i < iN; i++)
    {
        cin >> iArr[i];
    }
    cout << "Enter number to be searched\t:";
    cin >> iVal;
    iRet = FirstOccur(iArr, iN, iVal);
    if (iRet != -1)
    {
        cout << "First Occurances of " << iVal << "\t\t:at Index " << iRet << endl;
    }
    else
    {
        cout << "Element not found\n";
    }
    delete[] iArr;

    cout << "Enter number of elements\t:";
    cin >> iN;
    if (iN < 0)
        iN = -iN;
    fArr = new float[iN];

    cout << "Enter float elements\n";
    for (i = 0; i < iN; i++)
    {
        cin >> fArr[i];
    }
    cout << "Enter float number to be searched\t:";
    cin >> fVal;
    iRet = FirstOccur(fArr, iN, fVal);
    if (iRet != -1)
    {
        cout << "First Occurances of " << fVal << "\t\t:at Index " << iRet << endl;
    }
    else
    {
        cout << "Element not found\n";
    }
    delete[] fArr;

    cout << "Enter number of elements\t:";
    cin >> iN;
    if (iN < 0)
        iN = -iN;
    cArr = new char[iN];
    cout << "Enter char elements\n";
    for (i = 0; i < iN; i++)
    {
        cin >> cArr[i];
    }

    cout << "Enter character to be searched\t:";
    cin >> cVal;
    iRet = FirstOccur(cArr, iN, cVal);
    if (iRet != -1)
    {
        cout << "First Occurances of " << cVal << "\t\t:at Index " << iRet << endl;
    }
    else
    {
        cout << "Element not found\n";
    }
    delete[] cArr;

    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :T[], int, T
//  Returns     :T
//  Description :Finds first occurances of particular element
//  Author      :Pranav Choudhary
//  Date        :15 Sept 2020
//
///////////////////////////////////////////////////////////////////
template <class T>
int FirstOccur(T tArr[], int iN, T tVal)
{
    if (tArr == NULL)
    {
        cout << "Invalid Input\n";
    }
    int i = 0;
    for (i = 0; i < iN; i++)
    {
        if (tArr[i] == tVal)
        {
            break;
        }
    }
    if (i == iN)
    {
        return -1;
    }
    else
    {
        return i;
    }
}