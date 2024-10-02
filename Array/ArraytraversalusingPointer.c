#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i = 0;
    int *p = &arr[0];
    while (i < 5)
    {
        printf("%d\n", *p);
        i++;
        p++;
    }
}
