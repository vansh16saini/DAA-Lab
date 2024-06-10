#include<stdio.h>
#include<stdlib.h>
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
void heapify(int arr[], int n, int l)
{
    int largest = l;
    int lef = 2*l+1;
    int rig = 2*l+2;
    if(lef<n && arr[lef]>arr[largest])
        largest = lef;
    if(rig<n && arr[rig]>arr[largest])
        largest = rig;
    if(largest != l)
    {
        swap(&arr[l], &arr[largest]);
        heapify(arr ,n ,largest);
    }        
}
void heapsort(int arr[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr, n, i);
    int ij;
    for(ij=n-1;ij>=0;ij--)
        swap(&arr[0],&arr[ij]);
        heapify(arr,ij,0);
}
int main()
{
    int arr[] = {3,2,5,7,83,8,34,63,};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting:\n");
    print(arr, n);
    heapsort(arr, n);
    printf("\nAfter sorting:\n");
    print(arr, n);
    return 0;
}