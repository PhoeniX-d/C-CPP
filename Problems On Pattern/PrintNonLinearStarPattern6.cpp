/*
*   Program to print designated star patterns
*/
#include<iostream>
#include<iomanip>

using namespace std;
class Pattern
{
    private:
        int iRow;
    
    public:
        Pattern(int iRows)
        {
            iRow = iRows;
        }
        void Updater(int);
        void PrintPattern1();
        void PrintPattern2();
        void PrintPattern3();
        void PrintPattern4();
        void PrintPattern5();
        void PrintPattern6();
        void PrintPattern7();
        void PrintPattern8();
};

////////////////////////////////////////////////////////////////////////
//
//	Name		:Updater
//	Input		:int
//	Returns		:void
//	Description	:Updates Wrong inputs
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::Updater(int iRow)
{
    if(this->iRow < 0)
        this->iRow = -this->iRow; 
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                       1
//                     1 1 1
//                   1 0 1 0 1
//                 1 0 0 1 0 0 1
//               1 0 0 0 1 0 0 0 1
//             1 1 1 1 1 1 1 1 1 1 1
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern1()
{
    int i = 0, j = 0;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= iRow; j++)
        {
            if(j == iRow || i == iRow || j == iRow - i + 1)
                cout << "1 ";
            else if(j > iRow - i + 1)
                cout << "0 ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern2
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                  1
//                  1 0
//                  1 0 3
//                  1 0 3 0
//                  1 0 3 0 5
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern2()
{
    int i = 0, j = 0;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(j % 2 != 0)
                cout << setw(2) << j << " ";
            else
                cout << " 0 ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern3
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                1
//                1 2
//                1 0 3
//                1 0 0 4
//                1 0 0 0 5
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern3()
{
    int i = 0, j = 0;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(i == j || j == 1)
                cout << setw(2) << j << " ";
            else
                cout << " 0 ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern4
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                1
//                1 1
//                1 0 1
//                1 0 0 1
//                1 0 0 0 1
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern4()
{
    int i = 0, j = 0;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(i == j || j == 1)
                cout << " 1 ";
            else
                cout << " 0 ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern5
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                1
//                2 2
//                3 3 3
//                4 4 4 4
//                5 5 5 5 5
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern5()
{
    int i = 0, j = 0;
    Updater(this->iRow);
    for (i = 1; i <= iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
            cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern6
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                1
//                1 2
//                1 2 3
//                1 2 3 4
//                1 2 3 4 5
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern6()
{
    int i = 0, j = 0;
    Updater(this->iRow);
    for (i = 1; i <= iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
            cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern7
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//               1
//               2  3
//               4  5  6
//               7  8  9  10
//               11 12 13 14 15
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern7()
{
    int i = 0, j = 0, iNum = 1;
    Updater(this->iRow);
    for (i = 1; i <= iRow; i++)
    {
        for (j = 1; j <= i; j++, iNum++)
        {
            cout << setw(2) << iNum << " ";
        }
            cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern8
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                  1
//                  4  9
//                  16 25 36
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern8()
{
    int i = 0, j = 0, iNum = 1;
    Updater(this->iRow);
    for (i = 1; i <= iRow; i++)
    {
        for (j = 1; j <= i; j++, iNum++)
        {
            cout << setw(3) << iNum * iNum << " ";
        }
            cout << endl;
    }
}

int main()
{
    int iValue1 = 0, iValue2 = 0;
    cout << "Enter the number of rows\n";
    cin >> iValue1;

    Pattern pObj(iValue1);
    cout << "\n-----Pattern 1-----\n";
    pObj.PrintPattern1();
    /*cout << "\n-----Pattern 2-----\n";
    pObj.PrintPattern2();
    cout << "\n-----Pattern 3-----\n";
    pObj.PrintPattern3();
    cout << "\n-----Pattern 4-----\n";
    pObj.PrintPattern4();    
    cout << "\n-----Pattern 5-----\n";
    pObj.PrintPattern5();
    cout << "\n-----Pattern 6-----\n";
    pObj.PrintPattern6();
    cout << "\n-----Pattern 7-----\n";
    pObj.PrintPattern7();
    cout << "\n-----Pattern 8-----\n";
    pObj.PrintPattern8();*/

    return 0;
}