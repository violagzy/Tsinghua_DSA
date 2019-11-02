// sorting.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "stdlib.h"
void PrintSort(int A[], int N);
void ShellSort(int A[], int N);
void MergeSort(int A[], int N);
void MSort(int A[], int TmpArray[], int Left, int Right);
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd);
void QuickSort(int A[], int N);
int Median3(int A[], int Left, int Right);
void QSort(int A[], int Left, int Right);
void InsertSort(int A[], int N);

int main()
{
	int i, N;
	int A[100], B[100];
	printf("Please input the total number of intergers: ");
	scanf_s("%d", &N);
	printf("Now Please input the numbers one by one: \n");
	for(i = 0; i < N; i++) 
	{
		scanf_s("%d",&B[i]);
	}

	// ShellSort
	for(i = 0; i < N; i++) 
	{
		A[i] = B[i];
	}
	ShellSort(A, N);

	// MergeSort
	for(i = 0; i < N; i++) 
	{
		A[i] = B[i];
	}
	MergeSort(A, N);

	// QuickSort
	for(i = 0; i < N; i++) 
	{
		A[i] = B[i];
	}
	QuickSort(A, N);

	getchar();
	return 0;
}

void PrintSort(int A[], int N)
{
	int i;
	for(i = 0; i < N-1; i++) printf("%d ",A[i]);
	printf("%d\n",A[N-1]);
}

void ShellSort(int A[], int N)
{ 
	int i, j;
	int Increment[3] = {1, 3, 7};
	int inc;
	int Tmp;
	for(inc = 0; inc < 3; inc++)
	{ 
		for(i = Increment[inc]; i < N; i++)
		{ 
			Tmp = A[i];
			for(j = i; j >= Increment[inc]; j = j-Increment[inc])
			{ 
				if(Tmp < A[j - Increment[inc]]) A[j] = A[j - Increment[inc]];
				else break;
			}
			A[j] = Tmp;
		}
	}
	printf("Shell Sort: ");
	PrintSort(A,N);
}

void MergeSort(int A[], int N)
{ 
	int *TmpArray;
	TmpArray = (int*)(malloc(N * sizeof(int)));
	if(TmpArray != NULL)
	{ 
		MSort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
	{ 
		printf("No Space for tmp array!!!\n");
	}
	printf("Merge Sort: ");
	PrintSort(A,N);
}

void MSort(int A[], int TmpArray[], int Left, int Right)
{ 
	int Center;
	if(Left < Right) // When the list length is > 1
	{ 
		Center = (Left + Right)/2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}

void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)
{ 
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos; // TmpPos is used for TmpArray
	NumElements = RightEnd - Lpos + 1;
	while(Lpos <= LeftEnd && Rpos <= RightEnd) // Both left & right halves have not been finished scanning
	{ 
		if(A[Lpos] <= A[Rpos]) TmpArray[TmpPos++] = A[Lpos++];
		else TmpArray[TmpPos++] = A[Rpos++];
	}
	while(Lpos <= LeftEnd) // Copy the rest of left half
	{ 
		TmpArray[TmpPos++] = A[Lpos++]; 
	}
	while(Rpos <= RightEnd) // Copy the rest of right half
	{ 
		TmpArray[TmpPos++] = A[Rpos++]; 
	}
	for(i=0; i<NumElements; i++, RightEnd--) // Copy TmpArray back to A
	{ 
		A[RightEnd] = TmpArray[RightEnd]; 
	}
}

void QuickSort(int A[], int N)
{ 
	QSort(A, 0, N - 1); // QSort(Array, Left, Right)
	printf("Quick Sort: ");
	PrintSort(A,N);
}

int Median3(int A[], int Left, int Right)
{ 
	int Tmp; // A tmp variable for swap
	int Center = (Left + Right)/2; // Locate center
	if(A[Left] > A[Center]) // Make A[left]<A[center]
	{ 
		Tmp= A[Left]; A[Left] = A[Center]; A[Center] = Tmp; 
	}
	if(A[Left] > A[Right]) // Make A[left]<A[right]
	{ 
		Tmp= A[Left]; A[Left] = A[Right]; A[Right] = Tmp; 
	}
	if(A[Center] > A[Right]) // Make A[center]<A[Right]
	{ 
		Tmp= A[Center]; A[Center] = A[Right]; A[Right] = Tmp; 
	}
	Tmp = A[Center]; // A[center] is pivot
	A[Center] = A[Right - 1]; // Swap A[center]
	A[Right - 1] = Tmp; // with A[Right-1]
	return A[Right - 1]; // Return the pivot
}

#define Cutoff (3) // Define the Cutoff threshold
void QSort(int A[], int Left, int Right)
{ 
	int i, j, Pivot, Tmp;
	if(Left + Cutoff <= Right) // If current number of elements > 3
	{ 
		Pivot = Median3(A, Left, Right); // Find the pivot using Median3()
		i = Left; j = Right - 1; // Initialize i and j
		for( ; ; ) // Locate i and j for swap
		{ 
			while(A[++i] < Pivot) {}; // Move i until A[i] > Pivot
			while(A[--j] > Pivot) {}; // Move j until A[j] < Pivot
			if(i < j) { Tmp= A[i]; A[i] = A[j]; A[j] = Tmp; } // swap
			else break; // If i>j, then stop current partitioning
		}
		Tmp = A[i]; A[i] = A[Right - 1]; A[Right - 1] = Tmp; // Restore pivot
		QSort(A, Left, i - 1); // Recursively Qsort Left
		QSort(A, i + 1, Right); // Recursively Qsort Right
	}
	// If the current number <= 3, do InsertSort
	InsertSort(A + Left, Right - Left + 1); // Base case
}

void InsertSort(int A[], int N)
{ 
	int j, P;
	int Tmp; // Tmp is used for swap
	for(P=1; P<N; P++)
	{ 
		Tmp = A[P];
		for(j=P; (j>0)&&(A[j-1]>Tmp); j--)
		{ 
			A[j] = A[j-1];
		}
		A[j] = Tmp;
	}
}