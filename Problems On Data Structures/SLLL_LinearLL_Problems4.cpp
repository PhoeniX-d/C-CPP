/*
*   Implementaion of Singly Linear Linked List in C++ with Problems 4
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef class Node
{
    public:
        int     iData;
        Node    *cpNext;
}NODE, *PNODE;

class Singly_LinearLL
{
    private:
        PNODE Head;
        int   iCount;

    public:
    /* Required Functions As Linked List */
    Singly_LinearLL();      /* constructor (initialization) */
    ~Singly_LinearLL();     /* Destructor (dedallocation)*/
    inline int Count();     /* Returns number of els */
    bool InsertLast(int);   /* inserts els in list */
    bool DisplayList();     /* displays list */

    /* Problems */
    bool IsPalindrome();
    void ListSortAsc();
    void ListSortDesc();
    bool ListCmp(Singly_LinearLL &);
    bool ListNCmp(Singly_LinearLL &, int);
    bool ListLNCmp(Singly_LinearLL &, int);
    int FindMiddle();
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
            Head = Head->cpNext;
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
        First = First->cpNext;
    }
    /* way 2
    int iCnt = 0;
    while(iCnt != iCount)
    {
        printf("|%d|->", First->iData);
        First = First->cpNext;
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
    NewN->cpNext = NULL;

     /* if linked list is empty */
    if(Head == NULL)
    {
        Head = NewN;
    }
    else
    {
        PNODE nTemp = Head;
        while(nTemp->cpNext != NULL)
        {
            nTemp = nTemp->cpNext;
        }
        nTemp->cpNext = NewN;
    }
    iCount++;
    return true;
}// End of InsertLast

///////////////////////////////////////////////////////////////////////
//
//  Name        :IsPalindrome
//  Input       :void
//  Returns     :bool
//  Description :Checks  whether list is palindrome or not
//  Author      :Pranav Choudhary
//  Date        :8 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_LinearLL::IsPalindrome()
{
    if(Head == NULL)
    {
        printf("List Is Empty");
        return false;
    }
    int *iArr = (int*)malloc(sizeof(int) * iCount);
    int i = 0, j = 0;
    PNODE cTemp = Head;
    while(cTemp != NULL)
    {
        iArr[i++] = cTemp->iData;
        cTemp = cTemp->cpNext;
    }
    i--;
    j = 0;
    while(j < i)
    {
        if(iArr[i] != iArr[j])
        {
            break;
        }
        i--;
        j++;
    }
    if(j >= i)
        return true;
    else
        return false;
}

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListSortAsc
//  Input       :void
//  Returns     :void
//  Description :Sorts List in Ascending order
//  Author      :Pranav Choudhary
//  Date        :8 Sept 2020
//
///////////////////////////////////////////////////////////////////////
void Singly_LinearLL::ListSortAsc()
{
    if(Head == NULL && Head->cpNext == NULL)
    {
        return;
    }
    PNODE Temp1 = Head;
    PNODE Temp2 = Head->cpNext;
    PNODE Temp3 = NULL;

    while(Temp2 != NULL)
    {
        if(Temp1->iData > Temp2->iData)
        {
            if(Temp1 == Head && Temp2 == Head->cpNext)
            {
                Temp1->cpNext = Temp2->cpNext;
                Temp2->cpNext = Head;
                Head = Temp2;
            }
            else
            {
                Temp3 = Head;
                while(Temp3->cpNext != Temp1)
                {
                    Temp3 = Temp3->cpNext;
                }
                Temp3->cpNext = Temp2;
                Temp1->cpNext = Temp2->cpNext;
                Temp2->cpNext = Temp1;
            }
            Temp1 = Head;
            Temp2 = Temp1->cpNext;
        }
        else
        {
            Temp1 = Temp1->cpNext;
            Temp2 = Temp1->cpNext;
        }        
    }
}// end of ListSortAsc

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListSortDesc
//  Input       :void
//  Returns     :void
//  Description :Sorts List in Descending order
//  Author      :Pranav Choudhary
//  Date        :8 Sept 2020
//
///////////////////////////////////////////////////////////////////////
void Singly_LinearLL::ListSortDesc()
{
    if(Head == NULL && Head->cpNext == NULL)
    {
        return;
    }
    PNODE Temp1 = Head;
    PNODE Temp2 = Head->cpNext;
    PNODE Temp3 = NULL;

    while(Temp2 != NULL)
    {
        if(Temp1->iData < Temp2->iData)
        {
            if(Temp1 == Head && Temp2 == Head->cpNext)
            {
                Temp1->cpNext = Temp2->cpNext;
                Temp2->cpNext = Head;
                Head = Temp2;
            }
            else
            {
                Temp3 = Head;
                while(Temp3->cpNext != Temp1)
                {
                    Temp3 = Temp3->cpNext;
                }
                Temp3->cpNext = Temp2;
                Temp1->cpNext = Temp2->cpNext;
                Temp2->cpNext = Temp1;
            }
            Temp1 = Head;
            Temp2 = Temp1->cpNext;
        }
        else
        {
            Temp1 = Temp1->cpNext;
            Temp2 = Temp1->cpNext;
        }        
    }
}// end of ListSortDesc

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListCmp
//  Input       :Singly_LinearLL&
//  Returns     :bool
//  Description :Compares 2 List for equality
//  Author      :Pranav Choudhary
//  Date        :8 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListCmp(Singly_LinearLL &List2)
{
    if(this->Head == NULL || List2.Head == NULL)
    {
        printf("List are empty\n");
        return false;
    }
    
    PNODE temp1 = this->Head;
    PNODE temp2 = List2.Head;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->iData != temp2->iData)
        {
            break;
        }
        temp1 = temp1->cpNext;
        temp2 = temp2->cpNext;
    }
    if(temp1 == NULL && temp2 == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of ListCmp

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListCmp
//  Input       :Singly_LinearLL&
//  Returns     :bool
//  Description :Compares 2 List for equality
//  Author      :Pranav Choudhary
//  Date        :8 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListNCmp(Singly_LinearLL &List2, int iN)
{
    if(this->Head == NULL || List2.Head == NULL)
    {
        printf("List are empty\n");
        return false;
    }
    if(iN < 1 && iN > iCount)
    {
        printf("Invalid value of N\n");
        return false;
    }
    PNODE temp1 = this->Head;
    PNODE temp2 = List2.Head;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->iData != temp2->iData)
        {
            break;
        }
        temp1 = temp1->cpNext;
        temp2 = temp2->cpNext;
    }
    if(temp1 == NULL && temp2 == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of ListNCmp

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListCmp
//  Input       :Singly_LinearLL&
//  Returns     :bool
//  Description :Compares 2 List for equality
//  Author      :Pranav Choudhary
//  Date        :8 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_LinearLL::ListLNCmp(Singly_LinearLL &List2, int iN)
{
    if(this->Head == NULL || List2.Head == NULL)
    {
        printf("List are empty\n");
        return false;
    }
    if(iN < 1 && iN > iCount)
    {
        printf("Invalid value of N\n");
        return false;
    }
    PNODE temp1 = this->Head;
    PNODE temp2 = List2.Head;

    int iCnt1 = this->iCount - iN;
    int iCnt2 = List2.iCount - iN;
    
    while(iCnt1 != 0 && temp1 != NULL)
    {
        temp1 = temp1->cpNext;
        iCnt1--;
    }

    while(iCnt2 != 0 && temp2 != NULL)
    {
        temp2 = temp2->cpNext;
        iCnt2--;
    }

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->iData != temp2->iData)
        {
            break;
        }
        temp1 = temp1->cpNext;
        temp2 = temp2->cpNext;
    }
    if(temp1 == NULL && temp2 == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of ListLNCmp

///////////////////////////////////////////////////////////////////////
//
//  Name        :FindMiddle
//  Input       :void
//  Returns     :int
//  Description :Returns middle element of List
//  Author      :Pranav Choudhary
//  Date        :8 Sept 2020
//
///////////////////////////////////////////////////////////////////////
int Singly_LinearLL::FindMiddle()
{
    if(NULL == Head)
    {
        printf("List is empty\n");
        return 0;
    }
    PNODE temp1 = Head, temp2 = Head;
    while(temp1 != NULL && temp2->cpNext != NULL)
    {
        temp1 = temp1->cpNext;
        if(temp2->cpNext->cpNext != NULL)
            temp2 = temp2->cpNext->cpNext;
        else
            temp2 = temp2->cpNext;
    }
    return temp1->iData;
}// end of FindMiddle

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 3----------\n\n");
    int iRet = 0, i = 0, iNum = 0;
    Singly_LinearLL sllObj1, sllObj2;

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

    /* Linked List 2
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
    printf("Total Elements List 2\t:%d\n", sllObj2.Count());*/

    /* IsPalindrome:Check whether string is palindrome or not 
    printf("------------------------------------------------------\n");
    if(sllObj1.IsPalindrome() == true)
    {
        printf("List is Palindrome\n");
        sllObj1.DisplayList();
    }
    else
    {
        printf("List is not palindrome\n");
    }
    */

    /* ListSortAsc:Sorts list in ascending order 
    printf("------------------------------------------------------\n");
    printf("Linked In Sorted order\n");
    sllObj1.ListSortAsc();
    sllObj1.DisplayList();
    printf("Total Elements List 2\t:%d\n", sllObj1.Count());

    /* ListSortAsc:Sorts list in ascending order
    printf("------------------------------------------------------\n");
    printf("Linked In Sorted order\n");
    sllObj1.ListSortDesc();
    sllObj1.DisplayList();
    printf("Total Elements List 2\t:%d\n", sllObj1.Count()); */

    /* ListCmp:compares two lists for equality 
    printf("------------------------------------------------------\n");
    if(sllObj1.ListCmp(sllObj2) == true)
    {
        printf("Lists are equal\n");
    }
    else
    {
        printf("List are not equal\n");
    }
    */

    /* ListNCmp:compares two lists for equality upto N elements
    printf("------------------------------------------------------\n");
    printf("Enter value of N\t:");
    scanf("%d", &iNum);
    if(sllObj1.ListNCmp(sllObj2, iNum) == true)
    {
        printf("Lists are equal\n");
    }
    else
    {
        printf("List are not equal\n");
    }

    /* ListLNCmp:compares two lists for equality only last N elements
    printf("------------------------------------------------------\n");
    printf("Enter value of N\t:");
    scanf("%d", &iNum);
    if(sllObj1.ListLNCmp(sllObj2, iNum) == true)
    {
        printf("Lists are equal\n");
    }
    else
    {
        printf("List are not equal\n");
    }
    */
    /* FindMiddle : Find middle element of list */
    printf("------------------------------------------------------\n");
    iRet = sllObj1.FindMiddle();
    if(iRet != 0)
        printf("Middle element of List is\t:%d\n", iRet);
    printf("Total Elements List 2\t:%d\n", sllObj1.Count());

    return 0;
}