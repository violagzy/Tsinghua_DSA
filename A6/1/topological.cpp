// topological.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "stdlib.h"
#include "graph.h"

void ReadGraph(Graph *G);
void OptTopsort(Graph G);

struct ListVertex
{
	Vertex AdjVertex;
	Position NextAdj;
	int Cost;
};

typedef Position List;

struct GraphStructure 
{
	int NumVertex;
	List *TheVertices;
};

int Indeg[1000];
int Outdeg[1000];

void main() 
{
	Graph g;
	ReadGraph(&g);
	Indegree(g);
	OptTopsort(g);
	getchar();
}

void ReadGraph(Graph *G)
{
	*G = InitializeGraph(7);
	// Insert
	InsertEdge(*G, 0, 1);
	InsertEdge(*G, 0, 2);
	InsertEdge(*G, 0, 3);
	InsertEdge(*G, 1, 3);
	InsertEdge(*G, 1, 4);
	InsertEdge(*G, 2, 5);
	InsertEdge(*G, 3, 2);
	InsertEdge(*G, 3, 5);
	InsertEdge(*G, 3, 6);
	InsertEdge(*G, 4, 3);
	InsertEdge(*G, 4, 6);
	InsertEdge(*G, 6, 5);
}

Graph InitializeGraph(int NumVertex)
{
	Graph G; int i;
	G = (Graph)malloc(sizeof(struct GraphStructure));
	if(G == NULL)
	{
		printf("Out of space!!\n");
		return NULL;
	}
	G->NumVertex = NumVertex;
	G->TheVertices = (List *)malloc(sizeof(List) * (G->NumVertex));
	if(G->TheVertices == NULL) 
	{
		printf("Out of space!!\n");
		return NULL;
	}
	for(i = 0; i < G->NumVertex; i++) 
	{
		G->TheVertices[i] = (List)malloc(sizeof(struct ListVertex));
		if(G->TheVertices[i] == NULL) 
		{
			printf("Out of space!!\n");
			return NULL;
		}
		else G->TheVertices[i]->NextAdj = NULL;
	}
	return G;
}

void InsertEdge(Graph G, Vertex V, Vertex W)
{
	List Pos;
	List NewCell;
	Pos = G->TheVertices[V];
	while(Pos->NextAdj != NULL && Pos->NextAdj->AdjVertex != W)
	{
		Pos = Pos->NextAdj;
	}
	if(Pos->NextAdj != NULL) return;
	NewCell = (List)malloc(sizeof(struct ListVertex));
	if(NewCell == NULL) {
		printf("Out of space!!\n");
		return;
	}
	else {
		Pos->NextAdj = NewCell;
		NewCell->AdjVertex = W;
		NewCell->NextAdj = NULL;
	}
}

void Outdegree(Graph G)
{
	int i; List Pos;
	for(i = 0; i < G->NumVertex; i++) {Outdeg[i] = 0;}
	for(i = 0; i < G->NumVertex; i++) {
		Pos = G->TheVertices[i]->NextAdj;
		while(Pos->NextAdj != NULL) {
			Outdeg[i]++;
			Pos = Pos->NextAdj;
		}
	}
}

void Indegree(Graph G)
{
	int i; List Pos;
	for(i = 0; i < G->NumVertex; i++) 
	{
		Indeg[i] = 0;
	}
	for(i = 0; i < G->NumVertex; i++) 
	{
		Pos = G->TheVertices[i]->NextAdj;
		while(Pos != NULL) 
		{
			Indeg[Pos->AdjVertex]++;
			Pos = Pos->NextAdj;
		}
	}
}

void OptTopsort(Graph G)
{
	int i, Rear = -1, Head = 0;
	Vertex TopSortQueue[1000];
	List Pos;
	for(i = 0; i < G->NumVertex; i++) 
	{
		if(Indeg[i] == 0) TopSortQueue[++Rear] = i;
	}
	while(Head <= Rear) 
	{
		Pos = G->TheVertices[TopSortQueue[Head++]]->NextAdj;
		while(Pos != NULL) 
		{
			if(--Indeg[Pos->AdjVertex] == 0) 
			{
				TopSortQueue[++Rear] = Pos->AdjVertex;
			}
			Pos = Pos->NextAdj;
		}
	}
	if(Rear < G->NumVertex-1) 
	{
		printf("Graph has a cycle!\n");
	}
	else 
	{
		for(i = 0; i < G->NumVertex - 1; i++)
			printf("%d ", TopSortQueue[i]);
		printf("%d\n", TopSortQueue[G->NumVertex - 1]);
	}
}
