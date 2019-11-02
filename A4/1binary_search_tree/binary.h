#ifndef _Tree_H
#define ElementType int

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
int Retrieve(Position P);

#endif /* _Tree_H */


struct TreeNode 
{
    ElementType Element;
    SearchTree left;
    SearchTree right;
};

