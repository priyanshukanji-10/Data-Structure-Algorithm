#include <stdio.h>

int main()
{
    int arr[5] = {5, 4, 5, 78, 6};
    int i = 0;
    while (i < 5)
    {
        printf("%x\n", &arr[i]);
        i++;
    }
}