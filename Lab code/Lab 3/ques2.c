#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    int n;
    printf("\nEnter the size of array: \n");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = ( rand() % 5 ) + 1;
        printf("%d ", arr[i] );
    }

    // int duplicates = 0;
    int count,maxElement,maxCount=0;
    
    
    for (int i = 0; i < n; i++)
    {
        count=1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                // duplicates++;
                count++;
                
                if( count > maxCount )
                {
                    maxCount = count;
                    maxElement = arr[j];
                }
            }
                
        }
    }
    if (maxCount > n/2)
    {
    printf("\n Majority Element is : %d and its count is: %d",maxElement,maxCount);
    }
    else
    {
        printf("\nThere is no Majority element\n");
    }
    
    
    // printf("\n No. of Duplicate elements in array are :  %d", duplicates);   
 
    return 0;
}