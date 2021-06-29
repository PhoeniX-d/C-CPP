/*
*   Program to find maximum of N elements
*/

#include<iostream>
using namespace std;

template<class T>
T ArrayMax(T*, int);

int main()
{
    int iN, *iArr = NULL, iRet = 0, i = 0;
    float *fArr = NULL, fRet = 0;
    cout << "Enter number of elements\t:";
    cin >> iN;
    iArr = new int[iN];

    cout << "Enter elements\n";
    for(i = 0; i < iN; i++)
    {
        cin >> iArr[i];
    }

    iRet = ArrayMax(iArr, iN);
    cout << "Maximum of Array is\t\t:" << iRet << endl;

    cout << "Enter number of elements\t:";
    cin >> iN;
    if(iN < 0)
        iN = -iN;
    fArr = new float[iN];
    
    cout << "Enter elements\n";
    for(i = 0; i < iN; i++)
    {
        cin >> fArr[i];
    }

    fRet = ArrayMax(fArr, iN);
    cout << "Maximum of Array is\t\t:" << fRet << endl;

    delete[] iArr;
    delete[] fArr;

    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :ArrayMax
//  Input       :T[], int
//  Returns     :T
//  Description :Computes Maximum of N elements
//  Author      :Pranav Choudhary
//  Date        :14 Sept 2020
//
///////////////////////////////////////////////////////////////////
template<class T>
T ArrayMax(T tArr[], int iN)
{
    if(tArr == NULL)
    {
        cout << "Invalid Input\n";
    }
    int i = 0;
    T tMax = tArr[0];

    for(i = 0; i < iN; i++)
    {
        if(tMax < tArr[i])
        {
            tMax = tArr[i];
        }
    }
    return tMax;
}