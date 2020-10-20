/* Singly Linear Linked List*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 1024
#define MAXTHREAD 10

typedef int INDEX;
typedef struct node
{
    INDEX index;
    PCHAR szData;
    struct node *npNext;
} NODE, *PNODE, **PPNODE;

void InitializeHead(PPNODE);
void UninitializeHead(PPNODE);
void InsertFirst(PNODE, PCHAR, INDEX);
void InsertLast(PNODE, PCHAR, INDEX);
void InsertAtPos(PNODE, PCHAR, int, INDEX);
void DisplayList(PNODE);
void Deallocate(PNODE);
int  CountEls(PNODE);
void DeleteFirst(PNODE);
void DeleteLast(PNODE);
void DeleteAtPos(PNODE, int);
void SortList(PNODE);
