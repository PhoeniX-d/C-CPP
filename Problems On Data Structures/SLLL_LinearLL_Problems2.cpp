/*
*   Implementaion of Singly Linear Linked List in C++ with Problems 1
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
    bool ListCat(Singly_LinearLL& Op1, Singly_LinearLL& Op2);
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
//  Name        :ListCat
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :concats src linked list into destination
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListCat(Singly_LinearLL& Op1, Singly_LinearLL& Op2)
{
    printf("Inside ListCat\n");
    if (NULL == Op1.Head && NULL == Op2.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    PNODE nTemp = Op2.Head;
    while (nTemp != NULL)
    {
        Op1.InsertLast(nTemp->iData);
        nTemp = nTemp->npNext;
    }
    return true;
}
// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 1----------\n\n");
    int iRet = 0, i = 0, iNum = 0;
    Singly_LinearLL sllObj1, sllObj2;

    printf("Enter Number of elements for linked list 1\n");
    scanf("%d", &iRet);
    printf("Enter the numbers\n");
    for (i = 1; i <= iRet; i++)
    {
        scanf("%d", &iNum);
        sllObj1.InsertLast(iNum);
    }
    printf("Linked List 1:\n");
    sllObj1.DisplayList();
    printf("Total Elements List 1:\n%d\n", sllObj1.Count());

    printf("-----------------------------------------------------\n");
    printf("Enter Number of elements for linked list 2\n");
    scanf("%d", &iRet);
    printf("Enter the numbers\n");
    for (i = 1; i <= iRet; i++)
    {
        scanf("%d", &iNum);
        sllObj2.InsertLast(iNum);
    }
    printf("Linked List 2:\n");
    sllObj2.DisplayList();
    printf("Total Elements List 2:\n%d\n", sllObj2.Count());


    printf("-----------------------------------------------------\n");
    sllObj1.ListCat(sllObj1, sllObj2);
    printf("Linked List 1 After Concat:\n");
    sllObj1.DisplayList();
    printf("Total Elements List 1:\n%d\n", sllObj1.Count());

    return 0;
}