#include <stdio.h>
void swap(int *arr, int start, int pIndex)
{
    int k = arr[start];
    arr[start] = arr[pIndex];
    arr[pIndex] = k;
}
int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    for(int i = start; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr, i, pIndex);
            pIndex += 1;
        }
    }
    swap(arr, pIndex, end);
    return pIndex;
}
void quicksort(int *arr, int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quicksort(arr, start, pIndex - 1);
        quicksort(arr, pIndex + 1, end);
    }
}
int main()
{
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before QuickSort: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quicksort(arr, 0, n-1);
    printf("Array after QuickSort: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
