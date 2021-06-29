/*
*   Program to implement stack in static way using array
*/

#include<iostream>
#include<stdio.h>

using namespace std;

/* class SStack */
class SStack
{
    private:
        int *iArr;
        int iTop;
        int iSize;
    
    public:
    /* Parameterized constructor with default args */
    SStack(int);
    /* Destructor */
    ~SStack();
    /* IsEmpty: check stack is empty or not */
    bool IsEmpty();
    /* IsFull: check stack is full or not */
    bool IsFull();
    /* Push: Push element in stack */
    void Push(int);
    /* Pop: Pop element from stack */
    int Pop();
    /* Display elements in stack */
    void Display();

};// end of class declaration

////////////////////////////////////////////////////////////
//
//  Name        :SStack
//  Input       :int
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
SStack::SStack(int iNum = 5)
{
    this->iSize = iNum;
    this->iTop = -1;
    this->iArr = new int[this->iSize];
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :~SStack
//  Input       :   -
//  Returns     :   -
//  Description :destructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
SStack::~SStack()
{
   delete[] iArr;
}// end of destructor

////////////////////////////////////////////////////////////
//
//  Name        :IsEmpty
//  Input       :void
//  Returns     :bool
//  Description :Check whether stack is empty or not
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
bool SStack::IsEmpty()
{
    if(this->iTop == -1)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of IsEmpty

////////////////////////////////////////////////////////////
//
//  Name        :IsFull
//  Input       :void
//  Returns     :bool
//  Description :Check whether stack is full or not
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
bool SStack::IsFull()
{
    if(this->iTop == iSize)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of IsFull

////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :Displays stack elements
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
void SStack::Display()
{
    if(IsEmpty())
    {
        cout << "Cannot display stack is empty!!\n";
        return;
    }
    int i = 0;
    cout << "Top--->";
    for(i = this->iSize -1; i >= 0; i--)
    {
        printf("\t| %04d |\n", this->iArr[i]);
    }
}// end of Display

////////////////////////////////////////////////////////////
//
//  Name        :Push
//  Input       :int
//  Returns     :void
//  Description :Push els in stack
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
void SStack::Push(int iNum)
{
    if(IsFull())
    {
        cout << "Stack is Full\n";
        return;
    }
    this->iTop++;
    this->iArr[iTop] = iNum;
}// end of Push

////////////////////////////////////////////////////////////
//
//  Name        :Pop
//  Input       :void
//  Returns     :int
//  Description :Pop els from stack
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
int SStack::Pop()
{
    if(IsEmpty())
    {
        cout << "Stack is Empty\n";
        return -1;
    }
    int iNum = 0;
    iNum = this->iArr[iTop--];
    return iNum;
}// end of Push

int main()
{
    int iNum = 0, iSize = 0, i = 0;
    cout << "Enter the number of Stack elements\t:";
    cin >> iSize;
    SStack ssObj1(iSize);

    cout << "Enter elements:\n";
    for(i = 1; i <= iSize; i++)
    {
        cin >> iNum;
        ssObj1.Push(iNum);
    }
    cout << "\nStack:\n\n";
    ssObj1.Display();

    cout << "\nPoped Element\t:" << ssObj1.Pop() << endl;
    cout << "Poped Element\t:" << ssObj1.Pop() << endl;
    cout << "Poped Element\t:" << ssObj1.Pop() << endl;

    return 0;
}