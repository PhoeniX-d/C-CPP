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
    bool ListCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
    bool ListCpy(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
    bool ListNCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc, int);
    bool ListLNCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc, int);
    bool ListRangeCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc, int, int);
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
bool Singly_LinearLL::ListCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc)
{
    if (NULL == ODest.Head && NULL == OSrc.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    PNODE nTemp = OSrc.Head;
    while (nTemp != NULL)
    {
        ODest.InsertLast(nTemp->iData);
        nTemp = nTemp->npNext;
    }
    return true;
}// end of ListCat

/////////////////////////////////////////////////////////////////
//
//  Name        :ListNCat
//  Input       :Singly_LinearLL, Singly_LinearLL, int
//  Returns     :bool
//  Description :concats N elements from src list to destinaton
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
/////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListNCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc, int iN)
{
    if (NULL == ODest.Head && NULL == OSrc.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    if(iN > OSrc.iCount)
    {
        printf("Please Enter valid number to concat\n");
        return false;
    }
    if(iN < 0)
    {
        iN = -iN;
    }

    PNODE nTemp = OSrc.Head;
    while (nTemp != NULL && iN != 0)
    {
        ODest.InsertLast(nTemp->iData);
        nTemp = nTemp->npNext;
        iN--;
    }
    return true;
}// end of ListNCat

/////////////////////////////////////////////////////////////////
//
//  Name        :ListLNCat
//  Input       :Singly_LinearLL, Singly_LinearLL, int
//  Returns     :bool
//  Description :concats N elements from src list to destinaton
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
/////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListLNCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc, int iN)
{
    int iCnt = 0;
    PNODE nTemp = NULL;

    if (NULL == ODest.Head && NULL == OSrc.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    if(iN > OSrc.iCount)
    {
        printf("Please Enter valid number to concat\n");
        return false;
    }
    if(iN < 0)
    {
        iN = -iN;
    }

    iCnt = OSrc.iCount - iN;
    nTemp = OSrc.Head;

    while (nTemp != NULL && iCnt != 0)
    {
        nTemp = nTemp->npNext;
        iCnt--;
    }
    
    while (nTemp != NULL)
    {
        ODest.InsertLast(nTemp->iData);
        nTemp = nTemp->npNext;
    }
    return true;
}// end of ListLNCat

/////////////////////////////////////////////////////////////////
//
//  Name        :ListRangeCat
//  Input       :Singly_LinearLL, Singly_LinearLL, int, int
//  Returns     :bool
//  Description :concats elements from src list to destinaton
//              :in given range
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
/////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListRangeCat(Singly_LinearLL& ODest, Singly_LinearLL& OSrc, int iS, int iE)
{
    if (NULL == ODest.Head && NULL == OSrc.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    if(iE > OSrc.iCount || iS < 1)
    {
        printf("Please Enter valid number to concat\n");
        return false;
    }
    if(iS < 0)
        iS = -iS;
    if(iE < 0)
        iE = -iE;

    int iCnt = iE - iS + 1, i = 0;
    PNODE nTemp = OSrc.Head;
    for (i = 1; i < iS ; i++)
    {
        nTemp = nTemp->npNext;
    }
    while (nTemp != NULL && iCnt != 0)
    {
        ODest.InsertLast(nTemp->iData);
        nTemp = nTemp->npNext;
        iCnt--;
    }
    return true;
}// end of ListRangeCat

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
bool Singly_LinearLL::ListCpy(Singly_LinearLL& ODest, Singly_LinearLL& OSrc)
{
    if (NULL == OSrc.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    PNODE nTemp = OSrc.Head;
    while (nTemp != NULL)
    {
        ODest.InsertLast(nTemp->iData);
        nTemp = nTemp->npNext;
    }
    return true;
}// end of ListCpy

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 1----------\n\n");
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

    /* ListCat: Concat 2 lists
    printf("-----------------------------------------------------\n");
    sllObj1.ListCat(sllObj1, sllObj2);
    printf("Destination Linked List After Concat:\n");
    sllObj1.DisplayList();
    printf("Total Elements Destination List:\n%d\n", sllObj1.Count());*/

    /* ListNcat: Concats N elements
    printf("-----------------------------------------------------\n");
    printf("Enter number of elements to concat:\n");
    scanf("%d", &iNum);
    sllObj1.ListNCat(sllObj1, sllObj2, iNum);
    printf("Destination Linked List After N Concat %d:\n", iNum);
    sllObj1.DisplayList();
    printf("Total Elements Destination List:\n%d\n", sllObj1.Count());*/

    /* ListLNCat: Concats last N elements 
    printf("-----------------------------------------------------\n");
    printf("Enter number of last elements to concat:\n");
    scanf("%d", &iNum);
    sllObj1.ListLNCat(sllObj1, sllObj2, iNum);
    printf("Destination Linked List After Last N Concat %d:\n", iNum);
    sllObj1.DisplayList();
    printf("Total Elements Destination List:\n%d\n", sllObj1.Count());*/

    /* ListRangeCat: concat elements in range 
    printf("-----------------------------------------------------\n");
    printf("Enter position of start:\n");
    scanf("%d", &iStart);
    printf("Enter position of end:\n");
    scanf("%d", &iEnd);
    sllObj1.ListRangeCat(sllObj1, sllObj2, iStart, iEnd);
    printf("Destination Linked List After Last N Concat %d:\n", iNum);
    sllObj1.DisplayList();
    printf("Total Elements Destination List:\n%d\n", sllObj1.Count());*/

    /* ListCpy: copies source linked list to destination */
    printf("-----------------------------------------------------\n");
    sllObj2.ListCpy(sllObj3, sllObj2);
    printf("Destination Linked List After copy:\n");
    sllObj3.DisplayList();
    printf("Total Elements Destination List:\n%d\n", sllObj3.Count());
    return 0;
}