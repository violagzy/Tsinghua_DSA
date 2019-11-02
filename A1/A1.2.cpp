
#include <stdio.h>
void transpose(int *p);


int main()
{
	int a[3][3],i,j;

	// construct 3x3 integer matrix
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

	printf("The original matrix is \n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
	printf("\n");

	// transpose the matrix
	transpose(a[0]);

	printf("The transposed matrix is \n");
	for(i = 0; i < 3; i++) 
	{
		for(j = 0; j < 3; j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}

	getchar();
}

void transpose(int *p)
{
	int *p1, *p2;
	int temp, i, j;
	for(i = 0; i < 2; i++) 
	{
		for(j = i + 1; j < 3; j++) 
		{
			p1 = p + i * 3 + j;
			p2 = p + i + j * 3;
			temp = *p1; *p1 = *p2; *p2 = temp; 
		}
	}
}

