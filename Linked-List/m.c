#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Global start pointer
struct Node *start = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertFromBeginning(int data)
{
    struct Node *temp = createNode(data);
    temp->next = start;
    start = temp;
}

// Function to insert a node at the end
void insertFromEnd(int data)
{
    struct Node *temp = createNode(data);
    if (start == NULL)
    {
        start = temp;
        return;
    }
    struct Node *current = start;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
}

// Function to display the linked list
void display()
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list operations
int main()
{
    insertFromBeginning(10);
    insertFromBeginning(20);
    insertFromEnd(30);
    insertFromEnd(40);

    display();

    return 0;
}
