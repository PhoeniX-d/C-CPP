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
            if(i < 0)
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
};// end of class Array

// class ArraySearch
class ArraySearch:public Array
{
    private:
        bool IsSorted()
        {
            int i = 0;
            for (i = 0; i < this->iSize - 1; i++)
            {
                if(this->iArr[i] > this->iArr[i + 1])
                {
                    break;
                }
            }
            if(i == this->iSize - 1)
            {
                return true;
            }
            else
            {
                return false;
            }            
        }

    public:
        ArraySearch(int i = 7):Array(i)     /* Base Member Initialization */
        {}

        /* Utility functions */
        int LinearSearch(int);
        int LinearSearchX(int);
        int BinarySearch(int);
};// end of class ArraySearch

///////////////////////////////////////////////////////////////////
//
//  Name        :Accept
//  Input       :void
//  Returns     :void
//  Description :Accepts N elements from user (through constructor)
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
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
}

///////////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :Displays Array elemets
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
//
///////////////////////////////////////////////////////////////////
void Array::Display()   /* Display(const Array *this) */
{
    if(this->iArr == NULL)
    {
        cout << "Array is empty\n";
        return;
    }
    cout << "[ ";
    for (int i = 0; i < this->iSize; i++)
    {
       cout << this->iArr[i] << " ";
    }
    cout << "]" << endl;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :LinearSearch
//  Input       :int
//  Returns     :int
//  Description :Performs LinearSearch on array for iNum
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::LinearSearch(int iNum)    /* LinearSearch(ArraySearch const *this, int) */
{
    if(NULL == this->iArr)
    {
        cout << "Array is empty\n";
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
    
}// end of LinearSearch()

///////////////////////////////////////////////////////////////////
//
//  Name        :LinearSearchX
//  Input       :int
//  Returns     :bool
//  Description :Performs LinearSearch on array for iNum
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::LinearSearchX(int iNum)    /* LinearSearch(ArraySearch const *this, int) */
{
    if(NULL == this->iArr)
    {
        cout << "Array is empty\n";
        return EMPTY;
    }

    int i = 0, j = this->iSize - 1;
    while(i < j)
    {
        if(this->iArr[i] == iNum || this->iArr[j] == iNum)
        {
            break;
        }
        i++;
        j--;
    }
    if(i >= j)
    {
        return NOTFOUND;
    }
    else
    {
        if(this->iArr[i] == iNum)
            return i;
        else if(this->iArr[j] == iNum)
            return j;
    }
    return NOTFOUND;
}// end of LinearSearchX()

///////////////////////////////////////////////////////////////////
//
//  Name        :BinarySearch
//  Input       :int
//  Returns     :int
//  Description :Performs LinearSearch on array for iNum
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
//
///////////////////////////////////////////////////////////////////
int ArraySearch::BinarySearch(int iNum)    /* BinarySearch(ArraySearch const *this, int) */
{
    if(NULL == this->iArr)
    {
        cout << "Array is empty\n";
        return EMPTY;
    }
    int iMid = 0, iBeg = 0, iEnd = 0;
    bool bRet = false;
    iEnd = this->iSize;
    iMid = (iBeg + iEnd) / 2;
    bRet = IsSorted();
    if(bRet == false)
    {
        return LinearSearchX(iNum);
    }
    while(iBeg <= iEnd)
    {
        iMid = (iBeg + iEnd) / 2;
        if(this->iArr[iMid] == iNum)
        {
            break;
        }
        if(this->iArr[iMid] > iNum)
        {
            iEnd = iMid - 1;
        }
        else if(this->iArr[iMid] < iNum)
        {
            iBeg = iMid + 1;
        }        
    }
    if(this->iArr[iMid] == iNum)
    {
        return iMid;
    }
    else
    {
        return NOTFOUND;
    }   

}// end of BinarySearch()

// Entry point
int main()
{
    int iValue = 0, iRet = 0;
    bool bRet = false;
    cout << "\nEnter no. of elements\n";
    cin >> iValue;
    ArraySearch *pArraySearch = new ArraySearch(iValue);

    cout << "\nEnter elemnets\n";
    pArraySearch->Accept(); /* Accept(pArraySearch); */

    cout << "\nArray 2 elements\n";
    pArraySearch->Display(); /* Display(pArraySearch); */

    /* LinearSearch : Performs LinearSearch on Array 
    cout << "----------------------------------------------------------------------\n";
    cout << "Enter value for LinearSearch\t:";
    cin >> iValue;
    iRet = pArraySearch->LinearSearch(iValue);
    if(iRet == true)
    {
        cout << "Element found in Array\t\t:" << iRet << endl;
    }
    else
    {
        cout << "Element not present in Array\n";
    }

    /* LinearSearchX : Performs LinearSearch on Array in less complexity 
    cout << "----------------------------------------------------------------------\n";
    cout << "Enter value for LinearSearchX\t:";
    cin >> iValue;
    iRet = pArraySearch->LinearSearchX(iValue);
    if(iRet == EMPTY)
    {
        cout << "Array Is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not present in Array\n";
    }
    else
    {
        cout << "Element found in Array\t\t:" << iRet << endl;
    }

    /* BinarySearch : Performs BinarySearch on Array */
    cout << "----------------------------------------------------------------------\n";
    cout << "Enter value for BinarySearch\t:";
    cin >> iValue;
    iRet = pArraySearch->BinarySearch(iValue);
    if(iRet == EMPTY)
    {
        cout << "Array Is Empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not present in Array\n";
    }
    else
    {
        cout << "Element found in Array\t\t:" << iRet << endl;
    }

    cout << "----------------------------------------------------------------------\n";
    delete pArraySearch;
    return 0;
}