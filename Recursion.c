#include <stdio.h>
void printName(int n)
{
    if(n==0)
        return;
    else
        printf("Vansh ");
    printName(n-1);        
}
int binarySearch(int arr[], int s, int l, int tar) {
    if (s > l)
        return -1;
    int mid = (s + l) / 2;
    if (arr[mid] == tar)
        return mid;
    else if (arr[mid] > tar) 
        return binarySearch(arr, s, mid - 1, tar);
    else 
        return binarySearch(arr, mid + 1, l, tar);
}

int linearSearch(int arr[],int s, int l, int tar)
{
    if(s>l)
        {return -1;}
    else if (arr[s] == tar);
        {return 1;}
    else if (arr[l] == tar);
        {return l;}
    else{
        return linearSearch(arr,s+1,l,tar);}
}
int main()
{
    int arr[] = {10,2,8,4,3,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tar = 3;
    int res1 = binarySearch(arr,0,n-1,tar);
    int res2 = linearSearch(arr,0,n-1,2);
    printName(7);
    if(res1==-1)
        printf("Element not found");
    else
        printf("Element found at index %d",res1);    
    
    if(res2==-1)
        printf("Element not found");
    else
        printf("Element found at index %d",res2);  
    return 0;
}