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
        void PrintPattern6();
        void PrintPattern7();
        void PrintPattern8();
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
//              * * * * *
//              *       *
//              *       *
//              * * * * *
//	Author		:Pranav Choudhary
//	Date		:18 August 2020
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
            if(j == 1 || i == 1 || j == iCol || i == iRow)
                cout << "* ";
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
//                *       * * * * *
//                *       *
//                *       *
//                *       *
//                * * * * * * * * *
//                        *       *
//                        *       *
//                        *       *
//                * * * * *       *
//	Author		:Pranav Choudhary
//	Date		:18 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern2()
{
    int i = 0, j = 0, iRange = 0;
    Updater(this->iRow, this->iCol);
    /* way 1 */
    iRange = (iRow * 2) + 1;
    for (i = 1; i <= iRange; i++)
    {
        for (j = 1; j <= iRange; j++)
        {
            if(i == iRow + 1 || j == iCol + 1 || 
                i <= iRow + 1 && j == 1 || 
                j >= iCol + 1 && i == 1 ||
                i == iRange && j <= iCol + 1||
                j == iRange && i >= iRow + 1                
                )
                cout << "* ";
            else
                cout << "  ";
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
//               * * * * *
//               *     * 
//               *   * 
//               * *  
//               *  
//	Author		:Pranav Choudhary
//	Date		:18 August 2020
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
            if(j + i == iRow + 1 || i == 1 || j == 1)
                cout << "* ";
            else
                cout << "  ";
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
//                       *
//                     * * *
//                   * * * * *
//                 * * * * * * *
//               * * * * * * * * *
//	Author		:Pranav Choudhary
//	Date		:19 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern4()
{
    int i = 0, j = 0, iRange = 0;
    Updater(this->iRow, this->iCol);
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1; j <= iRange; j++)
		{
			if(j >= iCol - i + 1 && j <= iCol + i -1)
			{
				cout<<"* ";
			}
			else
			{
				cout <<"  ";
			}
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
//              * * * * * * * * *
//                * * * * * * *
//                  * * * * *
//                    * * *
//                      *
//	Author		:Pranav Choudhary
//	Date		:19 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern5()
{
    int i = 0, j = 0, iRange = 0;
    Updater(this->iRow, this->iCol);
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1; j <= iRange; j++)
		{
			if(j >= i && j <= iRange - i + 1)
			{
				cout<<"* ";
			}
			else
			{
				cout <<"  ";
			}
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
//                       *
//                     *   *
//                   *       *
//                 *           *
//               * * * * * * * * *
//	Author		:Pranav Choudhary
//	Date		:19 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern6()
{
    int i = 0, j = 0, iRange = 0;
    Updater(this->iRow, this->iCol);
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1; j <= iRange; j++)
		{
			if(j == iCol - i + 1 || j == iCol + i -1 || i == iRow)
			{
				cout<<"* ";
			}
			else
			{
				cout <<"  ";
			}
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
//						1
//					  2 3 2
//					3 4 5 4 3
//				  4 5 6 7 6 5 4
//				5 6 7 8 9 8 7 6 5
//	Author		:Pranav Choudhary
//	Date		:19 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern7()
{
    int i = 0, j = 0, iRange = 0, k = 0;
    Updater(this->iRow, this->iCol);
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		k = i;
		for(j = 1; j <= iRange; j++)
		{
			if(j >= iCol - i + 1 && j <= iCol + i - 1)
			{
				cout<< k << " ";
				if(j < iCol)
				{
					k++;
				}
				else if(j >= iCol)
				{
					--k;
				}
			}
			else
			{
				cout <<"  ";
			}
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
//						1
//					  1   2
//					1       3
//				  1	          4
//				1	2   3   4   5
//	Author		:Pranav Choudhary
//	Date		:19 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern8()
{
    int i = 0, j = 0, iRange = 0, k = 0;
    Updater(this->iRow, this->iCol);
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		k = i;
		for(j = 1, k = 1; j <= iRange; j++)
		{
			if(j == iCol - i + 1)
			{
				cout << k << " ";
				k++;
			}
			else if(j == iCol + i - 1)
			{
				cout << i << " ";
			}
			else if(i == iRow && j % 2 != 0)
			{
				cout << k++ << " ";
			}
			else
			{
				cout <<"  ";
			}
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
    cout << "\n-----Pattern 6-----\n";
    pObj.PrintPattern6(); 
    cout << "\n-----Pattern 7-----\n";
    pObj.PrintPattern7();
    cout << "\n-----Pattern 8-----\n";
    pObj.PrintPattern8();
    return 0;
}