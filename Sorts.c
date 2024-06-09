#include <stdio.h>
void print(int* arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d/t",arr[i]);
    }
}
void swap(int* a ,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int* arr, int n)
{
    int i,j,min=0;
    printf("Bubble SORT: ");
    for(i=n-1;i>=1;i--)
        for(j=0;j<i-1;j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
}
void selectionsort(int* arr, int n)
{
    int i,j,min=i;
    printf("SELECTION SORT: ");
    for(i=0;i<n-1;i++)
        for(j=i;j<n-1;j++)
            if(arr[min]>arr[j])
                min = j;
        swap(&arr[min],&arr[i]);    

}
void insertionsort(int* arr, int n)
{
    int i,j,key;
    printf("Insertion SORT: ");
    for(i=0;i<n-1;i++)
        key = i;
        for(j=i;j<n-1;j++)
            while(j>0 && arr[j]>arr[key])
                 swap(&arr[j],&arr[key]);
}

int main()
{
    int arr[] = {3,2,5,7,83,8,34,63,};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    selectionsort(arr,n);
    insertionsort(arr,n);
}
