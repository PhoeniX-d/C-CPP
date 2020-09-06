/*
*   Program to implement stack in dynamic way using Liked list
*/

#include<iostream>
#include<stdio.h>

using namespace std;

typedef class Node
{
    public:
        int     iData;
        Node    *cpNext;
}NODE, *PNODE;

/* class DStack */
class DStack
{
    private:
        PNODE Head = new NODE;
        int iSize;

    public:
    /* Constructor*/
    DStack();
    /* Destructor */
    ~DStack();
    /* IsEmpty: check stack is empty or not */
    bool IsEmpty();
    /* Push: Push element in stack */
    void Push(int);
    /* Pop: Pop element from stack */
    int  Pop();
    /* Display elements in stack */
    void Display();

};// end of class declaration

////////////////////////////////////////////////////////////
//
//  Name        :DStack
//  Input       :int
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
DStack::DStack()
{
    Head = NULL;
    iSize = 0;
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :~DStack
//  Input       :   -
//  Returns     :   -
//  Description :destructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
DStack::~DStack()
{
   if(Head != NULL)
   {
       PNODE cTemp = NULL;
       while(Head != NULL)
       {
           cTemp = Head;
           Head = Head->cpNext;
           delete cTemp;
           iSize--;
       }
   }
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
bool DStack::IsEmpty()
{
    if(this->iSize == 0)
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
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :Displays stack elements
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
void DStack::Display()
{
    if(IsEmpty())
    {
        cout << "Cannot display stack is empty!!\n";
        return;
    }
    int i = 0;
    PNODE cTemp = Head;
    cout << "Top--->";
    while(cTemp != NULL)
    {
        printf("\t| % 4d |\n", cTemp->iData);
        cTemp = cTemp->cpNext;
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
void DStack::Push(int iNum)
{
    PNODE newn = new NODE;
    newn->iData = iNum;
    newn->cpNext = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        PNODE cTemp = Head;
        while(cTemp->cpNext != NULL)
        {
            cTemp = cTemp->cpNext;
        }
        cTemp->cpNext = newn;
    }
    iSize++;
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
int DStack::Pop()
{
    int iNum = 0;
    if(IsEmpty())
    {
        cout << "Stack is Empty\n";
        return -1;
    }
    iNum = Head->iData;
    if(Head->cpNext == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE cTemp = Head;
        Head = Head->cpNext;
        delete cTemp;
    }
    iSize--;
    return iNum;
}// end of Push

int main()
{
    int iNum = 0, iSize = 0, i = 0;
    DStack dsObj;
    cout << "Enter elements[enter \'0\' to break]:\n";
    while(1)
    {
        cin >> iNum;
        if(iNum == 0)
        {
            break;
        }
        dsObj.Push(iNum);
    }
    cout << "\nStack:\n\n";
    dsObj.Display();

    cout << "\nPoped Element\t:" << dsObj.Pop() << endl;
    cout << "Poped Element\t:" << dsObj.Pop() << endl;
    cout << "Poped Element\t:" << dsObj.Pop() << endl;

    return 0;
}