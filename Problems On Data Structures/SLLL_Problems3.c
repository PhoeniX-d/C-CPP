/*
*   Implementaion of Singly Linear Linked List
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node     *cpNext;
} NODE, *PNODE, **PPNODE;

// global declarations
void InsertLast(PPNODE, int);
void DisplayList(PNODE);
void Deallocate(PPNODE);
void ListReverse(PNODE);
void DisplayPalindrome(PNODE);
void SmallestDigit(PNODE);
void LargestDigit(PNODE);
void ProdDigits(PNODE);

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 1----------\n\n");
    PNODE Head = NULL;
    int iRet = 0, i = 0, iNo = 0, iNum = 0;

    printf("Enter Number of elements\n");
    scanf("%d", &iNo);
    printf("Enter the numbers\n");
    for (i = 1; i <= iNo; i++)
    {
        scanf("%d", &iNum);
        InsertLast(&Head, iNum);
    }
    printf("Linked List:\n");
    DisplayList(Head);

    /* Reverses the Linked list */
    ListReverse(Head);
    printf("Linked List in Reverse order\n");
    DisplayList(Head);

    /* Displays Palindrome numbers in a linked list */
    printf("Palindrome numbers in linked list are\n");
    DisplayPalindrome(Head);
    

    /* Product of Digits */
    printf("Product of Digits of entered elements are\n");
    ProdDigits(Head);
    

    /* Displays smallest digits from elements in a linked list */
    printf("Smallest Digits from elements in a linked list are\n");
    SmallestDigit(Head);
    
    /* Displays largest digits from elements in a linked list */
    printf("Largest Digits from elements in a linked list are\n");
    LargestDigit(Head);

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
//  Date        :30 Aug 2020
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
        First = First->cpNext;
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
//  Date        :30 Aug 2020
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
        First = First->cpNext;
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
//  Date        :30 Aug 2020
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
        *First = nTemp->cpNext;
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
//  Date        :30 Aug 2020
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
    NewN->cpNext = NULL;

     /* if linked list is not empty */
    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        PNODE nTemp = *First;
        while(nTemp->cpNext != NULL)
        {
            nTemp = nTemp->cpNext;
        }
        nTemp->cpNext = NewN;
    }    
}// End of InsertLast

//////////////////////////////////////////////////////////////////////////
//
//  Name        :ListReverse
//  Input       :PNODE
//  Returns     :void
//  Description :Function which reverse each element of singly linked list
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
//////////////////////////////////////////////////////////////////////////
void ListReverse(PNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    PNODE nTemp = First;
    int *iArr = NULL, i = 0;
    iArr = (int *)malloc(sizeof(int) * CountEls(First));
    if(iArr == NULL)
    {
        printf("Memory allocation failed\n");
    }

    while(nTemp != NULL)
    {
        iArr[i++] = nTemp->iData;
        nTemp = nTemp->cpNext;
    }
    nTemp = First;
    while(nTemp != NULL)
    {
        nTemp->iData = iArr[--i];
        nTemp = nTemp->cpNext;
    }
}// end of ListReverse

//////////////////////////////////////////////////////////////////////////
//
//  Name        :DisplayPalindrome
//  Input       :PNODE
//  Returns     :void
//  Description :display palindrome elements in singly linked list
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
//////////////////////////////////////////////////////////////////////////
void DisplayPalindrome(PNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    int iTemp = 0, iRev = 0;
    char cFlag = 0;
    while(NULL != First)
    {
        iTemp = First->iData;
        iRev = 0;
        while(iTemp != 0)
        {
            iRev = iRev * 10 + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        if(First->iData == iRev)
        {
            printf("%d ", First->iData);
            cFlag = 1;
        }
        First = First->cpNext;
    }
    if(cFlag == 0)
    {
        printf("No Palindrome numbers\n");
    }
    else
    {
        printf("\n");
    }
    
}// end of DisplayPalindrome

//////////////////////////////////////////////////////////////
//
//  Name        :ProdDigits
//  Input       :PNODE
//  Returns     :void
//  Description :computes product of elements digits
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
//////////////////////////////////////////////////////////////
void ProdDigits(PNODE First)
{
    if(NULL == First)
    {
        printf("Linked list is empty\n");
        return;
    }
    int iDigProd = 0, iTemp = 0;

    while(First != NULL)
    {
        iTemp = 0;
        iDigProd = 1;
        iTemp = First->iData;
        if(iTemp == 0)
        {
            iDigProd = 0;
        }
        while(iTemp != 0)
        {
            if(iTemp % 10 != 0)
            {
                iDigProd = iDigProd * (iTemp % 10);
            }           
            iTemp = iTemp / 10;
        }
        printf("%d ", iDigProd);
        First = First->cpNext;
    }
    printf("\n");
}// end of ProdDigits

//////////////////////////////////////////////////////////////
//
//  Name        :SmallestDigit
//  Input       :PNODE
//  Returns     :void
//  Description :computes smallest digits of elements in LL
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
//////////////////////////////////////////////////////////////
void SmallestDigit(PNODE First)
{
    if(NULL == First)
    {
        printf("Linked list is empty\n");
        return;
    }
    int iSmallDig = 0, iTemp = 0;

    while(First != NULL)
    {
        iTemp = 0;
        iSmallDig = 0;
        iTemp = First->iData;
        iSmallDig = iTemp % 10;
        while(iTemp != 0)
        {
            if(iTemp % 10 < iSmallDig)
            {
                iSmallDig = iTemp % 10;
            }           
            iTemp = iTemp / 10;
        }
        printf("%d ", iSmallDig);
        First = First->cpNext;
    }
    printf("\n");
}// end of SmallestDigit

//////////////////////////////////////////////////////////////
//
//  Name        :LargestDigit
//  Input       :PNODE
//  Returns     :void
//  Description :computes Largest digits of elements in LL
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
//////////////////////////////////////////////////////////////
void LargestDigit(PNODE First)
{
    if(NULL == First)
    {
        printf("Linked list is empty\n");
        return;
    }
    int iLargeDig = 0, iTemp = 0;

    while(First != NULL)
    {
        iTemp = 0;
        iLargeDig = 0;
        iTemp = First->iData;
        iLargeDig = iTemp % 10;
        while(iTemp != 0)
        {
            if(iTemp % 10 > iLargeDig)
            {
                iLargeDig = iTemp % 10;
            }           
            iTemp = iTemp / 10;
        }
        printf("%d ", iLargeDig);
        First = First->cpNext;
    }
    printf("\n");
}// end of LargestDigit