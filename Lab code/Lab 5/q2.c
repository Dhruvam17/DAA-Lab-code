#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printarray(int*A,int n)
{
    for (int i = 0; i < n; i++)
    {
         printf("%d",A[i]);
    }
    printf("\n");
}
void merge(int *A,int low,int mid,int high)
{
    int i,j,k;
    int B[20];
     i=low;
     j=mid+1;
     k =low;
    while (i<=mid&& j<=high)
    {
          if(A[i]<A[j])
          {
              B[k]=A[i];
              i++;
              k++;
          }
          else{
              B[k]=A[j];
              j++;
              k++;
          }


    }
    while (i<=mid)
    {
        B[k]=A[i];
              k++;
              i++;
    }
    while (j<=high)
    {
        B[k]=A[j];
              k++;
              j++;
    }
    for ( int i = low; i <=high; i++)
    {
        A[i]=B[i];
    }
    
    
    
    
}
void mergesort(int *A,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
void bubblesort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)

    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
void bubblesort2(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)

    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] < A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int main()
{
     int N;
    printf("\nEnter the value of N : \n");
    scanf("%d", &N);

    int arr[N];

    int x,n;
    printf("Enter maximum no  upto which you  want to generate  in array\n");
    scanf("%d", &x);
    printf("Enter the elements of array\n");
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % x; // Generate number between 0 to x-1
    }
    clock_t start, stop;

     do
    {
        printf("\n");
        printf("Press 1 to sort random data by merge sort \n");
        printf("Press 2 to sort sorted data by marge sort \n");
        printf("Press 3 to sort reverse sorted data by merge sort \n");
        printf("Press 0 to exit\n");
        scanf("%d", &n);
        if (n == 1)
        {
            start = clock();
           mergesort(arr,0,N-1);
           printarray(arr,N);
            stop = clock();
            printf("\nTotal execution time: %f\n", ((double)stop - start) / (CLOCKS_PER_SEC));
        }
        else if (n == 2)
        {
            start = clock();
           bubblesort(arr,N);
           mergesort(arr,0,N-1);
           printarray(arr,N);
            stop = clock();
            printf("\nTotal execution time: %f\n", ((double)stop - start) / (CLOCKS_PER_SEC));
        }
        else if (n == 3)
        {
            start = clock();
           bubblesort2(arr,N);
           mergesort(arr,0,N-1);
           printarray(arr,N);
            stop = clock();
            printf("\nTotal execution time: %f\n", ((double)stop - start) / (CLOCKS_PER_SEC));
        }
       

        else
            break;
    } while (n);
    printf("we have exit from program\n");
    return 0;


}