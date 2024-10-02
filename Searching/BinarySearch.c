#include <stdio.h>

int main()
{
    int arr[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n;
    printf("Enter a element:");
    scanf("%d", &n);
    int l = 0, m, r = 9;
    while (r >= l)
    {
        m = (l + r) / 2;
        if (n == arr[m])
        {
            printf("Match found!!");
            break;
        }
        else if (n > arr[m])
        {
            l = m + 1;
        }
        else if (n < arr[m])
        {
            r = m - 1;
        }
    }
    if (l > r)
    {
        printf("Element not found!!");
    }
}