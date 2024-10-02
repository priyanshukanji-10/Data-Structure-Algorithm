#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} N;
N *createNode(int elem)
{
    N *newNode = (N *)malloc(sizeof(N));
    newNode->data = elem;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(N **start, int elem)
{
    N *newNode = createNode(elem);
    newNode->next = *start;
    *start = newNode;
}
void insertAtEnd(N **start, int elem)
{
    N *newNode = createNode(elem);
    if (*start == NULL)
    {
        *start = newNode;
    }
    else
    {
        N *temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void travarseList(N *start)
{
    N *temp = start;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int elem;
    N *start = NULL;
    int sig;
    do
    {
        printf("Menu:\n 1.insertatBeginning\n 2.insertatEnd\n3.travase\n 0.END\n");
        printf("Enter signal:");
        scanf("%d", &sig);
        switch (sig)
        {
        case 1:
            printf("Enter element to insert:");
            scanf("%d", &elem);
            insertAtBeginning(&start, elem);
            break;
        case 2:
            printf("Enter element to insert:");
            scanf("%d", &elem);
            insertAtEnd(&start, elem);
            break;
        case 3:
            printf("Travasing the link-list...\n");
            travarseList(start);
            break;
        default:
            if (sig != 0)
            {
                printf("Invalid signal!!");
                break;
            }
        }

    } while (sig != 0);
}
