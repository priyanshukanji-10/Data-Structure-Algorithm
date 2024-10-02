#include <stdio.h>

int main()
{
    int ary[10] = {2, 4, 5, 6, 8, 9, 2, 11, 23, 5};
    int n, i = 0;
    ;
    printf("Enter a element to search:");
    scanf("%d", &n);
    while (i < 10)
    {
        if (n == ary[i])
        {
            printf("Match found");
            break;
        }
        i++;
    }
    if (i >= 10)
    {
        printf("Element not found");
    }
}