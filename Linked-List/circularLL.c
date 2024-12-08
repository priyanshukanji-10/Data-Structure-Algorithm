#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int d;
    struct node *next;
} N;

N *start = NULL;

N *createNode(int elem)
{
    N *temp = (N *)malloc(sizeof(N));
    temp->d = elem;
    temp->next = NULL;
    return temp;
}
void insertionBeg(int elem)
{
    N *temp = createNode(elem);
    N *t = start;
    if (start == NULL)
    {
        start = temp;
        temp->next = start;
        return;
    }
    temp->next = start;
    do
    {
        t = t->next;
    } while (t->next != start);
    t->next = temp;
    start = temp;
}
void insertionEnd(int elem)
{
    N *temp = createNode(elem);
    N *tr = start;
    if (start == NULL)
    {
        start = temp;
        temp->next = start;
        return;
    }
    do
    {
        tr = tr->next;
    } while (tr != start);
    temp->next = start;
    tr->next = temp;
}
void travarse()
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    N *temp = start;
    do
    {
        printf("%d ->", temp->d);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}
int main()

{
    int sig, elem;
    N *temp = start;
    printf("Cirular LL");
    do
    {
        printf("Menu: \n 1. insertion beginning\n 2. insertion End\n 4. Travarse\n 0. End\n");
        printf("Enter signal: ");

        scanf("%d", &sig);
        switch (sig)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &elem);
            insertionBeg(elem);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &elem);
            insertionEnd(elem);
            break;
        case 4:
            travarse();
            break;
        default:
            printf("Enter valid input!!\n");
            break;
        case 0:
            break;
        }
    } while (sig != 0);
}