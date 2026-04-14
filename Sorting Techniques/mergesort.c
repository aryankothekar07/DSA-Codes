#include <stdio.h>
void Merge(int *arr1, int start, int mid, int end)
{
    int arr2[end + 1];
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end)
    {
        if(arr1[i] <= arr1[j])
        {
            arr2[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr2[k] = arr1[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        arr2[k] = arr1[i];
        i++;
        k++;
    }
    while(j <= end)
    {
        arr2[k] = arr1[j];
        j++;
        k++;
    }
    for(int i = start; i <= end; i++)
    {
        arr1[i] = arr2[i];
    }
}

void MergeSort(int *arr1, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(arr1, start, mid);
        MergeSort(arr1, mid + 1, end);
        Merge(arr1, start, mid, end);
    }
}

int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter the array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    MergeSort(arr1, 0, n - 1);
    printf("The sorted array is: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}