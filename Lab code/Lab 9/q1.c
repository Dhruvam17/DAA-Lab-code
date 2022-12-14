#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;


	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver code
int main()
{
    srand(time(0));
    int n;
    n = (rand() % 20)  + 1;
    printf("\nValue of n is : %d",n);
    int arr[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = (  rand() % 10 )  + 1;
    }
    printf("\n\nDimensions of the matrices are : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
	// Function call
	printf("\n\nMinimum number of multiplications is : %d \n",
	MatrixChainOrder(arr, 1, n - 1));
	return 0;
}  