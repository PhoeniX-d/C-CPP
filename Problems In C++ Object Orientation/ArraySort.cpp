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

// class ArraySort
class ArraySort:public Array
{
    public:
        ArraySort(int i = 7):Array(i)     /* Base Member Initialization */
        {}

        /* Utility functions */
        void BubbleSort();
        void BubbleSortX();
        void SelectionSort();
        void InsertionSort();
        void QuickSort();
        void MergeSort();
};// end of class ArraySort

///////////////////////////////////////////////////////////////////
//
//  Name        :Accept
//  Input       :void
//  Returns     :void
//  Description :Accepts N elements from user (through constructor)
//  Author      :Pranav Choudhary
//  Date        :17 Sept 2020
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
//  Date        :17 Sept 2020
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
//  Name        :BubbleSort
//  Input       :void
//  Returns     :void
//  Description :Sorts elements using bubblesort technique
//  Author      :Pranav Choudhary
//  Date        :17 Sept 2020
//
///////////////////////////////////////////////////////////////////
void ArraySort::BubbleSort()       /* BubbleSort(ArraySort const *this) */
{
    if(NULL == this->iArr)
    {
        cout << "Array Is Empty\n";
        return;
    }
    int iPass = 0, i = 0, iTemp = 0;
    for (iPass = 1; iPass < this->iSize; iPass++)
    {
        for (i = 0; i < this->iSize - iPass; i++)
        {
            if(this->iArr[i] > this->iArr[i + 1])
            {
                iTemp = this->iArr[i];
                this->iArr[i] = this->iArr[i + 1];
                this->iArr[i + 1] = iTemp;
            }
        }
    }
}// end of BubbleSort()

///////////////////////////////////////////////////////////////////
//
//  Name        :BubbleSortX
//  Input       :void
//  Returns     :void
//  Description :Sorts elements using bubblesort technique with less
//               complexity
//  Author      :Pranav Choudhary
//  Date        :17 Sept 2020
//
///////////////////////////////////////////////////////////////////
void ArraySort::BubbleSortX()       /* BubbleSortX(ArraySort const *this) */
{
    if(NULL == this->iArr)
    {
        cout << "Array Is Empty\n";
        return;
    }
    int iPass = 0, i = 0, iTemp = 0;
    bool bFlag = false;
    for (iPass = 1; iPass < this->iSize; iPass++)
    {
        bFlag = false;
        for (i = 0; i < this->iSize - iPass; i++)
        {
            if(this->iArr[i] > this->iArr[i + 1])
            {
                iTemp = this->iArr[i];
                this->iArr[i] = this->iArr[i + 1];
                this->iArr[i + 1] = iTemp;
                bFlag = true;
            }
        }
        if(bFlag == false)
        {
            break;
        }
    }
}// end of BubbleSortX

///////////////////////////////////////////////////////////////////
//
//  Name        :SelectionSort
//  Input       :void
//  Returns     :void
//  Description :Sorts elements using bubblesort technique with less
//               complexity
//  Author      :Pranav Choudhary
//  Date        :17 Sept 2020
//
///////////////////////////////////////////////////////////////////
void ArraySort::SelectionSort()       /* SelectionSort(ArraySort const *this) */
{
    if(NULL == this->iArr)
    {
        cout << "Array Is Empty\n";
        return;
    }
    int iMin = 0, i = 0, j = 0, iTemp = 0;
    for (i = 0; i < this->iSize - 1; i++)
    {
        iMin = i;
        for (j = i + 1; j < this->iSize; j++)
        {
            if(this->iArr[j] < this->iArr[iMin])
            {
                iMin = j;
            }
        }
        if(i != iMin)
        {
            iTemp = this->iArr[i];
            this->iArr[i] = this->iArr[iMin];
            this->iArr[iMin] = iTemp;
        }
    }
}// end of SelectionSort

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertionSort
//  Input       :void
//  Returns     :void
//  Description :Sorts elements using InsertionSort technique
//  Author      :Pranav Choudhary
//  Date        :17 Sept 2020
//
///////////////////////////////////////////////////////////////////
void ArraySort::InsertionSort()       /* InsertionSort(ArraySort const *this) */
{
    if(NULL == this->iArr)
    {
        cout << "Array Is Empty\n";
        return;
    }
    int i = 0, j = 0, iKey = 0;
    for (i = 1; i < this->iSize; i++)
    {
        iKey = this->iArr[i];
        j = i - 1;
        /* Iterate array to find out position for key */
        while((j >= 0) && (this->iArr[j] > iKey))
        {
            this->iArr[j + 1] = this->iArr[j];
            j--;
        }
        this->iArr[j + 1] = iKey;      /* store selected element at desired position */
    }
}// end of InsertionSort

// Entry point
int main()
{
    int iValue = 0, iRet = 0;
    bool bRet = false;
    cout << "\nEnter no. of elements\n";
    cin >> iValue;
    ArraySort *pArraySort = new ArraySort(iValue);

    cout << "\nEnter elemnets\n";
    pArraySort->Accept(); /* Accept(pArraySort); */

    cout << "\nArray elements\n";
    pArraySort->Display(); /* Display(pArraySort); */

    /* BubbleSort : Performs BubbleSort on Array
    cout << "----------------------------------------------------------------------\n";
    pArraySort->BubbleSort();   /* BubbleSort(pArratSort); 
    cout << "\nArray elements\n";
    pArraySort->Display(); /* Display(pArraySort); */

    /* BubbleSortX : Performs BubbleSort on Array
    cout << "----------------------------------------------------------------------\n";
    pArraySort->BubbleSortX();  /* BubbleSortX(pArratSort); 
    cout << "\nArray elements\n";
    pArraySort->Display(); /* Display(pArraySort); */

    /* SelectionSort : Performs SelectionSort on Array 
    cout << "----------------------------------------------------------------------\n";
    pArraySort->SelectionSort();    /* SelectionSort(pArratSort); 
    cout << "\nArray elements\n";
    pArraySort->Display(); /* Display(pArraySort); */

    /* InsertionSort : Performs InsertionSort on Array */
    cout << "----------------------------------------------------------------------\n";
    pArraySort->InsertionSort();    /* InsertionSort(pArraySort)*/
    cout << "\nArray elements\n";
    pArraySort->Display(); /* Display(pArraySort); */

    delete pArraySort;
    return 0;
}