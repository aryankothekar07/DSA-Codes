#include <stdio.h>
void selectionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = i;
        for(int j = i + 1; j < n; j++)
        {
            if( arr[key]> arr[j])
            {
                key = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
    }
}
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionsort(arr, n);
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
