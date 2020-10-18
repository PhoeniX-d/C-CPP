/* Singly Linear Linked List*/


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 100

typedef struct node
{
    PCHAR szData;
    struct node *npNext;
} NODE, *PNODE;

void InsertFirst(PNODE, PCHAR);
void InsertLast(PNODE, PCHAR);
void InsertAtPos(PNODE, PCHAR, int);
void DisplayList(PNODE);
void Deallocate(PNODE);
int  CountEls(PNODE);
void DeleteFirst(PNODE);
void DeleteLast(PNODE);
void DeleteAtPos(PNODE, int);
