/*
*   Implementaion of Singly Linear Linked List
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node     *npNext;
} NODE, *PNODE, **PPNODE;

// global declarations
void InsertFirst(PPNODE, int);
void InsertLast(PPNODE, int);
void DisplayList(PNODE);
int  CountEls(PNODE);
void Deallocate(PPNODE);
int  Add(PNODE);
int  AddEven(PNODE);
int  AddOdd(PNODE);
int  CountFreq(PNODE, int);
int FirstOccur(PNODE, int);
int LastOccur(PNODE, int);
int Maximum(PNODE);
int Minimum(PNODE);
/*void ListCat(PNODE, PNODE);
int IsIntersect(PNODE, PNODE);*/

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 1----------\n\n");
    PNODE Head = NULL;
    PNODE Head1 = NULL;

    int iRet = 0, i = 0, iNo = 0, iNum = 0;

    printf("List 1:\n");
    printf("-----------------------------------------------------\n");
    printf("Enter the numbers[enter \'0\' to break]\n");
    while(1)
    {
        scanf("%d", &iNum);
        if(iNum == 0)
        {
            break;
        }
        InsertLast(&Head, iNum);
    }
    printf("Linked List 1:\n");
    DisplayList(Head);
    
    /* Count number of elemnts */
    iRet = CountEls(Head);
    printf("Total Elements:\t\t%d\n", iRet);

    /* Finds largest element in linked list */
    iRet = Maximum(Head);
    if(iRet != -1)
        printf("Largest elements is:\t\t%d\n", iRet);

    /* Finds smallest element in linked list */
    iRet = Minimum(Head);
    if(iRet != -1)
        printf("Smallest elements is:\t\t%d\n", iRet);

    /* Addition of all Elements */
    iRet = Add(Head);
    if(iRet != -1)
        printf("Addition of  Elements is:\t\t%d\n", iRet);

    /* Addition of Even Elements */
    iRet = AddEven(Head);
    if(iRet != -1)
        printf("Addition of Even Elements is:\t\t%d\n", iRet);

    /* Addition of odd Elements */
    iRet = AddOdd(Head);
    if(iRet != -1)
        printf("Addition of Odd Elements is:\t\t%d\n", iRet);

    /* counts frequncy of number */
    printf("Enter number for number of occurance:\n");
    scanf("%d", &iNum);
    iRet = CountFreq(Head, iNum);
    if(iRet != -1)
        printf("No. of occurances of %d :\t\t%d\n", iNum, iRet);
    else
        printf("Number not present in List\n");

    /* finds first occuarance of number */
    printf("Enter number for first occurance:\n");
    scanf("%d", &iNum);
    iRet = FirstOccur(Head, iNum);
    if(iRet != -1)
        printf("First Occurance of %d is at :\t\t%d\n", iNum, iRet);
    else
        printf("Element Not Present in linked list\n"); 

    /* finds last occuarance of number */
    printf("Enter number for last occurance:\n");
    scanf("%d", &iNum);
    iRet = LastOccur(Head, iNum);
    if(iRet != -1)
        printf("Last Occurance of %d is at :\t\t%d\n", iNum, iRet);
    else
        printf("Element Not Present in linked list\n");

    /*
    printf("List 2:\n");
    printf("-----------------------------------------------------\n");
    printf("Enter the numbers[enter \'0\' to break]\n");
    while(1)
    {
        scanf("%d", &iNum);
        if(iNum == 0)
        {
            break;
        }
        InsertLast(&Head1, iNum);
    }
    printf("Linked List 2:\n");
    DisplayList(Head1);

    ListCat(Head, Head1);
    DisplayList(Head);

    iRet = IsIntersect(Head, Head1);
    if(iRet != -1)
    {
        printf("Intersect At pos\t:%d\n", iRet);
    }
    else
    {
        printf("Not Intersect\n");
    }
    */

    /* Deallocates all nodes in linked list */
    Deallocate(&Head);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :PNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DisplayList(PNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    while(First != NULL)
    {
        printf("%d->", First->iData);
        First = First->npNext;
    }
    printf("NULL\n\n");
}// end of DisplayList

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :PNODE
//  Returns     :int
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
int CountEls(PNODE First)
{
    int iCnt = 0;
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return iCnt;
    }
    while(First != NULL)
    {
        iCnt++;
        First = First->npNext;
    }
    return iCnt;
}// end of CountEls

////////////////////////////////////////////////////////////
//
//  Name        :Deallocate
//  Input       :PPNODE
//  Returns     :void
//  Description :Deallocates all nodes in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PPNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    
    PNODE nTemp = NULL;
    while(*First != NULL)
    {
        nTemp = *First;
        *First = nTemp->npNext;
        free(nTemp);
    }
}// end of Deallocate

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertLast(PPNODE First, int iNum)
{
    PNODE NewN = NULL;
    NewN = (PNODE)malloc(sizeof(NODE));
    
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return;
    }
    
    NewN->iData = iNum;
    NewN->npNext = NULL;

     /* if linked list is not empty */
    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        PNODE nTemp = *First;
        while(nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext = NewN;
    }    
}// End of InsertLast

////////////////////////////////////////////////////////////
//
//  Name        :Add
//  Input       :PNODE
//  Returns     :int
//  Description :Adds all elemsts in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
int Add(PNODE First)
{
    int iSum = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    while(First != NULL)
    {
        iSum = iSum + First->iData;
        First = First->npNext;
    }
    return iSum;
}// end of Add

////////////////////////////////////////////////////////////
//
//  Name        :AddEven
//  Input       :PNODE
//  Returns     :int
//  Description :Adds Even elemsts in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
int AddEven(PNODE First)
{
    int iEsum = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    while(First != NULL)
    {
        if(First->iData % 2 == 0)
        {
            iEsum = iEsum + First->iData;
        }
        First = First->npNext;
    }
    return iEsum;
}// end of AddEven

////////////////////////////////////////////////////////////
//
//  Name        :AddOdd
//  Input       :PNODE
//  Returns     :int
//  Description :Adds Odd elemsts in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
int AddOdd(PNODE First)
{
    int iOsum = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    while(First != NULL)
    {
        if(First->iData % 2 != 0)
        {
            iOsum = iOsum + First->iData;
        }
        First = First->npNext;
    }
    return iOsum;
}// end of AddOdd

////////////////////////////////////////////////////////////
//
//  Name        :CountFreq
//  Input       :PNODE, int
//  Returns     :int
//  Description :Counts frequecy of particular number
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
int CountFreq(PNODE First, int iNum)
{
    int iCnt = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    while(First != NULL)
    {
        if(First->iData  == iNum)
        {
            iCnt++;
        }
        First = First->npNext;
    }
    return iCnt;
}// end of CountFreq

//////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :PNODE, int
//  Returns     :int
//  Description :returns position of First occurance of number
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////////////////
int FirstOccur(PNODE First, int iNum)
{
    int iPos = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    while(First != NULL)
    {
        iPos++;
        if(First->iData == iNum)
        {
            break;
        }
        First = First->npNext;
    }
    if(iPos != 0)
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
//  Name        :LastOccur
//  Input       :PNODE, int
//  Returns     :int
//  Description :returns position of Last occurance of number
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////////////////
int LastOccur(PNODE First, int iNum)
{
    int iPos = 0, iCnt = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
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
    return iPos;
}// end of LastOccur

//////////////////////////////////////////////////////////////
//
//  Name        :Maximum
//  Input       :PNODE
//  Returns     :int
//  Description :returns largest element in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////////////////
int Maximum(PNODE First)
{
    int iMax = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
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
//  Input       :PNODE
//  Returns     :int
//  Description :returns smallest element in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////////////////
int Minimum(PNODE First)
{
    int iMin = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
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
//  Name        :ListCat
//  Input       :PPNODE, PPNODE
//  Returns     :void
//  Description :concats two lists
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
//////////////////////////////////////////////////////////////
void ListCat(PNODE First1, PNODE First2)
{
    PNODE nTemp = First1;
    while(nTemp->npNext != NULL)
    {
        nTemp = nTemp->npNext;
    }
    nTemp->npNext = First2;
} // end of ListCat

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
int IsIntersect(PNODE First1, PNODE First2)
{
    if (NULL == First1 && NULL == First2)
    {
        printf("Linked Lists is empty\n");
        return -1;
    }
    PNODE nTemp1 = First1;
    PNODE nTemp2 = First2;
    int iDiff = 0, i = 0, iCnt1 = CountEls(First1), iCnt2 = CountEls(First2);
    if(iCnt1 > iCnt2)
    {
        iDiff = iCnt1 - iCnt2;
        for(i = 1; i <= iDiff; i++)
        {
            nTemp1 = nTemp1->npNext;
        }
    }
    else if(iCnt1 < iCnt2)
    {
        iDiff = iCnt2 - iCnt1;
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
