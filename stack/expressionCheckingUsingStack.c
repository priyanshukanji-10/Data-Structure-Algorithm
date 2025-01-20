#include <stdio.h>

char stack[20];
int top = -1;

void push(char elem)
{
    if (top >= 19)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = elem;
    }
}

int pop()
{
    if (top <= -1)
    {
        return -1;
    }
    else
    {
        top--;
        return 1;
    }
}

int main()
{
    char ar1[20];
    char arr[20];
    int i, j = 0;

    printf("Enter expression: ");
    scanf("%s", ar1);

    for (i = 0; ar1[i] != '\0'; i++)
    {
        if (ar1[i] == '(' || ar1[i] == ')')
        {
            arr[j] = ar1[i];
            j++;
        }
    }
    arr[j] = '\0';

    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(')
        {
            push('(');
        }
        else if (arr[i] == ')')
        {
            if (pop() == -1)
            {
                printf("Mismatch\n");
                return 0;
            }
        }
    }

    if (top == -1)
    {
        printf("Match\n");
    }
    else
    {
        printf("Mismatch\n");
    }

    return 0;
}
