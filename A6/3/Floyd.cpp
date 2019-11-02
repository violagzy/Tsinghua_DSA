// Floyd.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "stdlib.h"

void Floyd(int A[][4], int);

void main()
{
	int i, j, n;
	int a[4][4] = {{0, 3, 2, INT_MAX/2},
	{INT_MAX/2, 0, 8, INT_MAX/2},
	{INT_MAX/2, INT_MAX/2, 0, 6},
	{7, 5, INT_MAX/2, 0}};
	n = 4;
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			if(a[i][j] == INT_MAX/2) printf("-1 "); else printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	Floyd(a, 4);
	getchar();
}

void Floyd(int A[][4], int NumVertex)
{
	int v, w, k, D[100][100], Path[100][100];
	for(v=0; v < NumVertex; v++) 
	{
		for(w=0; w < NumVertex; w++)
		{
			D[v][w] = A[v][w]; Path[v][w] = -1;
		}
	}
	for(k = 0; k < NumVertex; k++) 
	{
		for(v = 0; v < NumVertex; v++) 
		{
			for(w = 0; w < NumVertex; w++) 
			{
				if(D[v][w] > D[v][k] + D[k][w]) 
				{
					D[v][w] = D[v][k] + D[k][w];
					Path[v][w] = k+1;
				}
			}
		}
	}
	printf("Distance Matrix\n");
	for(v = 0; v < NumVertex; v++) 
	{
		for(w = 0; w < NumVertex; w++) 
		{
			if(D[v][w] == INT_MAX/2) printf("-1 "); else printf("%d ", D[v][w]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Path Matrix\n");
	for(v = 0; v < NumVertex; v++) 
	{
		for(w = 0; w < NumVertex; w++) 
		{
			printf("%d ", Path[v][w]);
		}
		printf("\n");
	}
}