/*
*   Implementaion of Singly Linear Linked List in C++ with Problems 1
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
        int FirstOccur(int);
        int SecOccur(int);
        int LastOccur(int);
        int SecLastOccur(int);
        int Maximum();
        int SecMaximum();
        int Minimum();
        int SecMinimum();
        bool ReverseList();
        int TotalOccur(int);
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
bool Singly_LinearLL::ReverseList()
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
}// end of ReverseList   

//////////////////////////////////////////////////////////////
//
//  Name        :TotalOccur
//  Input       :int
//  Returns     :int
//  Description :returns number of occurance of number
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::TotalOccur(int iNum)
{
    int iCnt = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    while(First != NULL)
    {
        if(First->iData == iNum)
        {
            iCnt++;
        }
        First = First->npNext;
    }
    return iCnt;
}// end of TotalOccur

//////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :int
//  Returns     :int
//  Description :returns position of First occurance of number
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::FirstOccur(int iNum)
{
    int iPos = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    while(First != NULL)
    {
        iPos++;
        if(First->iData == iNum)
        {
            break;
        }
        First = First->npNext;
    }
    if(First != NULL)
    {
        return iPos;
    }
    else
    {
        return -1;
    }
}// end of FirstOccur

//////////////////////////////////////////////////////////////
//
//  Name        :SecOccur
//  Input       :int
//  Returns     :int
//  Description :returns position of second occurance of number
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::SecOccur(int iNum)
{
    int iPos = 0, iCnt = 0, iPos2 = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    while(First != NULL)
    {
        iPos++;
        if(First->iData == iNum)
        {
            iCnt++;
			if(iCnt == 2)
            {
                break;
            }
			iPos2 = iPos;
        }
        First = First->npNext;
    }
    if(iCnt == 2)
    {
        return iPos;
    }
	else if(iCnt == 1)
    {
        return iPos2;
    }
    else
    {
        return -1;
    }    
}// end of SecOccur

//////////////////////////////////////////////////////////////
//
//  Name        :LastOccur
//  Input       :int
//  Returns     :int
//  Description :returns position of Last occurance of number
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::LastOccur(int iNum)
{
    int iPos = 0, iCnt = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    while(First != NULL)
    {
        iCnt++;
        if(First->iData == iNum)
        {
            iPos = iCnt;
        }
        First = First->npNext;
    }
    if(iPos == 0)
	{
		return -1;
	}
	else
	{
		return iPos;
	}
}// end of FirstOccur

//////////////////////////////////////////////////////////////
//
//  Name        :SecLastOccur
//  Input       :int
//  Returns     :int
//  Description :returns second last position of number
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::SecLastOccur(int iNum)
{
    int iPos = -1, iCnt = 0, iPos2 = -1;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return iPos2;
    }
    PNODE First = Head;
    while(First != NULL)
    {
        iCnt++;
        if(First->iData == iNum)
        {
            iPos2 = iPos;
            iPos = iCnt;            
        }
        First = First->npNext;
    }
    if(iPos2 == -1)
    {
        return iPos;
    }
    else
    {
        return iPos2;
    }
}// end of SecLastOccur

//////////////////////////////////////////////////////////////
//
//  Name        :Maximum
//  Input       :void
//  Returns     :int
//  Description :returns largest element in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::Maximum()
{
    int iMax = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    iMax = First->iData;
    First = First->npNext;
    while(First != NULL)
    {
        if(iMax < First->iData)
        {
            iMax = First->iData;
        }
        First = First->npNext;
    }
    return iMax;
}// end of Maximum

//////////////////////////////////////////////////////////////
//
//  Name        :Minimum
//  Input       :void
//  Returns     :int
//  Description :returns smallest element in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::Minimum()
{
    int iMin = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    iMin = First->iData;
    First = First->npNext;
    while(First != NULL)
    {
        if(iMin > First->iData)
        {
            iMin = First->iData;
        }
        First = First->npNext;
    }
    return iMin;
}// end of Minimum

//////////////////////////////////////////////////////////////
//
//  Name        :SecMaximum
//  Input       :void
//  Returns     :int
//  Description :returns second largest element in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::SecMaximum()
{
    int iMax1 = 0, iMax2 = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    iMax1 = First->iData;
    First = First->npNext;
    while(First != NULL)
    {
        if(iMax1 < First->iData)
        {
            iMax2 = iMax1;
            iMax1 = First->iData;
        }
        else if(iMax2 < First->iData)
        {
            iMax2 = First->iData;
        }
        First = First->npNext;
    }
    return iMax2;
}// end of SecMaximum

//////////////////////////////////////////////////////////////
//
//  Name        :SecMinimum
//  Input       :void
//  Returns     :int
//  Description :returns second smallest element in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////
int Singly_LinearLL::SecMinimum()
{
    int iMin1 = 0, iMin2 = 0;
    if(NULL == Head)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    PNODE First = Head;
    iMin1 = First->iData;
    First = First->npNext;
    while(First != NULL)
    {
        if(iMin1 > First->iData)
        {
            iMin2 = iMin1;
            iMin1 = First->iData;
        }
        else if((iMin1 > iMin2 || iMin2 > First->iData) && iMin1 != iMin2)
        {
            iMin2 = First->iData;
        }
        First = First->npNext;
    }
    return iMin2;
}// end of SecMinimum

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 1----------\n\n");
    int iRet = 0, i = 0, iNum = 0;
    Singly_LinearLL sllObj;

    printf("Enter Number of elements\n");
    scanf("%d", &iRet);
    printf("Enter the numbers\n");
    for (i = 1; i <= iRet; i++)
    {
        scanf("%d", &iNum);
        sllObj.InsertLast(iNum);
    }
    printf("Linked List:\n");
    sllObj.DisplayList();

    printf("-----------------------------------------------------\n");
    /* First occurance of particular number */
    printf("Enter number for first occurance:\n");
    scanf("%d", &iNum);
    iRet = sllObj.TotalOccur(iNum);
    if(iRet != -1)
        printf("Total Occuarance of %d:\n%d\n", iNum, iRet);
    else
        printf("Element Not Found!!\n");

    printf("-----------------------------------------------------\n");
    /* First occurance of particular number */
    printf("Enter number for first occurance:\n");
    scanf("%d", &iNum);
    iRet = sllObj.FirstOccur(iNum);
    if(iRet != -1)
        printf("First Occuarance of %d at %d position\n", iNum, iRet);
    else
        printf("Element Not Found!!\n");

    printf("-----------------------------------------------------\n");
    /* Last occurance of particular number */
    printf("Enter number for last occurance:\n");
    scanf("%d", &iNum);
    iRet = sllObj.LastOccur(iNum);
    if(iRet != -1)
        printf("Last Occuarance of %d at %d position\n", iNum, iRet);
    else
        printf("Element Not Found!!\n");

    printf("-----------------------------------------------------\n");
    /* Second occurance of particular number */
    printf("Enter number for Second occurance:\n");
    scanf("%d", &iNum);
    iRet = sllObj.SecOccur(iNum);
    if(iRet != -1)
        printf("Second occurance of %d at %d position\n", iNum, iRet);
    else
        printf("Element Not Found!!\n");

    printf("-----------------------------------------------------\n");
    /* second last occurance of particular number */
    printf("Enter number for Second last occurance:\n");
    scanf("%d", &iNum);
    iRet = sllObj.SecLastOccur(iNum);
    if(iRet != -1)
        printf("Second last occurance of %d at %d position\n", iNum, iRet);
    else
        printf("Element Not Found!!\n");

    printf("-----------------------------------------------------\n");
    /* Finds largest element in linked list */
    iRet = sllObj.Maximum();
    printf("Largest elements is:\n%d\n", iRet);

    printf("-----------------------------------------------------\n");
    /* Finds smallest element in linked list */
    iRet = sllObj.Minimum();
    printf("Smallest elements is:\n%d\n", iRet);

    printf("-----------------------------------------------------\n");
    /* Prints second maximum number */
    iRet = sllObj.SecMaximum();
    printf("Second Maximum is:\n%d\n", iRet);

    printf("-----------------------------------------------------\n");
    /* Prints second minimum number */
    iRet = sllObj.SecMinimum();
    printf("Second Minimum is:\n%d\n", iRet);

    printf("-----------------------------------------------------\n");
    /* Reverses whole list in place */
    sllObj.ReverseList();
    printf("Linked List Reversed:\n");
    sllObj.DisplayList();

    return 0;
}