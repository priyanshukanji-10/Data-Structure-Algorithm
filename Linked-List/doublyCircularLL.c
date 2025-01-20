#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int d;
    struct Node *prev;
    struct Node *next;
} N;

N *start = NULL;

N *createNode(int val)
{
    N *tmp = (N *)malloc(sizeof(N));
    tmp->d = val;
    tmp->prev = tmp->next = NULL;
    return tmp;
}

void insertionBeg(int value)
{
    N *ran = createNode(value);
    if (start == NULL)
    {
        ran->prev = ran->next = ran;
        start = ran;
    }
    else
    {
        ran->prev = start->prev;
        ran->next = start;
        start->prev->next = ran;
        start->prev = ran;
        start = ran;
    }
}

void deletionBeg()
{
    if (start == NULL)
    {
        printf("List already empty!!");
        return;
    }
    else if (start->next == start)
    {
        start = NULL;
    }
    else
    {

        N *temp = start;
        start->prev->next = start->next;
        start->next->prev = start->prev;
        start = start->next;
        free(temp);
    }
}

void deletionEnd()
{
    if (start == NULL)
    {
        printf("List already empty!!");
        return;
    }
    else if (start->next == start)
    {
        start = NULL;
    }
    else
    {
        N *temp = start->prev;
        start->prev = start->prev->prev;
        start->prev->next = start;
        free(temp);
    }
}

void insertionEnd(int value)
{
    N *ran = createNode(value);
    if (start == NULL)
    {
        ran->prev = ran->next = ran;
        start = ran;
    }
    else
    {
        ran->next = start;
        ran->prev = start->prev;
        start->prev->next = ran;
        start->prev = ran;
    }
}

void display(int count)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    N *temp = start;
    printf("List elements up to %dth count circularly: ", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d -> ", temp->d);
        temp = temp->next;
    }
    printf("\n");
}

void travarse()
{
    if (start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    N *temp = start;
    printf("List elements: ");
    do
    {
        printf("%d -> ", temp->d);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

int main()
{
    int choice, value, count;

    printf("*** Doubly Circular Linked List Operations ***\n");
    do
    {
        printf("\nMenu:\n");
        printf("0. Exit\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Traverse List\n");
        printf("4. Display N Elements\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting program...\n");
            break;

        case 1:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            insertionBeg(value);
            break;

        case 2:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            insertionEnd(value);
            break;

        case 3:
            travarse();
            break;

        case 4:
            printf("Enter the number of elements to display: ");
            scanf("%d", &count);
            display(count);
            break;

        case 5:
            deletionBeg();
            break;

        case 6:
            deletionEnd();
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
