// AVL.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#define Max(a,b) ((a)>(b)?(a):(b))

Position SingleRotateWithLeft(Position K2);
Position SingleRotateWithRight(Position K2);
Position DoubleRotateWithLeft(Position K3);
Position DoubleRotateWithRight(Position K3);

void PrintTreeEdge(AvlTree T);


int Height(Position P)
{ 
	if(P==NULL)
		return -1;
	else
		return P->Height;
}

AvlTree Insert(int X, AvlTree T)
{ 
	if(T==NULL)
	{ 
		T = (AvlNode*) malloc(sizeof(struct AvlNode));
		if(T==NULL) 
		{ 
			printf("Out of space!!!\n"); 
			return NULL;
		}
		else 
		{ 
			T->Element = X; 
			T->Height = 0; 
			T->Left = NULL; 
			T->Right = NULL; 
		}
	}
	else if(X<T->Element)
	{ 
		T->Left = Insert(X, T->Left);
		if(Height(T->Left) - Height(T->Right) == 2)
		{ 
			if(X<T->Left->Element) T = SingleRotateWithLeft(T);
			else T = DoubleRotateWithLeft(T);
		}
	}
	else if(X>T->Element)
	{ 
		T->Right = Insert(X, T->Right);
		if(Height(T->Right) - Height(T->Left) == 2)
		{ 
			if(X>T->Right->Element) T = SingleRotateWithRight(T);
			else T = DoubleRotateWithRight(T);
		}
	}
	// Else X is in the tree already; we’ll do nothing
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

Position SingleRotateWithLeft(Position K2) // Case (1), i.e., "/"
{ 
	Position K1; // Rotate centered with K1
	K1 = K2->Left; // Assign K1 as the left subtree of K2
	K2->Left = K1->Right; // Link Y as left subtree of K2
	K1->Right = K2; // Link K2 as right subtree of K1
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K2)) + 1;
	return K1; // New root of current sub-tree
}

Position SingleRotateWithRight(Position K2) // Case (4), i.e., "\"
{
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Right), Height(K2)) + 1;
	return K1;
}

Position DoubleRotateWithLeft(Position K3)
{ 
	// Rotate centered with K2
	K3->Left = SingleRotateWithRight(K3->Left);
	// Rotate centered with K2
	return SingleRotateWithLeft(K3);
}

Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}



int main()
{
	AvlTree Tree = NULL;

	int i = 0;
	int a[100];
	FILE *fpRead;
	errno_t err;  //判断此文件流是否存在 存在返回1
	err = fopen_s(&fpRead,"input.txt", "r");

    if(fpRead==NULL)  
    {  
        return 0;  
    }  
	for(i = 0;i < 100;i++)
	{
		fscanf_s(fpRead,"%d ",&a[i]);
		if(a[i] < 0) break;
		Tree = Insert(a[i], Tree);
	}

	printf("Now print all edges in forms of parent -> node: \n");
	PrintTreeEdge(Tree);
	return 0;
}

void PrintTreeEdge(AvlTree T)
 {

	 if(T != NULL)
	 {

		 if(T->Left!=NULL)
		 {
			 printf("%d -> %d\n", T->Element, T->Left->Element);
		 }
		 if(T->Right!=NULL)
		 {
			 printf("%d -> %d\n", T->Element, T->Right->Element);
		 }
		 PrintTreeEdge(T->Left);
		 PrintTreeEdge(T->Right);

	 }
 }