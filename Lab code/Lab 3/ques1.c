#include <stdio.h>
#include <stdlib.h>
void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
void insertionsort(int *A, int n)
{
    int key, j;
    for (int i = 0; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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
    int temp;3
    
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
{ int n;


    do
    {
        printf("\n");
        printf("press 1 to sort already sorted array by insertion sort \n");
        printf("press 2 to sort reverse sorted array by insertion sort   \n");
        printf("press 3 to random data array by insertion sort \n");
        printf("press 4 to generate random no in array and apply insertion sort and display content of arry \n");
        printf("press 5 to sort array any other sorting method\n");
        printf("press 6 to  reverse sort array by any other sorting method \n");
        printf("press 0 to exit\n");
        scanf("%d", &n);
        if (n == 1)
        {
            int X[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            printf("\nbefore sorting array is \n");
            printarray(X, 10);
            insertionsort(X, 10);
            printf("\nafter insertion sorting array is \n");
            printarray(X, 10);
        }
        else if (n == 2)
        {
            int Y[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
            printf("\nbefore sorting array is \n");
            printarray(Y, 10);
            insertionsort(Y, 10);
            printf("\nafter insertion sorting array is \n");
            printarray(Y, 10);
        }
        else if (n == 3)
        {
            int Z[10] = {1, 5, 3, 4, 2, 8, 9, 10, 6, 7};
            printf("\nbefore sorting array is \n");
            printarray(Z, 10);
            insertionsort(Z, 10);
            printf("\nafter insertion sorting array is \n");
            printarray(Z, 10);
        }
        else if (n == 4)
        {
            int N;
            printf("\nEnter the value of N : \n");
            scanf("%d", &N);

            int arr[N];

            int x;
            printf("enter maximum no  upto which you  want to generate  in array\n");
            scanf("%d", &x);
            printf("Enter the elements of array\n");
            for (int i = 0; i < N; i++)
            {
                arr[i] = rand() % x; // Generate number between 0 to x-1
            }
            printf("\nbefore sorting array is \n");
            printarray(arr, N);
            insertionsort(arr, N);
            printf("\nafter insertion sorting array is \n");
            printarray(arr, N);
        }
        else if (n == 5)
        {
            int N;
            printf("\nEnter the value of N : \n");
            scanf("%d", &N);

            int arr[N];

            int x;
            printf("enter maximum no  upto which you  want to generate  in array\n");
            scanf("%d", &x);
            printf("Enter the elements of array\n");
            for (int i = 0; i < N; i++)
            {
                arr[i] = rand() % x; // Generate number between 0 to x-1
            }
            printf("\nbefore sorting array is \n");
            printarray(arr, N);
            bubblesort(arr, N);
            printf("\nafter bubble sorting array is \n");
            printarray(arr, N);
        }
        else if (n == 6)
        {
            int M[10] = {1, 5, 3, 4, 2, 8, 9, 10, 6, 7};
            printf("\nbefore sorting array is \n");
            printarray(M, 10);
            bubblesort2(M, 10);
            printf("\nafter reverse sort by bubble sort array is \n");
            printarray(M, 10);
        }

        else
            break;
    } while (n);
    printf("we have exit from program\n");
    return 0;
}