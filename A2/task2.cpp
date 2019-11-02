// task2.cpp : 定义控制台应用程序的入口点。
//

# include <stdio.h>
# include "stdlib.h"
# include "time.h"

void main() 
{
	long long i,j,k,n;
	long long sum;
	clock_t start,finish;
	double totaltime;

	n = 10000;

	/*
	// (1)
	start=clock();
	sum = 0;
	for (i = 0; i<n; i++) {
		sum++;
	}
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC; 
	printf("Time1: %.11lf\n",totaltime);
	*/

	/*
	// (2)
	start=clock();
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			sum++;
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC; 
	printf("Time2: %.11lf\n",totaltime);
	*/

	/*
	// (3)
	start=clock();
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n*n; j++)
			sum++;
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC; 
	printf("Time3: %.11lf\n",totaltime);*/

	// (4)
	start=clock();
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < i; j++)
			sum++;
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC; 
	printf("Time4: %.11lf\n",totaltime);

	/*
	// (5)
	start=clock();
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < i*i; j++)
			for(k = 0; k < j; k++)
				sum++;
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC; 
	printf("Time5: %.11lf\n",totaltime);
	*/

	/*
	// (6)
	start=clock();
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < i*i; j++)
			if(j % i == 0)
				for(k = 0; k < j; k++)
					sum++;
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC; 
	printf("Time6: %.11lf\n",totaltime);
	*/

	getchar();
}

