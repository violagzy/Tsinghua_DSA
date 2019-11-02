

#include <stdio.h>
#include "Queue.h"
#include "stdlib.h"

#define MinQueueSize (5)

struct QueueRecord 
{
	int capacity;
	int front;
	int rear;
	int size;
	int *array;
};

int IsEmpty(Queue Q) 
{
	return Q->size == 0;
}

int IsFull(Queue Q) 
{
	return Q->size == Q->capacity;
}

Queue CreateQueue(int MaxElements) 
{
	Queue Q;
	if(MaxElements < MinQueueSize) printf("Queue size is too small!!!\n");
	Q = (Queue) malloc(sizeof(struct QueueRecord));
	if(Q == NULL) 
	{
		printf("Out of Space!!!\n");
		return NULL;
	}
	Q->array = (int *) malloc(sizeof(int)*MaxElements);
	if(Q->array == NULL) 
	{
		printf("Out of Space!!!\n");
		return NULL;
	}
	Q->capacity = MaxElements;
	MakeEmpty(Q);
	return Q;
}

void DisposeQueue(Queue Q)
{
	if(Q != NULL) 
	{
		free(Q->array);
		free(Q);
	}
}
void MakeEmpty(Queue Q)
{
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

void Enqueue(int X, Queue Q){
	if(IsFull(Q)) printf("Full Queue!!!\n");
	else {
		Q->size++;
		Q->rear = (Q->rear+1)% Q->capacity;
		Q->array[Q->rear] = X;
	}
}

int Front(Queue Q) 
{
	if(Q->size > 0) return Q->array[Q->front];
	else 
	{
		printf("Empty Queue!!!\n");
		return -1;
	}
}
int Dequeue(Queue Q) 
{
	int X;
	if(IsEmpty(Q)) 
	{
		printf("Empty Queue!!!\n");
		return -1;
	}
	else 
	{
		Q->size--;
		X = Q->array[Q->front];
		Q->front = (Q->front+1)% Q->capacity;
		return X;
	}
}


void main() 
{
	Queue q;
	q = CreateQueue(10);
	Enqueue(5, q);
	Enqueue(10, q);
	printf("%d", Dequeue(q));
	getchar();
}