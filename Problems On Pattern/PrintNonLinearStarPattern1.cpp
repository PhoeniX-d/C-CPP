/*
*   Program to print designated star patterns
*/
#include<iostream>
using namespace std;
class Pattern
{
    private:
        int iRow;
        int iCol;
    
    public:
        Pattern(int iRows, int iCols)
        {
            iRow = iRows;
            iCol = iCols;
        }
        void Updater(int, int);
        void PrintPattern1();
        void PrintPattern2();
        void PrintPattern3();
        void PrintPattern4();
        void PrintPattern5();
};

////////////////////////////////////////////////////////////////////////
//
//	Name		:Updater
//	Input		:void
//	Returns		:void
//	Description	:Updates Wrong inputs
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::Updater(int iRow, int iCol)
{
    if(this->iRow < 0)
        this->iRow = -this->iRow;
    if(this->iCol < 0)
        this->iCol = -this->iCol;    
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                 * # # #
//                 * * # #
//                 * * * #
//                 * * * *
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern1()
{
    int i = 0, j = 0;
    Updater(this->iRow, this->iCol);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= this->iCol; j++)
        {
            if(j <= i)
                cout << "* ";
            else
                cout << "# ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                 * * * *
//                 * * * #
//                 * * # #
//                 * # # #
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern2()
{
    int i = 0, j = 0;
    Updater(this->iRow, this->iCol);
    /* way 1 */
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= this->iCol; j++)
        {
            if(j <= iRow - i + 1)
                cout << "* ";
            else
                cout << "# ";
        }
        cout << endl;
    }

    /* way 2
    for (i = this->iRow; i >= 1; i--)
    {
        for (j = 1; j <= this->iCol; j++)
        {
            if(j <= i)
                cout << "* ";
            else
                cout << "# ";
        }
        cout << endl;
    }
    */
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                 $ * * * *
//                 * $ * * *
//                 * * $ * *
//                 * * * $ *
//                 * * * * $
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern3()
{
    int i = 0, j = 0;
    Updater(this->iRow, this->iCol);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= this->iCol; j++)
        {
            if(j == i)
                cout << "$ ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                 * * * * *
//                 * @ @ @ *
//                 * @ @ @ *
//                 * @ @ @ *
//                 * @ @ @ *
//                 * * * * *
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern4()
{
    int i = 0, j = 0;
    Updater(this->iRow, this->iCol);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= this->iCol; j++)
        {
            if(j == 1 || i == 1 || i == iRow || j == iCol)
                cout << "* ";
            else
                cout << "@ ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//               1 2 3 4
//               1 * * 4
//               1 * * 4
//               1 2 3 4
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern5()
{
    int i = 0, j = 0;
    Updater(this->iRow, this->iCol);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= this->iCol; j++)
        {
            if(j == 1 || i == 1 || i == iRow || j == iCol)
                cout << j << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int iValue1 = 0, iValue2 = 0;
    cout << "Enter the number of rows\n";
    cin >> iValue1;
    cout << "Enter the number of columns\n";
    cin >> iValue2;

    Pattern pObj(iValue1, iValue2);
    cout << "\n-----Pattern 1-----\n";
    pObj.PrintPattern1();
    cout << "\n-----Pattern 2-----\n";
    pObj.PrintPattern2();
    cout << "\n-----Pattern 3-----\n";
    pObj.PrintPattern3();
    cout << "\n-----Pattern 4-----\n";
    pObj.PrintPattern4();    
    cout << "\n-----Pattern 5-----\n";
    pObj.PrintPattern5(); 
    return 0;
}