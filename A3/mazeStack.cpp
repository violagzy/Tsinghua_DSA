
#include <stdio.h>
#include "stdlib.h"

typedef struct Node
{
    int x;
    int y;
    int pre;
}Node;

typedef struct StackRecord
{
    int capacity;
    int topofstack;
    Node *array;
}StackRecord;

typedef StackRecord *Stack;
Stack createStack(int);
void push(Stack, int, int, int);
Node top(Stack);
void pop(Stack);
void solution(Stack, int, int, int**);

void main() 
{
    Stack s;
	int **a;
	int width, depth, i, j;
	printf("Please input m and n to construct a m * n maze\n");
	scanf_s("%d%d",&width,&depth);
	a = (int **)malloc(sizeof(int*) * depth);
	for(i = 0; i < depth; i++)
		a[i] = (int *)malloc(sizeof(int) * width);
	for(i = 0; i < depth; i++)
		for(j = 0; j < width; j++) 
		{
			scanf_s("%d",&a[i][j]);
		}
	for(i = 0; i < depth; i++) 
	{
		for(j = 0; j < width; j++) 
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	s = createStack(depth * width);
	solution(s, width, depth, a);
	free(a);
}

// Deep first search using stack: set the searched location 0 and pop the top if there is no way to go
void solution(Stack s, int width, int depth, int** a)
{
	Node tmp;
	int pos, i, flag;
	int dic[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};
	if (a[0][0] != 1)
	{
		printf("No Solution!\n");
		return;
	}
	a[0][0] = 0;
	push(s, 0, 0, -1);
	while(a[width-1][depth-1] != 0 && s->topofstack != -1) 
	{
		pos = s->topofstack;
		tmp = top(s);
		flag = 0;
		for(i = 0; i < 4; i++) 
		{
			if(tmp.x + dic[i][0] < width && tmp.x + dic[i][0] >= 0 && 
			tmp.y + dic[i][1] < depth && tmp.y + dic[i][1] >= 0 && 
			a[tmp.x + dic[i][0]][tmp.y + dic[i][1]] == 1) 
			{
				flag++;
				a[tmp.x + dic[i][0]][tmp.y + dic[i][1]] = 0;
				push(s, tmp.x + dic[i][0], tmp.y + dic[i][1], pos);
				if (tmp.x + dic[i][0] == width - 1 && tmp.y + dic[i][1] == depth - 1) break;
			}
		}
		if(flag == 0) pop(s);
	}
	if (s->topofstack== -1) 
	{
		printf("No Solution!\n");
		return;
	}
	pos = s->topofstack;
	while(s->array[pos].pre != -1) 
	{
		printf("(%d, %d)<-",s->array[pos].x+1, s->array[pos].y+1);
		pos = s->array[pos].pre;
	}
	printf("(1, 1)\n");
}

Stack createStack(int MaxElements) 
{
    Stack s;
    s = (Stack) malloc(sizeof(struct StackRecord));
    if(s == NULL) 
	{
        printf("Out of Space!!!\n"); return NULL;
    }
    s->array = (Node *) malloc(sizeof(Node) * MaxElements);
    if(s->array == NULL) 
	{
        printf("Out of Space!!!\n"); return NULL;
    }
    s->capacity = MaxElements;
    s->topofstack = -1;
	return s;
}

void push(Stack s, int i, int j, int preN) 
{
    Node newNode;
    newNode.x = i; newNode.y = j; newNode.pre = preN;
    if(s->topofstack == s->capacity - 1) printf("Full Stack!!!\n");
    else 
	{
        s->topofstack ++;
        s->array[s->topofstack] = newNode;
    }
}

Node top (Stack s) 
{
    if(s->topofstack != -1) return s->array[s->topofstack];
	else 
	{
		printf("Empty Stack!!!\n");
		exit(0);
	}
}

void pop(Stack s) 
{
    if(s->topofstack == -1) printf("Empty Stack!!\n");
    else s->topofstack--;
}
