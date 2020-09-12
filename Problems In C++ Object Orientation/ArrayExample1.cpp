<<<<<<< HEAD
/*
*   Design a class that contains following openation
*   1. Memory allocation
*   2. Memory deallocation
*   3. Copy contents from one memory location to other
*   4. Accept data and store it into array
*   5. Display contents of array
*/

// Header files
#include<iostream>
using namespace std;

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
void Array::Accept()    /* Accept(Array *const this) */
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
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
void Array::Display()   /* Display(Array *const this) */
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

// class ArraySearch
class ArraySearch : protected Array
{
    public:
        ArraySearch(int i = 7):Array(i) /* Base Member initialization */
        {}

};

// Entry point
int main()
{
    Array aObj1;

    cout << "\nEnter elements\n";
    aObj1.Accept(); /* Accept(&aObj1); */
    cout << "\nArray 1 elements\n";
    aObj1.Display(); /* Display(&aObj1); */

    int iValue = 0;
    cout << "\nEnter no. of elements\n";
    cin >> iValue;
    Array *pArray = new Array(iValue);
    cout << "\nEnter elemnets\n";
    pArray->Accept(); /* Accept(pArray); */
    cout << "\nArray 2 elements\n";
    pArray->Display(); /* Display(pArray); */
    delete pArray;

    Array *pArray2 = new Array(aObj1);
    cout << "\nArray 3 elements\n";
    pArray2->Display(); /* Display(pArray2); */
    delete pArray2;

    return 0;
=======
/*
*   Design a class that contains following openation
*   1. Memory allocation
*   2. Memory deallocation
*   3. Copy contents from one memory location to other
*   4. Accept data and store it into array
*   5. Display contents of array
*/

// Header files
#include<iostream>
using namespace std;

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
void Array::Accept()    /* Accept(Array *const this) */
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
//  Date        :12 Sept 2020
//
///////////////////////////////////////////////////////////////////
void Array::Display()   /* Display(Array *const this) */
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

// class ArraySearch
class ArraySearch : protected Array
{
    public:
        ArraySearch(int i = 7):Array(i) /* Base Member initialization */
        {}

};

// Entry point
int main()
{
    Array aObj1;

    cout << "\nEnter elements\n";
    aObj1.Accept(); /* Accept(&aObj1); */
    cout << "\nArray 1 elements\n";
    aObj1.Display(); /* Display(&aObj1); */

    int iValue = 0;
    cout << "\nEnter no. of elements\n";
    cin >> iValue;
    Array *pArray = new Array(iValue);
    cout << "\nEnter elemnets\n";
    pArray->Accept(); /* Accept(pArray); */
    cout << "\nArray 2 elements\n";
    pArray->Display(); /* Display(pArray); */
    delete pArray;

    Array *pArray2 = new Array(aObj1);
    cout << "\nArray 3 elements\n";
    pArray2->Display(); /* Display(pArray2); */
    delete pArray2;

    return 0;
>>>>>>> 7e1db77ccd04542c2bf2a8e755bf2a3acc822aa2
}