#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

// Generalized Structure of node For Singly Linked List
template <class T>
struct node
{
	T Data;
	struct node *Next;
};

// Generalized Structure of node For Queue
template <class T>
struct qnode
{
	int P;
	T data;
	struct qnode *next;
};

// Generalized Structure of node For Stack
template <class T>
struct snode
{
	T data;
	struct snode *next;
};

// Generalized Structure of node For Doubly Linked List
template <class T>
struct dnode
{
	T Data;
	struct dnode *Next;
	struct dnode *Prev;
};

template <class T>
struct tnode
{
	T data;
	struct tnode<T> *lchild;
	struct tnode<T> *rchild;
};

//Abstract Class of Linked_List
template <class T>
class Linked_List
{
protected:
	virtual void InsertFirst(T) = 0;
	virtual void InsertLast(T) = 0;
	virtual void InsertAtPos(T, int) = 0;
	virtual void Display() = 0;
	virtual int Count() = 0;
	virtual void DeleteFirst() = 0;
	virtual void DeleteLast() = 0;
	virtual void DeleteAtPos(int) = 0;
};
