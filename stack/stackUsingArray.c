#include <stdio.h>
#define size 5
int stk[size];
int top = -1;

void push(int elem)
{
    if (top < size - 1)
    {
        top++;
        stk[top] = elem;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

int pop()
{
    if (top <= -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int a = stk[top];
        top--;
        return a;
    }
}

int main()
{
    int choice, elem;
    do
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &elem);
            push(elem);
            break;
        case 2:
            elem = pop();
            if (elem != -1)
                printf("Popped element: %d\n", elem);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
