/*
*   Implementaion of Singly Linear Linked List in C++ with Problems 3
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node* npNext;
} NODE, * PNODE;

class Singly_LinearLL
{
private:
    PNODE Head;
    int   iCount;

public:
    /* Required Functions As Linked List */
    Singly_LinearLL();      /* constructor */
    ~Singly_LinearLL();     /* Destructor */
    inline int Count();     /* Returns number of els */
    bool InsertLast(int);   /* inserts els in list */
    bool DisplayList();     /* displays list */

    /* Problems */
    bool ListCpyEven(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
    bool ListCpyPrime(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
};

////////////////////////////////////////////////////////////
//
//  Name        :Singly_LinearLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
Singly_LinearLL::Singly_LinearLL()
{
    Head = NULL;
    iCount = 0;
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :Singly_LinearLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
Singly_LinearLL::~Singly_LinearLL()
{
    if (Head != NULL)
    {
        PNODE nTemp = NULL;
        while (Head != NULL)
        {
            nTemp = Head;
            Head = Head->npNext;
            delete nTemp;
            iCount--;
        }
        Head = NULL;
    }
}// end of Destructor

////////////////////////////////////////////////////////////
//
//  Name        :Count
//  Input       :void
//  Returns     :int
//  Description :returns count of elements
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
int Singly_LinearLL::Count()
{
    return this->iCount;
}// end of Count

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :void
//  Returns     :bool
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::DisplayList()
{
    if (Head == NULL)
    {
        printf("Linked List is NULL\n");
        return false;
    }
    PNODE First = Head;
    /* way 1 */
    while (First != NULL)
    {
        printf("|%d|->", First->iData);
        First = First->npNext;
    }
    /* way 2
    int iCnt = 0;
    while(iCnt != iCount)
    {
        printf("|%d|->", First->iData);
        First = First->npNext;
        iCnt++;
    }
    */
    printf("NULL\n\n");
    return true;
}// end of DisplayList

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :int
//  Returns     :bool
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::InsertLast(int iNum)
{
    PNODE NewN = new NODE;
    if (NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return false;
    }

    NewN->iData = iNum;
    NewN->npNext = NULL;

    /* if linked list is empty */
    if (Head == NULL)
    {
        Head = NewN;
    }
    else
    {
        PNODE nTemp = Head;
        while (nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext = NewN;
    }
    iCount++;
    return true;
}// End of InsertLast

////////////////////////////////////////////////////////////
//
//  Name        :ListCpyEven
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :concats src linked list into destination
//               whose digits addition is a even number
//  Author      :Pranav Choudhary
//  Date        :5 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListCpyEven(Singly_LinearLL& ODest, Singly_LinearLL& OSrc)
{
    if (NULL == OSrc.Head && NULL != ODest.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    PNODE nTemp = OSrc.Head;
    int iEvenSum = 0, iTemp = 0;
    while (nTemp != NULL)
    {
        iEvenSum = 0;
        iTemp = nTemp->iData;
        while(iTemp != 0)
        {
            iEvenSum = iEvenSum + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        /* check sum is even or not if it is then copy that node to destination node */
        if(iEvenSum % 2 == 0)
        {
             ODest.InsertLast(nTemp->iData);
        }       
        nTemp = nTemp->npNext;
    }
    return true;
}// end of ListCpyEven

////////////////////////////////////////////////////////////
//
//  Name        :ListCpyPrime
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :concats src linked list into destination
//               whose digits addition is prime number
//  Author      :Pranav Choudhary
//  Date        :5 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListCpyPrime(Singly_LinearLL& ODest, Singly_LinearLL& OSrc)
{
    if (NULL == OSrc.Head && NULL != ODest.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    PNODE nTemp = OSrc.Head;
    int iPrimeSum = 0, iTemp = 0, i = 0;
    while (nTemp != NULL)
    {
        iPrimeSum = 0;
        iTemp = nTemp->iData;
        while(iTemp != 0)
        {
            iPrimeSum = iPrimeSum + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        /* check for sum is prime or not */
        for (i = iPrimeSum / 2; i > 1; i--)
        {
            if(iPrimeSum % i == 0)
            {
                break;
            }
        }
        /* if prime then copy that node to destination list */
        if(i == 1)
        {
            ODest.InsertLast(nTemp->iData);
        }
        nTemp = nTemp->npNext;
    }
    return true;
}// end of ListCpyPrime

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 3----------\n\n");
    int iRet = 0, i = 0, iNum = 0, iStart = 0, iEnd = 0;
    Singly_LinearLL sllObj1, sllObj2, sllObj3;

    /* Destination Linked List
    printf("Enter Number of elements for Destination Linked List\n");
    scanf("%d", &iRet);
    printf("Enter the numbers\n");
    for (i = 1; i <= iRet; i++)
    {
        scanf("%d", &iNum);
        sllObj1.InsertLast(iNum);
    }
    printf("Destination Linked List:\n");
    sllObj1.DisplayList();
    printf("Total Elements Destination List:\n%d\n", sllObj1.Count());*/

    /* Source Linked List */
    printf("-----------------------------------------------------\n");
    printf("Enter Number of elements for Source Linked List\n");
    scanf("%d", &iRet);
    printf("Enter the numbers\n");
    for (i = 1; i <= iRet; i++)
    {
        scanf("%d", &iNum);
        sllObj2.InsertLast(iNum);
    }
    printf("Source Linked List:\n");
    sllObj2.DisplayList();
    printf("Total Elements Source List:\n%d\n", sllObj2.Count());

    /* ListCpyAlt: copies source linked list to destination whose SumDig is even
    printf("-----------------------------------------------------\n");
    if(sllObj2.ListCpyEven(sllObj3, sllObj2))
    {
        printf("Destination Linked List After Even sum element copy:\n");
        sllObj3.DisplayList();
        printf("Total Elements Destination List:\n%d\n", sllObj3.Count());
    }
    */
    /* ListCpyAlt: copies source linked list to destination whose SumDig is prime */
    printf("-----------------------------------------------------\n");
    if(sllObj2.ListCpyPrime(sllObj3, sllObj2))
    {
        printf("Destination Linked List After Prime sum element copy:\n");
        sllObj3.DisplayList();
        printf("Total Elements Destination List:\n%d\n", sllObj3.Count());
    }
    
    return 0;
}