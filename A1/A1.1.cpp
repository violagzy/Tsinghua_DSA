
#include <stdio.h>
int fib_recursion(int N);
int fib_iteration(int N);
#include <time.h>
clock_t clock(void);


int main()
{
//	clock_t start_time, end_time;
	int N = 100;

	// Start and end time of recursion
	clock_t recursion_start_time = clock();
	int result_recursion = fib_recursion(N);
	clock_t recursion_end_time = clock();
	// Start and end time of iteration
	clock_t iteration_start_time = clock();
	int result_iteration = fib_iteration(N);
	clock_t iteration_end_time = clock();

	printf("Running time of recursion: %fseconds \n",(double)(recursion_end_time-recursion_start_time)/CLOCKS_PER_SEC);
	printf("Running time of iteration %fseconds",(double)(iteration_end_time-iteration_start_time)/CLOCKS_PER_SEC);
	
	/*
	Running time of recursion increases dramatically when N increases: 
	When N = 10, it takes approximately 0.000000 second(short for time in following analysis); 
	N = 20, time 「 0.000000; 
	N = 30, time 「 0.058000;
	N = 40, time 「 6.682000;
	N = 50, time 「 809.162000;
	...

	In the meantime, the running time of iteration does not show similar increasing trend. 
	*/


	getchar();
	return(0);
}

int fib_recursion(int N)
{
	if ( N == 1 || N == 2 ) return (1);
	return (fib_recursion(N - 1) + fib_recursion(N - 2));
}

int fib_iteration(int N)
{
	int prev1 = 1, prev2 = 1;
	int curr = 2, temp;
	while (curr < N + 1)
	{
		temp = prev1 + prev2;
		prev1 = prev2; 
		prev2 = temp; 
		curr ++;
	}
	return(prev1);
}
