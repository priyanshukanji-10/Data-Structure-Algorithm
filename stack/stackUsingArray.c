#include <stdio.h>

int stack[7];
int top = -1;

void push(int elem)
{
    if (top >= 6)
    {
        printf("Stack overflow!!\n");
    }
    else
    {
        top++;
        stack[top] = elem;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        printf("%d\n", stack[top]); // return stack[top]
        top--;
    }
}
int main()
{
    int sig, elem;
    do
    {
        printf("Enter signal to perform task:\n 1 for push \n 2 for pop \n 0 to End\n");
        scanf("%d", &sig);
        switch (sig)
        {
        case 1:
            printf("Enter element to push in stack:");
            scanf("%d", &elem);
            push(elem);
            break;
        case 2:
            printf("poping last element\n");
            pop();
            break;

        default:
            if (sig != 0)
            {
                printf("Invalid signal\n");
            }

            break;
        }
    } while (sig != 0);
}