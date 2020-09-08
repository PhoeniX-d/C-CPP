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
    int iArr[iCount], i = 0, j = 0;
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
    printf("Total Elements List 2\t:%d\n", sllObj2.Count()); */

    /* IsPalindrome:Check whether string is palindrome or not */
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
    return 0;
}