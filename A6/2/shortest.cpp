// shortest.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdio.h>
#include "stdlib.h"
#include "dijkgraph.h"

void ReadGraph(Graph *G);

struct TableEntry
{
	int Known;
	int Dist;
	Vertex Path;
}T[1000];


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


	Dijkstra(g, 0);
	int i;
	for(i = 1; i < g->NumVertex; i++) 
	{
		printf("Distance from 0 to %d: %d\n", i, T[i].Dist);
		path(0, i);
		printf("\n");
	}
	getchar();
}

void ReadGraph(Graph *G)
{
	*G = InitializeGraph(7);
	// Insert
	InsertEdge(*G, 0, 1, 2);
	InsertEdge(*G, 0, 3, 1);
	InsertEdge(*G, 1, 3, 3);
	InsertEdge(*G, 1, 4, 10);
	InsertEdge(*G, 2, 0, 4);
	InsertEdge(*G, 2, 5, 5);
	InsertEdge(*G, 3, 2, 2);
	InsertEdge(*G, 3, 4, 2);
	InsertEdge(*G, 3, 5, 8);
	InsertEdge(*G, 3, 6, 4);
	InsertEdge(*G, 4, 6, 6);
	InsertEdge(*G, 6, 5, 1);
}

void Dijkstra(Graph G, Vertex S)
{
	int i, min; Vertex V; List Pos;
	for(i = 0; i < G->NumVertex; i++) {
		T[i].Known = 0; T[i].Dist = 10000; T[i].Path = -1;
	}
	T[S].Dist = 0;
	while(1) 
	{
		min = 10000; V = -1;
		for(i = 0; i < G->NumVertex; i++) 
		{
			if(T[i].Known != 1 && T[i].Dist < min) 
			{
				min = T[i].Dist; V = i;
			}
		}
		if(V == -1) break;
		T[V].Known = 1; Pos = G->TheVertices[V]->NextAdj;
		while(Pos != NULL) 
		{
			if(T[Pos->AdjVertex].Known != 1) 
			{
				if(T[V].Dist + Pos->Cost < T[Pos->AdjVertex].Dist) 
				{
					T[Pos->AdjVertex].Dist = T[V].Dist + Pos->Cost;
					T[Pos->AdjVertex].Path = V;
				}
			}
			Pos = Pos->NextAdj;
		}
	}
}

void path(Vertex V, Vertex W)
{
	Vertex end;
	end = W;
	while(end != V) 
	{
		printf("%d<--", end);
		end = T[end].Path;
	}
	printf("%d\n", V);
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

void InsertEdge(Graph G, Vertex V, Vertex W, int C)
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
		NewCell->Cost = C;
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
	for(i = 0; i < G->NumVertex; i++) {
		Indeg[i] = 0;
	}
	for(i = 0; i < G->NumVertex; i++) {
		Pos = G->TheVertices[i]->NextAdj;
		while(Pos != NULL) {
			Indeg[Pos->AdjVertex]++;
			Pos = Pos->NextAdj;
		}
	}
}