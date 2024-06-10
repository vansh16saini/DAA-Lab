#include <stdio.h>
#include <stdlib.h>
void print(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[e]);
    return i + 1;
}

void quicksort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quicksort(arr, s, p - 1);
        quicksort(arr, p + 1, e);
    }
}

int main()
{
    int arr[] = {3,2,5,7,83,8,34,63,};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting:\n");
    print(arr, n);
    quicksort(arr, 0, n - 1);
    printf("\nAfter sorting:\n");
    print(arr, n);
    return 0;
}