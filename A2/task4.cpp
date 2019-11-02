// task4.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "stdlib.h"
void binary_search(int target, int a[], int left, int right);

void main() 
{
	int n,i,target;
	int *a;

	// Initialization
	printf("Please input the number of intergers in the sequence\n");
	scanf_s("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	printf("Please input the pre-sorted intergers: \n");
	for(i = 0; i < n; i++) 
	{
		scanf_s("%d",&a[i]);
	}
	printf("Please enter the target number you want to find: \n");
	scanf_s("%d",&target);

	binary_search(target, a, 0, n-1);

	getchar();
}

void binary_search(int target, int a[], int left, int right)
{
	int mid;
	if(left > right) printf("Sorry, the target is not in the sequence.\n");
	else {
		mid = (left + right)/2;
		if(a[mid] == target) printf("Target number %d is at position %d\n",target, mid);
		else {
			if(a[mid] > target) binary_search(target, a, left, mid-1);
			else binary_search(target, a, mid + 1, right);
		}
	}
	
}