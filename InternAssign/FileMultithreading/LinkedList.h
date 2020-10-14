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
} NODE, *PNODE, **PPNODE;

typedef struct resource
{
	PNODE Head;
	BOOL bIsLocked;
}RESOURCE;

void InsertFirst(PPNODE, PCHAR);
void InsertLast(PPNODE, PCHAR);
void InsertAtPos(PPNODE, PCHAR, int);
void DisplayList(PNODE);
void Deallocate(PPNODE);
int CountEls(PNODE);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeleteAtPos(PPNODE, int);
