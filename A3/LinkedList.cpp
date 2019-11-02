

#include <stdio.h>
#include "List.h"
#include "stdlib.h"

struct Node {
	int Element;
	Position Next;
};


// Make List empty and return the head of the emptied list
List MakeEmpty(List L)
{
	if(L==NULL) 
	{
		printf("The list does not exist!\n");
		return NULL;
	}
	else 
	{
		L->Next = NULL;
		return L;
	}
}

// Return 1 if L is empty, 0 if not empty, -1 if not exist
int IsEmpty(List L) 
{
	if(L != NULL) 
		return (L->Next == NULL);
	else 
	{
		printf("The list does not exist!\n");
		return -1;
	}
}

// Return 1 if P is the last position in L
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

// Return position of X in L; NULL if not found
Position Find(int X, List L) 
{
	Position P;
	if(L!=NULL) 
	{
		P = L->Next;
		while(P!=NULL && P->Element != X) 
		{
			P = P->Next;
		}
		return P;
	}
	else 
	{
		printf("The list does not exist!\n");
		return NULL;
	}
}

// Return previous position of X in L, or the last node's position if X is not found, or NULL if L not exist
Position FindPrevious(int X, List L) 
{
	Position P;
	if(L!=NULL) 
	{
		P = L;
		while(P->Next != NULL && P->Next->Element != X)
			P = P->Next;
		return P;
	}
	else 
	{
		printf("The list does not exist!\n");
		return NULL;
	}
}

// Delete the first X in L
void Delete(int X, List L) 
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if(!IsLast(P, L) || P != NULL) 
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

// Insert after P
void Insert(int X, List L, Position P) 
{
	Position TmpCell;
	TmpCell = (struct Node*)malloc(sizeof(struct Node)); //在加入(struct Node*)之前，报错显示无法从“void *”转换为“Position”，故强制转换
	if(TmpCell == NULL) 
	{
		printf("Out of Space\n");
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

// Insert before P = insert after P + exchange the elements
void InsertBefore(int X, List L, Position P)
{
	Position TmpCell;
	int Tmp;
	TmpCell = (struct Node*)malloc(sizeof(struct Node));
	if(TmpCell == NULL) 
	{
		printf("Out of Space\n");
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	//Exchange Element
	Tmp = P->Element;
	P->Element = P->Next->Element;
	P->Next->Element = Tmp;
}

// Delete List and free all the storage spacce
void DeleteList(List L) 
{
	Position P, Tmp;
	if(L!=NULL) 
	{
		P = L;
		while(P!=NULL) 
		{
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
}

// Get the Header of the List
Position Header(List L) 
{
	return L;
}

// Return the position of the first element 
Position First(List L) 
{
	Position P;
	P = L->Next;
	return P;
}

// Advance to the next Position
Position Advance(Position P) 
{
	if(P != NULL) 
	P = P->Next;
	return P;
}

// Retrieve the element value at the Position P
int Retrieve(Position P) 
{
	int element;
	if(P != NULL) 
		element = P->Element;
	return element;
}

void main() 
{
	List L;
	L = (List) malloc(sizeof(List));
	Insert(10, L, L);
	getchar();
}