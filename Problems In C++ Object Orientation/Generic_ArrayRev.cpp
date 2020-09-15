/*
*   Write generic program to accept N values and reverse the contents.
*   Input : 10 20 30 10 30 40 10 40 10
*   Output : 10 40 10 40 30 10 30 20 10
*/
#include <iostream>

using namespace std;

template <class T>
void ArrayRev(T[], int);
template <class T>
void DisplayArray(T[], int);

int main()
{
    int iN = 0, *iArr = NULL, i = 0;
    float *fArr = NULL;
    char *cArr = NULL;

    cout << "Enter number of elements\t:";
    cin >> iN;
    iArr = new int[iN];
    cout << "Enter integer elements\n";
    for (i = 0; i < iN; i++)
    {
        cin >> iArr[i];
    }
    cout << "Original Array\n";
    DisplayArray(iArr, iN);
    ArrayRev(iArr, iN);
    cout << "After reverse\n";
    DisplayArray(iArr, iN);
    delete[] iArr;

    cout << "Enter number of elements\t:";
    cin >> iN;
    fArr = new float[iN];
    cout << "Enter float elements\n";
    for (i = 0; i < iN; i++)
    {
        cin >> fArr[i];
    }
    cout << "Original Array\n";
    DisplayArray(fArr, iN);
    ArrayRev(fArr, iN);
    cout << "After reverse\n";
    DisplayArray(fArr, iN);
    delete[] fArr;

    cout << "Enter number of elements\t:";
    cin >> iN;
    cArr = new char[iN];
    cout << "Enter char elements\n";
    for (i = 0; i < iN; i++)
    {
        cin >> cArr[i];
    }
    cout << "Original Array\n";
    DisplayArray(cArr, iN);
    ArrayRev(cArr, iN);
    cout << "After reverse\n";
    DisplayArray(cArr, iN);
    delete[] cArr;

    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :ArrayRev
//  Input       :T[], int, T
//  Returns     :T
//  Description :Finds first occurances of particular element
//  Author      :Pranav Choudhary
//  Date        :15 Sept 2020
//
///////////////////////////////////////////////////////////////////
template <class T>
void ArrayRev(T tArr[], int iN)
{
    if(NULL == tArr)
    {
        cout << "Invalid Inputs";
    }
    T tTemp;
    for(int i = 0, j = iN - 1; i < j; i++, j--)
    {
        tTemp = tArr[i];
        tArr[i] = tArr[j];
        tArr[j] = tTemp;
    }
}

///////////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :T[], int
//  Returns     :T
//  Description :Displays Array elements
//  Author      :Pranav Choudhary
//  Date        :15 Sept 2020
//
///////////////////////////////////////////////////////////////////
template <class T>
void DisplayArray(T tArr[], int iN)
{
    if(NULL == tArr)
    {
        cout << "Invalid Inputs";
    }
    for(int i = 0; i < iN; i++)
    {
        cout << tArr[i] << " ";
    }
    cout << endl;
}