/*
*   Solved Problems on Singly Linear Linked List in C++ with Problems 3
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
    bool ListCpyEven(Singly_LinearLL&, Singly_LinearLL&);
    int  IsSublist(Singly_LinearLL&, Singly_LinearLL&);
    bool ListCpyPrime(Singly_LinearLL&, Singly_LinearLL&);
    bool ListCpyAsc(Singly_LinearLL&, Singly_LinearLL&);
    bool ListCpyDesc(Singly_LinearLL&, Singly_LinearLL&);
    bool ListMergeAlt(Singly_LinearLL&, Singly_LinearLL&);
    bool ListSwap();
    bool ListRev();
    bool ListRevInRange(int, int);
    bool InsertListAtPos(Singly_LinearLL&, Singly_LinearLL&, int);

    /* 
    *	Requires that Pointers of List1 and List2 should be
    *  	intersect with each other at some node not possible in C++ bcoz 
    * 	destructor will throw execption while deallocating either 
    * 	list as pointers are internally pointed to common node 
    *	
    *	int IsIntersect(Singly_LinearLL &, Singly_LinearLL &);
 	*/
   
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

//////////////////////////////////////////////////////////////
//
//  Name        :ListRevInRange
//  Input       :int, int
//  Returns     :bool
//  Description :reverses nodes data in given range
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListRevInRange(int iS, int iE)
{
    if(NULL == Head)
    {
        printf("Linked list is empty\n");
        return false;
    }
    if(iS < 1 || iE > iCount || iS > iE)
    {
        printf("Invalid Inputs\n");
        return false;
    }

    PNODE nTemp = Head, nStart = Head;
    int iPos = 1, i = 0;
    int *iArr = (int *)malloc(sizeof(int) * iCount);
    while(nTemp != NULL)
    {
        if(iPos == iS)
        {
            nStart = nTemp;
            while(iPos != (iE + 1))
            {
                iArr[i] = nTemp->iData;
                i++;
                iPos++;
                nTemp = nTemp->npNext;
            }
            break;
        }
        nTemp = nTemp->npNext;
        iPos++;
    }

    while(--i > -1)
    {
        nStart->iData = iArr[i];
        nStart = nStart->npNext;
    }
    free(iArr);
    return true;
}// end of ListRevInRange  


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

/*
////////////////////////////////////////////////////////////
//
//  Name        :IsIntersect
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :int
//  Description :Checks that lists are intersecting or not
//  Author      :Pranav Choudhary
//  Date        :5 Sept 2020
//
////////////////////////////////////////////////////////////
int Singly_LinearLL::IsIntersect(Singly_LinearLL& List1, Singly_LinearLL& List2)
{
    if (NULL == List1.Head && NULL == List2.Head)
    {
        printf("Linked Lists is empty\n");
        return -1;
    }
    PNODE nTemp1 = List1.Head;
    PNODE nTemp2 = List2.Head;
    int iDiff = 0, i = 0;
    if(List1.iCount > List2.iCount)
    {
        iDiff = List1.iCount - List2.iCount;
        for(i = 1; i <= iDiff; i++)
        {
            nTemp1 = nTemp1->npNext;
        }
    }
    else if(List1.iCount < List2.iCount)
    {
        iDiff = List2.iCount - List1.iCount;
        for(i = 1; i <= iDiff; i++)
        {
            nTemp1 = nTemp1->npNext;
        }
    }
    while(nTemp1 != NULL && nTemp2 != NULL)
    {
        if(nTemp1 == nTemp2)
        {
            break;
        }
        nTemp1 = nTemp1->npNext;
        nTemp2 = nTemp2->npNext;
        i++;
    }
    if(nTemp1 == NULL && nTemp2 == NULL)
    {
        return -1;
    }
    else
    {
        return i;
    }
}// end of IsIntersect
*/

////////////////////////////////////////////////////////////
//
//  Name        :ListCpyAsc
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :copies Destlist to SrcList in ascending order
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
//  Description :Swaps consecutive elements in List
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
}// end of ListSwap

///////////////////////////////////////////////////////////////////////
//
//  Name        :InsertListAtPos
//  Input       :Singly_LinearLL, Singly_LinearLL
//  Returns     :bool
//  Description :Inserts List2 at given position in List1
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_LinearLL::InsertListAtPos(Singly_LinearLL &ODest, Singly_LinearLL &OSrc, int iPos)
{
    if(NULL == ODest.Head || NULL == OSrc.Head || iPos < 0 || iPos > OSrc.iCount)
    {
        printf("Invalid Input(s)\n");
        return false;
    }
    int *iArr, i = 0;
    iArr = (int*)malloc(sizeof(int) * OSrc.iCount);
    PNODE nTemp = OSrc.Head;
    while(nTemp != NULL)
    {
        iArr[i++] = nTemp->iData;
        printf("%d\n", iArr[i - 1]);
        nTemp = nTemp->npNext;
    }
    if(iPos == 1)
    {
        while(--i != -1)
        {
            PNODE newn = new NODE;
            newn->iData = iArr[i];
            newn->npNext = NULL;
            if(ODest.Head == NULL)
            {
                ODest.Head = newn;
            }
            else
            {
                newn->npNext = ODest.Head;
                ODest.Head = newn;
            }            
        }
    }
    else if(iPos == iCount)
    {
        PNODE nTemp = OSrc.Head;
        while(nTemp != NULL)
        {
            ODest.InsertLast(nTemp->iData);
            nTemp = nTemp->npNext;
        }
    }
    else
    {
        int i = 0;
        PNODE nTemp = ODest.Head;
        for(i = 1; i < iPos - 1; i++)
        {
            nTemp = nTemp->npNext;
        }
        i = OSrc.iCount;
        while(--i > -1)
        {
            PNODE newn = new NODE;
            newn->iData = iArr[i];
            newn->npNext = NULL;
            newn->npNext = nTemp->npNext;
            nTemp->npNext = newn;
        }
    }
    free(iArr);
    return true;
}// end of InsertListApPos

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 3----------\n\n");
    int iRet = 0, i = 0, iNum = 0, iStart = 0, iEnd = 0;
    Singly_LinearLL sllObj1, sllObj2, sllObj3, sllObj4, sllObj5, sllObj6, sllObj7;

    /* Linked List 1 */
    printf("Enter the numbers[enter \'0\' to break]\n");
    while(1)
    {
        scanf("%d", &iNum);
        if(iNum == 0)
        {
            break;
        }
        sllObj1.InsertLast(iNum);
    }
    printf("Linked List 1:\n");
    sllObj1.DisplayList();
    printf("Total Elements List 1\t:%d\n",  sllObj1.Count());

    /* Linked List 2 */
    printf("-----------------------------------------------------\n");
    printf("Enter the numbers[enter \'0\' to break]\n");
    while(1)
    {
        scanf("%d", &iNum);
        if(iNum == 0)
        {
            break;
        }
        sllObj2.InsertLast(iNum);
    }
    printf("Linked List 2:\n");
    sllObj2.DisplayList();
    printf("Total Elements List 2\t:%d\n", sllObj2.Count());

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

    /* ListSwap =:Swaps elements in list 
    printf("-----------------------------------------------------\n");
    sllObj1.ListSwap();
    printf("Linked List contents Swaped:\n");
    sllObj1.DisplayList();
    printf("Total Elements in List:\n%d\n", sllObj1.Count());*/

    /* InsertListAtPos:Inserts List2 int List1 at specific position 
    printf("-----------------------------------------------------\n");
    if(sllObj1.InsertListAtPos(sllObj1, sllObj2, 2) == true)
    {
        printf("Linked List Inserted:\n");
        sllObj1.DisplayList();
    }
    printf("Total Elements in List:\n%d\n", sllObj1.Count());
    */

    /* ListRevInRange: reverses linked list in place
    printf("-----------------------------------------------------\n");
    printf("Enter start\t:");
    scanf("%d", &iStart);
    printf("Enter start\t:");
    scanf("%d", &iEnd);
    sllObj1.ListRevInRange(iStart, iEnd);
    printf("Linked List in range Reversed:\n");
    sllObj1.DisplayList();
    printf("Total Elements in List:\n%d\n", sllObj1.Count());*/

    /* IsIntersect: check lists intersect or not 
    printf("-----------------------------------------------------\n");
    iRet = sllObj1.IsIntersect(sllObj1, sllObj2);
    if(iRet != -1)
    {
        printf("Linked List intersects at\t:%d\n");
    }
    else
    {
        printf("Linked list not intersects\n");
    }
    */
    return 0;
}