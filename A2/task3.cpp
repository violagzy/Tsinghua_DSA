// task3.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
# include "stdlib.h"
# include "time.h"


int max_subsequence_sum1(int a[], int n);
int max_subsequence_sum2(int a[], int n);
int max_subsequence_sum3(int a[], int left, int right);
int max_subsequence_sum4(int a[], int n);
int max3(int, int, int);

void main() 
{
	int n,i,sum;
	clock_t start,finish;
	double totaltime;
	int *a;

	// Initialization
	printf("Please input the number of intergers in the sequence\n");
	scanf_s("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	printf("Please input the intergers: \n");
	for(i = 0; i < n; i++) 
	{
		scanf_s("%d",&a[i]);
	}
	printf("\n");

	// Exhaustive Strategy
	start = clock();
	sum = max_subsequence_sum1(a, n);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC; 
	printf("Maximum sum is %d\n",sum);
	printf("Algorithm I: %.11lf\n",totaltime);
	printf("\n");

	// Optimized Strategy
	start = clock();
	sum = max_subsequence_sum2(a, n);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC; 
	printf("Maximum sum is %d\n",sum);
	printf("Algorithm II: %.11lf\n",totaltime);
	printf("\n");

	// Divide-and-Conquer Strategy
	start = clock();
	sum = max_subsequence_sum3(a, 0, n-1);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC; 
	printf("Maximum sum is %d\n",sum);
	printf("Algorithm III: %.11lf\n",totaltime);
	printf("\n");

	// The Best
	start = clock();
	sum = max_subsequence_sum4(a, n);
	finish = clock();
	totaltime = (double)(finish-start)/CLOCKS_PER_SEC; 
	printf("Maximum sum is %d\n",sum);
	printf("Algorithm IV: %.11lf\n",totaltime);
	printf("\n");

	getchar();
}

int max_subsequence_sum1(int a[], int n)
{
	int i,j,k,best_i,best_j,this_sum,max_sum;
	max_sum = 0;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			this_sum = 0;
			for(k=i;k<=j;k++)
				this_sum += a[k];
			if(this_sum > max_sum) {
				best_i = i;
				best_j = j;
				max_sum = this_sum;
			}
		}
	return max_sum;
}

int max_subsequence_sum2(int a[], int n)
{
	int i,j,best_i,best_j,this_sum,max_sum;
	max_sum = 0;
	for(i=0;i<n;i++)
	{
		this_sum = 0;
		for(j=i;j<n;j++)
		{
			this_sum += a[j];
			if(this_sum > max_sum) {
				best_i = i;
				best_j = j;
				max_sum = this_sum;
			}
		}
	}
	return max_sum;
}

int max_subsequence_sum3(int a[], int left, int right)
{
	int MaxLeftSum = 0, MaxRightSum = 0;
	int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;
	int LeftBorderSum = 0, RightBorderSum = 0;
	int center = (left + right)/2, i;
	if(left == right)
		if(a[left] > 0) return a[left]; else return 0;
	MaxLeftSum = max_subsequence_sum3(a, left, center);
	MaxRightSum = max_subsequence_sum3(a, center + 1, right);
	for(i = center; i >= left; i--)
	{
		LeftBorderSum += a[i];
		if(LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	for(i = center + 1; i <= right; i++)
	{
		RightBorderSum += a[i];
		if(RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}
	return max3(MaxLeftBorderSum, MaxRightBorderSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int max_subsequence_sum4(int a[], int n)
{
	int best_i,best_j,i,j,this_sum, best_sum;
	i = this_sum = best_sum = 0;
	for(j=0; j<n; j++)
	{
		this_sum += a[j];
		if(this_sum > best_sum)
		{
			best_sum = this_sum; best_i = i; best_j = j;
		}
		else if(this_sum < 0)
		{
			i = j + 1; this_sum = 0;
		}
	}
	return best_sum;
}

int max3(int a, int b, int c)
{
	if(a > b) {
		if(a > c) return a;
		else return c;
	}
	else {
		if(b > c) return b;
		else return c;
	}
}

