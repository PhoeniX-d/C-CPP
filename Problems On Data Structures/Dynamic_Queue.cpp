/*
*   Program to implementation of queue in dynamic way
*/

#include<iostream>
using namespace std;

typedef class Node
{
    public:
        int iData;
        Node *cpNext;
}NODE, *PNODE;
/* class Queue */
class Queue
{
    private:
        PNODE Head;
        PNODE Tail;
        int iSize;

    public:
        Queue();            /* constructor */
        ~Queue();           /* destructor */
        void Enqueue(int);  /* insert el in queue */
        int Dequeue();      /* delete el from queue */
        void Display();     /* displays el in queue */
        int Count();        /* returns total elements in queue */
};

///////////////////////////////////////////////////////////
//
//  Name        :Queue
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////
Queue::Queue()
{
    Head = NULL;
    Tail = NULL;
    iSize = 0;
}// end of constructor

///////////////////////////////////////////////////////////
//
//  Name        :Queue
//  Input       :   -
//  Returns     :   -
//  Description :destructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////
Queue::~Queue()
{
    if(NULL != Head)
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

///////////////////////////////////////////////////////////
//
//  Name        :Enqueue
//  Input       :int
//  Returns     :void
//  Description :Inserts element in queue
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////
void Queue::Enqueue(int iNum)
{
    PNODE newn = new NODE;
    newn->iData = iNum;
    newn->cpNext = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->cpNext = newn;
        Tail = Tail->cpNext;
    }
    iSize++;
}// end of Enqueue

///////////////////////////////////////////////////////////
//
//  Name        :Dequeue
//  Input       :void
//  Returns     :int
//  Description :Deletes element from queue
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////
int Queue::Dequeue()
{
    int iNum = 0;
    if(NULL == Head && NULL == Tail)
    {
        printf("Queue is empty cannot dequeue\n");
        return -1;
    }
    if(Head == Tail)
    {
        iNum = Head->iData;
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        iNum = Head->iData;
        PNODE cTemp = Head;
        Head = Head->cpNext;
        delete cTemp;
    }
    iSize--;
    return iNum;    
}// end of Dequeue

///////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :Displays elements in queue
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////
void Queue::Display()
{
    if(Head != NULL)
    {
        PNODE cTemp = Head;
        cout << "Front-->";
        while(cTemp != NULL)
        {
            printf("|%d|", cTemp->iData);
            cTemp = cTemp->cpNext;
        }
        cout << "<--Rear\n";
    }
}// end of Display

///////////////////////////////////////////////////////////
//
//  Name        :Count
//  Input       :void
//  Returns     :void
//  Description :Deletes element from queue
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////
int Queue::Count()
{
    return this->iSize;
}// end of Dequeue

// Entry point
int main()
{
    Queue qObj;
    int iNum = 0;
    cout << "Enter elements in queue[\'0\' to stop]\n";
    while(1)
    {
        cin >> iNum;
        if(iNum == 0)
        {
            break;
        }
        qObj.Enqueue(iNum);
    }
    qObj.Display();
    cout << "Total elements in queue\t:" << qObj.Count() << endl;
    cout << "Dequeued Element\t:" << qObj.Dequeue() << endl;
    cout << "Dequeued Element\t:" << qObj.Dequeue() << endl;
    cout << "Dequeued Element\t:" << qObj.Dequeue() << endl;

    return 0;
}