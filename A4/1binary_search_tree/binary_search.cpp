#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

SearchTree ConstructTree(SearchTree &T);
void Inorder(SearchTree T);
void Postorder(SearchTree T);
void Preorder(SearchTree T);
void Levelorder(SearchTree T);
#define MAXNODE 100
void Visit(int e);


SearchTree MakeEmpty(SearchTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X,SearchTree T)
{
    if(T==NULL)
        return NULL;
    if(X<T->Element)
        return Find(X,T->left);
    else if(X>T->Element)
        return Find(X,T->right);
    else 
        return T;
}

Position FindMin(SearchTree T)
{
    if(T==NULL)
        return NULL;
    if(T->left==NULL)
        return T;
    else
        return FindMin(T->left);
}

Position FindMax(SearchTree T)
{
    if(T==NULL)
        return NULL;
    else if(T->right==NULL)
        return T;
    else
        return FindMax(T->right);
}

SearchTree Insert(ElementType X,SearchTree T)
{
    if(T==NULL)
    {
        T = (TreeNode*)malloc(sizeof(struct TreeNode));
        if(T==NULL)
            printf("Out of space!!!");
        else
        {
            T->Element=X;
            T->left=T->right=NULL;
        }
    }
    else if(X<T->Element)
        T->left=Insert(X,T->left);
    else if(X>T->Element)
        T->right=Insert(X,T->right);
    return T;
}

SearchTree Delete(ElementType X,SearchTree T)
{
    Position TmpCell;
    if(T==NULL)
        printf("Element not found");
    else if(X<T->Element)
        T->left=Delete(X,T->left);
    else if(X>T->Element)
        T->right=Delete(X,T->right);
    else if(T->left&&T->right)
    {
        TmpCell=FindMin(T->right);
        T->Element=TmpCell->Element;
        T->right=Delete(X,T->right);
    }
    else
    {
        TmpCell=T;
        if(T->left==NULL)
            T=T->right;
        else if(T->right=NULL)
            T=T->left;
        free(TmpCell);
    }
    return T;
}

ElementType Retrieve(Position P)
{
    if(P==NULL)
        return -1;
    else
        return P->Element;
}


SearchTree ConstructTree(SearchTree *T)
{
	int arr[13] = {10, 4, 2, 1, 3, 6, 5, 8, 7, 9, 11, 12, 13};
	int i;
	for(i = 0; i <13; i++)
	{
		*T = Insert(arr[i],*T);
	}
	return *T;
}

int main()
{
	SearchTree Tree = NULL;
	ConstructTree(&Tree);
	printf("Inorder: ");
	Inorder(Tree);
	printf("\n");
	printf("Postorder: ");
	Postorder(Tree);
	printf("\n");
	printf("Preorder: ");
	Preorder(Tree);
	printf("\n");
	printf("Levelorder: ");
	Levelorder(Tree);
	printf("\n");
    system("pause");
	return 0;
}


void Inorder(SearchTree T)
{ 
	if(T!=NULL) // (T==NULL) is the Base case
	{ 
		Inorder(T->left); // Inorder traverse left
		Visit(T->Element); // Visit current element
		Inorder(T->right); // Inorder traverse right
	}
}

void Postorder(SearchTree T)
{ 
	if(T!=NULL) // (T==NULL) is Base condition
	{ 
		Postorder(T->left); // Postorder traverse left
		Postorder(T->right); // Postorder traverse right
		Visit(T->Element); // Visit current element
	}
}

void Preorder(SearchTree T)
{ 
	if(T!=NULL) // (T==NULL) is Base condition
	{ 
		Visit(T->Element); // Visit current element
		Preorder(T->left); // Preorder traverse left
		Preorder(T->right); // Preorder traverse right
	}
}

void Levelorder(SearchTree T)
{ 
	SearchTree Queue[MAXNODE];
	int front, rear;
	if (T==NULL) return; // If the T is null, quit the routine
	front=-1; rear=0; // Initialize front and rear
	Queue[rear]=T; // Enqueue Root
	while(front!=rear)
	{ 
		front++; // Dequeue front
		Visit(Queue[front]->Element); // Visit front node, e.g., print
		if(Queue[front]->left!=NULL) // Enqueue front node¡¯s left child
		{ 
			rear++; Queue[rear]=Queue[front]->left; 
		}
		if(Queue[front]->right!=NULL) // Enqueue front node¡¯s right child
		{ 
			rear++; Queue[rear]=Queue[front]->right; 
		}
}
}


void Visit(int e)
{
	printf("%d ", e);
}