#ifndef _Graph_H

struct ListVertex;
typedef struct ListVertex *Position;
struct GraphStructure;
typedef struct GraphStructure *Graph;
typedef int Vertex;

Graph InitializeGraph(int NumVertex);
void InsertEdge(Graph G, Vertex V, Vertex W, int C);
void Indegree(Graph G);
void Outdegree(Graph G);
void Dijkstra(Graph G, Vertex S);
void path(Vertex V, Vertex W);
#endif