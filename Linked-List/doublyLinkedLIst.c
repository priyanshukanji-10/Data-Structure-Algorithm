#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *prev;
    struct NODE *next;
} N;

N *start = NULL;
N *temp;

N *createNode(int elem)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->d = elem;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertionBeg(int elem)
{
    N *ptr = createNode(elem);
    if (start == NULL)
    {
        start = ptr;
        return;
    }
    ptr->next = start;
    start->prev = ptr;
    start = ptr;
}

void insertionEnd(int elem)
{
    N *ptr = createNode(elem);
    if (start == NULL)
    {
        start = ptr;
        return;
    }
    for (temp = start; temp->next != NULL; temp = temp->next)
        ;
    ptr->prev = temp;
    temp->next = ptr;
}

void insertionMid(int elem, int pos)
{
    N *ptr = createNode(elem);
    if (pos == 1)
    {
        insertionBeg(elem);
        return;
    }

    int c;
    for (c = 1, temp = start; c < pos - 1 && temp != NULL; c++, temp = temp->next)
        ;

    if (temp == NULL || (c < pos - 1 && temp->next == NULL))
    {
        printf("Position out of range.\n");
        free(ptr);
        return;
    }

    ptr->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = ptr;
    temp->next = ptr;
    ptr->prev = temp;
}
void deletionBeg()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    N *del = start;
    start = start->next;
    start->prev = NULL;
    free(del);
}
void deletionEnd()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    for (temp = start; temp->next != NULL; temp = temp->next)
        ;
    N *del = temp;
    (temp->prev)->next = NULL;
    free(del);
}
void delettionMid(int pos)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1)
    {
        deletionBeg();
        return;
    }
    int c;
    for (c = 1, temp = start; c < pos && temp->next != NULL; temp = temp->next)
        ;
    // todo add logic
}
void traverse()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    for (temp = start; temp != NULL; temp = temp->next)
    {
        printf("%d <-> ", temp->d);
    }
    printf("NULL\n");
}

int main()
{
    int choice, elem, pos;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Traverse\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert at beginning: ");
            scanf("%d", &elem);
            insertionBeg(elem);
            break;
        case 2:
            printf("Enter element to insert at end: ");
            scanf("%d", &elem);
            insertionEnd(elem);
            break;
        case 3:
            printf("Enter element to insert: ");
            scanf("%d", &elem);
            printf("Enter position to insert at: ");
            scanf("%d", &pos);
            insertionMid(elem, pos);
            break;
        case 4:
            printf("Doubly Linked List: ");
            traverse();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
