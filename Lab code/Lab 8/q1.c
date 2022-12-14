#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>5
void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void printMaxActivities(int s[], int f[], int n)
{
	int i, j;

	printf("Following activities are selected\n");

	// The first activity always gets selected
	i = 0;
	printf("%d ", i);

	// Consider rest of the activities
	for (j = 1; j < n; j++) {
		// If this activity has start time greater than or
		// equal to the finish time of previously selected
		// activity, then select it
		if (s[j] >= f[i]) {
			printf("%d ", j);
			i = j;
		}
	}
}

// Driver code
int main()
{
    int m;
    printf("Enter size of start and finish array\n");
    scanf("%d",&m);
    int s[m];
	for (int i = 0; i < m; i++)
	{
		s[i] = rand() % 100;
	}
    printf("Start array is \n");
    for (int i = 0; i < m; i++)
	{
		printf("%d\t",s[i]);
	}
    printf("\n");
    int f[m];
	for (int i = 0; i < m; i++)
	{
		f[i] = rand() % 100;
	}
    printf("finish array is \n");
    for (int i = 0; i < m; i++)
	{
		printf("%d\t",f[i]);
	}
    printf("\n");

	// int s[] = { 1, 3, 0, 5, 8, 5 };
	// int f[] = { 2, 4, 6, 7, 9, 9 };
	// int n = sizeof(s) / sizeof(s[0]);

	// Function call
    for (int i = 0; i < m; i++)
    {
        if (s[i]>f[i])
        {
            swap(s[i],f[i]);
        }
        
    }
    
	printMaxActivities(s, f, m);
	return 0;
}