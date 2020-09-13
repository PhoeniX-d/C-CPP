// Header files
#include<iostream>
using namespace std;

/* Error Code */
#define     NOTFOUND        0x11111111
#define     EMPTY           0x11111110

class Array
{
    protected:
        int *iArr;
        int iSize;
    
    public:
        Array(int i = 10)       /* Parameterized constructor:Memory allocation */
        {
            if (i < 0)
                i = -i;

            this->iSize = i;
            this->iArr = new int[this->iSize];
        }

        Array(Array &Ref)       /* Copy constructor : Memory content copy */
        {
            /* First allocate memory */
            this->iSize = Ref.iSize;
            this->iArr = new int[this->iSize];

            /* Now copying contents */
            for (int i = 0; i < this->iSize; i++)
            {
                this->iArr[i] = Ref.iArr[i];
            }
        }

        ~Array()                /* Destructor: Memory deallocation */
        {
            delete[] this->iArr;
        }

        /* Utility functions */
        inline void Accept();
        inline void Display();
};

// class ArraySearch
class ArraySearch : public Array
{
    public:
        ArraySearch(int i = 7):Array(i)     /* Base Member initialization */
        {}

        /* Utility functions */
        int Occurances(int);
        int FirstOccur(int);
        int SecOccur(int);
        int LastOccur(int);
        int SecLastOccur(int);
        int EvenCount();
        int OddCount();
};

///////////////////////////////////////////////////////////////////
//
//  Name        :Accept
//  Input       :void
//  Returns     :void
//  Description :Accepts N elements from user (through constructor)
//  Author      :Pranav Choudhary
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
void Array::Accept()    /* Accept(const Array *this) */
{
    if(this->iArr == NULL)
    {
        cout << "Array is empty\n";
        return;
    }
    
    for (int i = 0; i < this->iSize; i++)
    {
        cin >> this->iArr[i];
    }
}// end of Accept()

///////////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :Displays Array elemets
//  Author      :Pranav Choudhary
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
void Array::Display()   /* Display(const Array *this) */
{
    if(this->iArr == NULL)
    {
        cout << "Array is empty\n";
        return;
    }
    for (int i = 0; i < this->iSize; i++)
    {
       cout << "[ " << this->iArr[i] << " ]";
    }
    cout << "\n\n";
} // end of Display()

///////////////////////////////////////////////////////////////////
//
//  Name        :Occurances
//  Input       :int
//  Returns     :int
//  Description :Searches all occurance of particular number
//  Author      :Pranav Choudhary
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::Occurances(int iNum)    /* Occurances(const ArraySearch *this, int)*/
{
    if(this->iArr == NULL)
    {
        return EMPTY;
    }
    int iCnt = 0;
    for (int i = 0; i < this->iSize; i++)
    {
        if(this->iArr[i] == iNum)
        {
            iCnt++;
        }
    }
    if(iCnt == 0)
    {
        return NOTFOUND;
    }
    else
    {
        return iCnt;
    }
}// end of Occurances()

///////////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :int
//  Returns     :int
//  Description :Searches first occurance of particular number
//  Author      :Pranav Choudhary
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::FirstOccur(int iNum)    /* FirstOccur(const ArraySearch *this, int)*/
{
    if(this->iArr == NULL)
    {
        return EMPTY;
    }
    int i = 0;
    for (i = 0; i < this->iSize; i++)
    {
        if(this->iArr[i] == iNum)
        {
            break;
        }
    }
    if(i == this->iSize)
    {
        return NOTFOUND;
    }
    else
    {
        return i;
    }
}// end of FirstOccur()

///////////////////////////////////////////////////////////////////
//
//  Name        :SecOccur
//  Input       :int
//  Returns     :int
//  Description :Searches first occurance of particular number
//  Author      :Pranav Choudhary
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::SecOccur(int iNum)    /* SecOccur(const ArraySearch *this, int)*/
{
    if(this->iArr == NULL)
    {
        return EMPTY;
    }
    int i = 0, iPos = -1, iCnt = 0;
    for (i = 0; i < this->iSize; i++)
    {
        if(this->iArr[i] == iNum)
        {
            iCnt++;
            if(iCnt == 1 || iCnt == 2)
            {
                iPos = i;
            }
        }
    }
    if(iPos == -1)
    {
        return NOTFOUND;
    }
    else
    {
        return iPos;
    }
}// end of SecOccur()

///////////////////////////////////////////////////////////////////
//
//  Name        :LastOccur
//  Input       :int
//  Returns     :int
//  Description :Searches first occurance of particular number
//  Author      :Pranav Choudhary
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::LastOccur(int iNum)  /* LastOccur(const ArraySearch *this, int)*/
{
    if(this->iArr == NULL)
    {
        return EMPTY;
    }
    int iPos = -1, i = 0;
    for (i = 0; i < this->iSize; i++)
    {
        if(this->iArr[i] == iNum)
        {
            iPos = i;
        }
    }
    if(iPos == -1)
    {
        return NOTFOUND;
    }
    else
    {
        return iPos;
    }
}// end of LastOccur()

///////////////////////////////////////////////////////////////////
//
//  Name        :SecLastOccur
//  Input       :int
//  Returns     :int
//  Description :Searches second last occurance of particular number
//  Author      :Pranav Choudhary
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::SecLastOccur(int iNum)  /* SecLastOccur(const ArraySearch *this, int)*/
{
    if(this->iArr == NULL)
    {
        return EMPTY;
    }
    int iPos1 = -1, iPos2 = -1, i = 0;
    for (i = 0; i < this->iSize; i++)
    {
        if(this->iArr[i] == iNum)
        {
            iPos2 = iPos1;
            iPos1 = i;
        }
    }
    if(iPos1 == -1)
    {
        return NOTFOUND;
    }
    else if(iPos2 == -1)
    {
        return iPos1;
    }
    else
    {
        return iPos2;
    }
}// end of SecLastOccur()

///////////////////////////////////////////////////////////////////
//
//  Name        :EvenCount
//  Input       :void
//  Returns     :int
//  Description :Returns total number of even numbers in Array
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::EvenCount()  /* EvenCount(const ArraySearch *this)*/
{
    if(this->iArr == NULL)
    {
        return EMPTY;
    }
    int iECnt = 0, i = 0;
    for (i = 0; i < this->iSize; i++)
    {
        if(this->iArr[i] % 2 == 0)
        {
            iECnt++;
        }
    }
    if(iECnt == 0)
    {
        return NOTFOUND;
    }
    else
    {
        return iECnt;
    }
}// end of EvenCount()

///////////////////////////////////////////////////////////////////
//
//  Name        :OddCount
//  Input       :void
//  Returns     :int
//  Description :Returns total number of odd numbers in Array
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::OddCount()  /* OddCount(const ArraySearch *this)*/
{
    if(this->iArr == NULL)
    {
        return EMPTY;
    }
    int iOCnt = 0, i = 0;
    for (i = 0; i < this->iSize; i++)
    {
        if(this->iArr[i] % 2 != 0)
        {
            iOCnt++;
        }
    }
    if(iOCnt == 0)
    {
        return NOTFOUND;
    }
    else
    {
        return iOCnt;
    }
}// end of OddCount()

// Entry point
int main()
{
    int iValue = 0, iRet = 0;
    cout << "\nEnter no. of elements\n";
    cin >> iValue;
    ArraySearch *pArraySearch = new ArraySearch(iValue);
    cout << "\nEnter elemnets\n";
    pArraySearch->Accept(); /* Accept(pArraySearch); */
    cout << "\nArray 1 elements\n";
    pArraySearch->Display(); /* Display(pArraySearch); */
    
    /* Occurances: Searches all occurances of iNum */
    cout << "---------------------------------------------------------------\n";
    cout << "Enter value to be searched\t\t:";
    cin >> iValue;
    iRet = pArraySearch->Occurances(iValue);
    if(iRet == EMPTY)
    {
        cout << "Array is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "No. of Occurances of " << iValue << "\t\t\t:" << iRet << endl;
    }

    /* FirstOccur: Searches first occurances of iNum */
    cout << "---------------------------------------------------------------\n";
    cout << "Enter value for first occur\t\t:";
    cin >> iValue;
    iRet = pArraySearch->FirstOccur(iValue);
    if(iRet == EMPTY)
    {
        cout << "Array is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "First of Occurances of " << iValue << "\t\t:at Index " << iRet << endl;
    }

    /* SecOccur: Searches second occurances of iNum */
    cout << "---------------------------------------------------------------\n";
    cout << "Enter value for second occur\t\t:";
    cin >> iValue;
    iRet = pArraySearch->SecOccur(iValue);
    if(iRet == EMPTY)
    {
        cout << "Array is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Second of Occurances of " << iValue << "\t\t:at Index " << iRet << endl;
    }

    /* LastOccur: Searches last occurances of iNum */
    cout << "---------------------------------------------------------------\n";
    cout << "Enter value for last occur\t\t:";
    cin >> iValue;
    iRet = pArraySearch->LastOccur(iValue);
    if(iRet == EMPTY)
    {
        cout << "Array is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Last of Occurances of " << iValue << "\t\t\t:at Index " << iRet << endl;
    }
    
    /* SecLastOccur: Searches second last occurances of iNum */
    cout << "---------------------------------------------------------------\n";
    cout << "Enter value for second last occur\t:";
    cin >> iValue;
    iRet = pArraySearch->SecLastOccur(iValue);
    if(iRet == EMPTY)
    {
        cout << "Array is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Second Last of Occurances of " << iValue << "\t\t:at Index " << iRet << endl;
    }

    /* EvenCount: Counts even number in array */
    cout << "---------------------------------------------------------------\n";
    iRet = pArraySearch->EvenCount();
    if(iRet == EMPTY)
    {
        cout << "Array is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Doesn't have even numbers\n";
    }
    else
    {
        cout << "Total even numbers in array are " << "\t:"<< iRet << endl;
    }

    /* OddCount: Counts odd number in array */
    cout << "---------------------------------------------------------------\n";
    iRet = pArraySearch->OddCount();
    if(iRet == EMPTY)
    {
        cout << "Array is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Doesn't have odd numbers\n";
    }
    else
    {
        cout << "Total odd numbers in array are " << "\t\t:"<< iRet << endl;
    }

    /* deallocate pointer */
    delete pArraySearch;
    cout << "---------------------------------------------------------------\n";
    return 0;
}