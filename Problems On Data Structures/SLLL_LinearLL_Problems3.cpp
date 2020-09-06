/*
*   Implementaion of Singly Linear Linked List in C++ with Problems 3
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node     *npNext;
} NODE, *PNODE;

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
    int  IsSublist(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
    bool ListCpyPrime(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
    bool ListCpyAsc(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
    bool ListCpyDesc(Singly_LinearLL& ODest, Singly_LinearLL& OSrc);
    bool ListMergeAlt(Singly_LinearLL &ODest, Singly_LinearLL &OSrc);
    bool ListSwap();
    bool ListRev();
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
    if(Head != NULL)
    {
        PNODE nTemp = NULL;
        while(Head != NULL)
        {
            nTemp = Head;
            Head = Head->npNext;
            delete nTemp;
            iCount--;
        }
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
	return iCount;
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
    if(Head == NULL)
    {
        printf("Linked List is NULL\n");
        return false;
    }
    PNODE First = Head;
    /* way 1 */
    while(First != NULL)
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
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return false;
    }
    
    NewN->iData = iNum;
    NewN->npNext = NULL;

     /* if linked list is empty */
    if(Head == NULL)
    {
        Head = NewN;
    }
    else
    {
        PNODE nTemp = Head;
        while(nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext = NewN;
    }
    iCount++;
    return true;
}// End of InsertLast

//////////////////////////////////////////////////////////////
//
//  Name        :ReverseList
//  Input       :void
//  Returns     :void
//  Description :returns position of First occurance of number
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListRev()
{
    if(NULL == Head)
    {
        printf("Linked list is empty\n");
        return false;
    }

    PNODE Next = NULL;
    PNODE Prev = NULL;

    while(Head != NULL)
    {
        Next = Head->npNext;
        Head->npNext = Prev;
        Prev = Head;
        Head = Next;
    }
    Head = Prev;
    return true;
}// end of ListRev  

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
        while(iTemp > 0)
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
        while(iTemp > 0)
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

////////////////////////////////////////////////////////////
//
//  Name        :IsSublist
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :int
//  Description :Checks that list2 is sublist of list1
//  Author      :Pranav Choudhary
//  Date        :5 Sept 2020
//
////////////////////////////////////////////////////////////
int Singly_LinearLL::IsSublist(Singly_LinearLL& List1, Singly_LinearLL& List2)
{
    if (NULL == List1.Head && NULL == List2.Head)
    {
        printf("Linked Lists is empty\n");
        return -1;
    }
    PNODE nTemp1 = List1.Head;
    PNODE nTemp2 = NULL;
    int iPos = 0;
    while(nTemp1 != NULL)
    {
        nTemp2 = List2.Head;
        while(nTemp1 != NULL && nTemp2 != NULL)
        {
            if(nTemp1->iData != nTemp2->iData)
            {
                break;
            }
            nTemp1 = nTemp1->npNext;
            nTemp2 = nTemp2->npNext;
        }
        if(nTemp2 == NULL)
        {
            iPos++;
            break;
        }
        if(nTemp1 != NULL)
        {
            nTemp1 = nTemp1->npNext;
        }
        iPos++;
    }
    if(nTemp2 == NULL)
    {
        return iPos;
    }
    else
    {
        return -1;
    }
}// end of IsSublist

////////////////////////////////////////////////////////////
//
//  Name        :ListCpyAsc
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :copies list1 to list 2 in ascending order
//  Author      :Pranav Choudhary
//  Date        :5 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListCpyAsc(Singly_LinearLL& ODest, Singly_LinearLL& OSrc)
{
    if (NULL == OSrc.Head && NULL != ODest.Head)
    {
        printf("Invalid Inputs\n");
        return false;
    }
    PNODE newn = NULL;
    PNODE nTemp1 = OSrc.Head;
    PNODE nTemp2 = NULL;
    PNODE nTemp3 = NULL;

    while(nTemp1 != NULL)
    {
        newn = new NODE;
        newn->iData = nTemp1->iData;
        newn->npNext = NULL;
        
        ODest.iCount++;

        if(ODest.Head == NULL)
        {
            ODest.Head = newn;
        }

        else if(ODest.Head->iData > newn->iData)
        {
            newn->npNext = ODest.Head;
            ODest.Head = newn;
        }
        else if(newn->iData > ODest.Head->iData)
        {
            nTemp2 = ODest.Head;
            while(nTemp2 != NULL && nTemp2->iData < newn->iData)
            {
                nTemp3 = nTemp2;
                nTemp2 = nTemp2->npNext;
			}			
			newn->npNext = nTemp2;
			nTemp3->npNext = newn;
		}
        nTemp1 = nTemp1->npNext;
    }
    return true;
}// end of ListCpyAsc

////////////////////////////////////////////////////////////
//
//  Name        :ListCpyDesc
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :copies list1 to list 2 in Descending order
//  Author      :Pranav Choudhary
//  Date        :5 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListCpyDesc(Singly_LinearLL& ODest, Singly_LinearLL& Osrc)
{
    if (NULL == Osrc.Head && NULL != ODest.Head)
    {
        printf("Invalid Inputs\n");
        return false;
    }
    PNODE newn = NULL;
    PNODE nTemp1 = Osrc.Head;
    PNODE nTemp2 = NULL;
    PNODE nTemp3 = NULL;

    while(nTemp1 != NULL)
    {
        newn = new NODE;
        newn->iData = nTemp1->iData;
        newn->npNext = NULL;
        
        ODest.iCount++;

        if(ODest.Head == NULL)
        {
            ODest.Head = newn;
        }

        else if(ODest.Head->iData < newn->iData)
        {
            newn->npNext = ODest.Head;
            ODest.Head = newn;
        }
        else if(newn->iData < ODest.Head->iData)
        {
            nTemp2 = ODest.Head;
            while(nTemp2 != NULL && nTemp2->iData > newn->iData)
            {
                nTemp3 = nTemp2;
                nTemp2 = nTemp2->npNext;
			}			
			newn->npNext = nTemp2;
			nTemp3->npNext = newn;
		}
        nTemp1 = nTemp1->npNext;
    }
    return true;
}// end of ListCpyDesc

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListMergeAlt
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :Merge 2 linked list alternate way
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListMergeAlt(Singly_LinearLL& ODest, Singly_LinearLL& OSrc)
{
    if (NULL == OSrc.Head && NULL == ODest.Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    PNODE nTemp1 = ODest.Head;
    PNODE nTemp2 = NULL;
    PNODE nTemp3 = OSrc.Head;

    while (nTemp1 != NULL && nTemp3 != NULL)
    {
        nTemp2 = nTemp1->npNext;
        nTemp2 = nTemp1->npNext;
        PNODE newn = new NODE;
        newn->iData = nTemp3->iData;
        newn->npNext = nTemp2;
        nTemp1->npNext = newn;
        nTemp1 = nTemp2;
        nTemp3 = nTemp3->npNext;
        iCount++;
    }
    return true;
}// end of ListMergeAlt

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListSwap
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :Merge 2 linked list alternate way
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListSwap()
{
    if (NULL == Head)
    {
        printf("Linked Lists is empty\n");
        return false;
    }
    PNODE nTemp1 = Head;
    PNODE nTemp2 = NULL;
    int iTemp = 0;

    while (nTemp1 != NULL)
    {
        if(nTemp1->npNext == NULL)
        {
            break;
        }
        nTemp2 = nTemp1->npNext;
        iTemp = nTemp1->iData;
        nTemp1->iData = nTemp2->iData;
        nTemp2->iData = iTemp;

        nTemp1 = nTemp2->npNext;
    }
    return true;
}// end of ListMerge

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 3----------\n\n");
    int iRet = 0, i = 0, iNum = 0;
    Singly_LinearLL sllObj1, sllObj2, sllObj3, sllObj4, sllObj5, sllObj6, sllObj7;

    /* Linked List 1 */
    printf("Enter Number of elements for Linked List 1\n");
    scanf("%d", &iRet);
    printf("Enter the numbers\n");
    for (i = 1; i <= iRet; i++)
    {
        scanf("%d", &iNum);
        sllObj1.InsertLast(iNum);
    }
    printf("Linked List 1:\n");
    sllObj1.DisplayList();
    printf("Total Elements List 1\t:%d\n",  sllObj1.Count());

    /* Linked List 2
    printf("-----------------------------------------------------\n");
    printf("Enter Number of elements for Linked List 2\n");
    scanf("%d", &iRet);
    printf("Enter the numbers\n");
    for (i = 1; i <= iRet; i++)
    {
        scanf("%d", &iNum);
        sllObj2.InsertLast(iNum);
    }
    printf("Linked List 2:\n");
    sllObj2.DisplayList();
    printf("Total Elements List 2\t:%d\n", sllObj2.Count()); */

    /* ListCpyAlt: copies source linked list to destination whose SumDig is even 
    printf("-----------------------------------------------------\n");
    if(sllObj1.ListCpyEven(sllObj3, sllObj1))
    {
        printf("Destination Linked List After Even sum element copy:\n");
        sllObj3.DisplayList();
        printf("Total Elements in Linked List 3\t\t:%2d\n", sllObj3.Count());
    }

    /* ListCpyAlt: copies source linked list to destination whose SumDig is prime 
    printf("-----------------------------------------------------\n");
    if(sllObj1.ListCpyPrime(sllObj4, sllObj1))
    {
        printf("Destination Linked List After Prime sum element copy:\n");
        sllObj4.DisplayList();
        printf("Total Elements in Linked List 3\t\t:%2d\n", sllObj4.Count());
    }
    
    /* IsSublist: check List2 is sublist in List1 or not 
    printf("-----------------------------------------------------\n");
    iRet = sllObj1.IsSublist(sllObj1, sllObj2);
    if(iRet != -1)
    {
        printf("List2 is sublist in List1 at position\t:%d", iRet);
    }
    else
    {
        printf("List2 is Not sublist in List1\n");
    }
    
    /* ListCpyAsc: copy list1 to list2 in ascending order
    printf("-----------------------------------------------------\n");
    if(sllObj1.ListCpyAsc(sllObj5, sllObj1))
    {
        printf("Linked List 3 after copy Ascending order:\n");
        sllObj5.DisplayList();
        printf("Total Elements in Linked List 3\t\t:%2d\n", sllObj5.Count());
    }

    /* ListCpyAsc: copy list1 to list2 in descending order 
    printf("-----------------------------------------------------\n");
    if(sllObj1.ListCpyDesc(sllObj6, sllObj1))
    {
        printf("Linked List 3 after copy Descending order:\n");
        sllObj6.DisplayList();
        printf("Total Elements in Linked List 3\t\t:%2d\n", sllObj6.Count());
    }
	
	/* ListRev: reverses linked list in place
    printf("-----------------------------------------------------\n");
    sllObj1.ListRev();
    printf("Linked List Reversed:\n");
    sllObj1.DisplayList();
    printf("Total Elements in List:\n%d\n", sllObj1.Count());

    /* ListMergeAlt:Merge Two lists alterntely
    printf("-----------------------------------------------------\n");
    sllObj1.ListMergeAlt(sllObj1, sllObj2);
    printf("Linked List Merged:\n");
    sllObj1.DisplayList();
    printf("Total Elements in List:\n%d\n", sllObj1.Count());

    /* ListSwap =:Swaps elements in list */
    printf("-----------------------------------------------------\n");
    sllObj1.ListSwap();
    printf("Linked List contents Swaped:\n");
    sllObj1.DisplayList();
    printf("Total Elements in List:\n%d\n", sllObj1.Count());
    return 0;
}