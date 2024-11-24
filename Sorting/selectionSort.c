#include <stdio.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void selectionSort(int arr[], int size)
{
    int i, j;
    int min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
            {
                min = j;
            }
        swap(&arr[i], &arr[min]);
    }
}

int main()
{
    int size;
    printf("Enter array length: ");
    scanf("%d", &size);
    int arr[size];
    int i;
    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original Array:");
    for (i = 0; i < size; i++)
    {
        printf("\t%d", arr[i]);
    }
    selectionSort(arr, size);
    printf("\nSorted Array:");
    for (i = 0; i < size; i++)
    {
        printf("\t%d", arr[i]);
    }
    return 0;
}
