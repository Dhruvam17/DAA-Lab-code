#include<stdio.h>
#include<time.h>

void getMinMax(int arr[], int n)
{	
int i,min,max;


if (n == 1)
{
	max = arr[0];
	min = arr[0];	
}
if (arr[0] > arr[1])
{
	max = arr[0];
	min = arr[1];
}
else
{
	max = arr[1];
	min = arr[0];
}
for (i = 2; i<n; i++)
{
	if (arr[i] > max)	
	max = arr[i];

	else if (arr[i] < min)	
	min = arr[i];
}
printf("\nMinimum element is %d", min);
printf("\nMaximum element is %d", max);
}

int main()
{
clock_t tic ,toc;
int n;
printf("\nEnter the Value of n: ");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++)
{
    arr[i] = rand()%300;
}
printf("\nThe Elements of array: ");
for(int i=0;i<n;i++)
{
    printf(" %d",arr[i]);
}
tic = clock();
getMinMax(arr,n);
toc = clock() - tic;

printf("\nTime Taken with Divide-Conqure Method: %lf",(double)toc);
}
