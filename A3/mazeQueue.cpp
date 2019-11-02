

#include <stdio.h>
#include "stdlib.h"


typedef struct QueueRecord *Queue;

typedef struct Node 
{
	int x;
	int y;
	int pre;
}Node;

typedef struct QueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	Node *array;
}QueueRecord;

Queue CreateQueue(int MaxElements);
void Enqueue(Queue Q, int i, int j, int preN);
Node Dequeue(Queue Q);
Node Front(Queue Q);
void Solution(Queue Q, int width, int depth, int** a);
void MakeEmpty(Queue Q);


int main() 
{
	Queue Q;
	int **a;
	int width, depth, i, j;
	printf("Please input m and n to construct a m * n maze\n");
	scanf_s("%d%d",&width,&depth);
	a = (int **)malloc(sizeof(int*) * depth);
	for(i = 0; i < depth;i++)
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
	Q = CreateQueue(depth * width);
	Solution(Q, width, depth, a);
	free(a);
}

// Breadth first search: set the searched location 0 and never search it again
void Solution(Queue Q, int width, int depth, int** a)
{
	Node tmp;
	int pos, i;
	int dic[8][2] = {{1,1}, {1,0}, {1,-1}, {0,1}, {0,-1}, {-1,1}, {-1,0}, {-1,1}};
	if (a[0][0] != 1)
	{
		printf("No Solution!\n");
		return;
	}
	a[0][0] = 0;
	Enqueue(Q, 0, 0, -1);
	while(a[width-1][depth-1] != 0 && Q->size != 0) 
	{
		pos = Q->front;
		tmp = Dequeue(Q);
		for(i = 0; i < 8; i++) 
		{
			if(tmp.x + dic[i][0] < width && tmp.x + dic[i][0] >= 0 && 
			tmp.y + dic[i][1] < depth && tmp.y + dic[i][1] >= 0 && 
			a[tmp.x + dic[i][0]][tmp.y + dic[i][1]] == 1) 
			{
				a[tmp.x + dic[i][0]][tmp.y + dic[i][1]] = 0;
				Enqueue(Q, tmp.x + dic[i][0], tmp.y + dic[i][1], pos);
				if (tmp.x + dic[i][0] == width - 1 && tmp.y + dic[i][1] == depth - 1) break;
			}
		}
	}
	if (Q->size == 0) 
	{
		printf("No Solution!\n");
		return;
	}
	pos = Q->rear;
	while(Q->array[pos].pre != -1) 
	{
		printf("(%d, %d)<-",Q->array[pos].x+1, Q->array[pos].y+1);
		pos = Q->array[pos].pre;
	}
	printf("(1, 1)\n");
}

QueueRecord* CreateQueue(int MaxElements) 
{
	Queue Q = (QueueRecord *) malloc(sizeof(QueueRecord));
	MakeEmpty(Q);
	if (MaxElements < 5) printf("Queue Record size is too small!!!\n");
	Q->array = (Node *) malloc(sizeof(Node) * MaxElements);
	if(Q->array == NULL) {
		printf("Out of Space!!!\n");
		exit(0);
	}
	Q->capacity = MaxElements;
	return Q;
}

void MakeEmpty(Queue Q){
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

void Enqueue(Queue Q, int i, int j, int preN)
{
	if(Q->size == Q->capacity) printf("Full Queue!!!\n");
	else 
	{
		Q->size++;
		Q->rear++;
		Q->array[Q->rear].x = i;
		Q->array[Q->rear].y = j;
		Q->array[Q->rear].pre = preN;
	}
}

Node Front(Queue Q) 
{
	if (Q->size > 0) return Q->array[Q->front];
	else 
	{
		printf("Empty Queue!!!\n");
		return Q->array[Q->front];
	}
}

Node Dequeue(Queue Q) 
{
	Node X;
	if(Q->size == 0) 
	{
		printf("Empty Queue!!!\n");
		exit(0);
	}
	else 
	{
		Q->size--;
		X = Q->array[Q->front];
		Q->front = (Q->front + 1) % Q->capacity;
		return X;
	}
}
