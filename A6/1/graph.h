#ifndef _Graph_H

struct ListVertex;
typedef struct ListVertex *Position;
struct GraphStructure;
typedef struct GraphStructure *Graph;
typedef int Vertex;

Graph InitializeGraph(int NumVertex);
void InsertEdge(Graph G, Vertex V, Vertex W);
void Indegree(Graph G);
void Outdegree(Graph G);

#endif