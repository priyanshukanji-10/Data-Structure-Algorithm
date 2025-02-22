#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int d;
    struct Node *next;
} N;
N *start = NULL;
N *temp;

N *createNode(int elem)
{
    N *newNode;
    newNode = (N *)malloc(sizeof(N));
    newNode->d = elem;
    newNode->next = NULL;
    return newNode;
}

void insertionBeg(int elem)
{
    N *newNode = createNode(elem);
    if (start == NULL)
    {
        start = newNode;
        return;
    }
    newNode->next = start;
    start = newNode;
}

void insertionEnd(int elem)
{
    N *newNode = createNode(elem);
    if (start == NULL)
    {
        start = newNode;
        return;
    }
    for (temp = start; temp->next != NULL; temp = temp->next)
        ;
    temp->next = newNode;
}

void insertionMid(int elem, int pos)
{
    N *newNode = createNode(elem);
    if (pos == 1)
    {
        newNode->next = start;
        start = newNode;
        return;
    }

    int c;
    for (c = 1, temp = start; c < pos - 1 && temp->next != NULL; c++, temp = temp->next)
        ;

    if (c < pos - 1 && temp->next == NULL)
    {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deletionBeg()
{
    if (start == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    temp = start;
    start = start->next;
    free(temp);
}
void deletionEnd()
{
    if (start == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    for (temp = start; (temp->next)->next != NULL; temp = temp->next)
        ;
    N *del = temp->next;
    temp->next = NULL;
    free(del);
}
void deletionMid(int pos)
{
    if (start == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    int c;
    for (c = 1, temp = start; c < pos - 1 && temp->next != NULL; c++, temp = temp->next)
        ;
    N *del = temp->next;
    temp->next = (temp->next)->next;
    free(del);
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
        printf("%d -> ", temp->d);
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
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
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
            printf("Linked List: ");
            traverse();
            break;
        case 5:
            deletionBeg();
            printf("Deleted from beginning.\n");
            break;
        case 6:
            deletionEnd();
            printf("Deleted from end.\n");
            break;
        case 7:
            printf("Enter position to delete from: ");
            scanf("%d", &pos);
            deletionMid(pos);
            printf("Deleted from position %d.\n", pos);
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
