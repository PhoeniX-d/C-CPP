/*
*   Program to implement stack in static way using array
*/

#include<iostream>
#include<stdio.h>

using namespace std;

/*
// Specialization of Library files
template class SStack<char>;
template class SStack<int>;
template class SStack<float>;
template class SStack<double>;
*/

/* class SStack */
template<class T>
class SStack
{
    private:
        T   *Arr;
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
    void Push(T);
    /* Pop: Pop element from stack */
    T Pop();
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
template<class T>
SStack<T>::SStack(int iNum) 
{
    this->iSize = iNum;
    this->iTop = -1;
    this->Arr = new T[this->iSize];
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
template<class T>
SStack<T>::~SStack()
{
   delete[] Arr;
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
template<class T>
bool SStack<T>::IsEmpty()
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
template<class T>
bool SStack<T>::IsFull()
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
template<class T>
void SStack<T>::Display()
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
        cout << "\t| " << this->Arr[i] << " |" << endl;
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
template<class T>
void SStack<T>::Push(T tData)
{
    if(IsFull())
    {
        cout << "Stack is Full\n";
        return;
    }
    this->iTop++;
    this->Arr[iTop] = tData;
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
template<class T>
T SStack<T>::Pop()
{
    if(IsEmpty())
    {
        cout << "Stack is Empty\n";
        return T(-1);
    }
    T tData = 0;
    tData = this->Arr[iTop--];
    return tData;
}// end of Push

int main()
{

    char ch;
    int iSize = 0, i = 0;
    cout << "Enter the number of Stack elements\t:";
    cin >> iSize;
    SStack<char> ssObj1(iSize);

    cout << "Enter elements:\n";
    for(i = 1; i <= iSize; i++)
    {
        cin >> ch;
        ssObj1.Push(ch);
    }
    cout << "\nStack:\n\n";
    ssObj1.Display();

    cout << "\nPoped Element\t:" << ssObj1.Pop() << endl;
    cout << "Poped Element\t:" << ssObj1.Pop() << endl;
    cout << "Poped Element\t:" << ssObj1.Pop() << endl;

    return 0;
}
