#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int d;
    struct node *left;
    struct node *right;
} T;

T *createNode(int elem)
{
    T *temp = malloc(sizeof(T));
    temp->d = elem;
    temp->left = temp->right = NULL;
    return temp;
}

T *insertionBst(T *root, int elem)
{
    if (root == NULL)
    {
        return createNode(elem);
    }
    else if (root->d > elem)
    {
        root->left = insertionBst(root->left, elem);
    }
    else
    {
        root->right = insertionBst(root->right, elem);
    }
    return root;
}

T *findMin(T *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

T *delTree(T *root, int elem)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (elem > root->d)
    {
        root->right = delTree(root->right, elem);
    }
    else if (elem < root->d)
    {
        root->left = delTree(root->left, elem);
    }
    else
    {
        if (root->left == NULL)
        {
            T *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            T *tmp = root->left;
            free(root);
            return tmp;
        }
        else
        {
            T *tmp = findMin(root->right);
            root->d = tmp->d;
            root->right = delTree(root->right, tmp->d);
        }
    }
    return root;
}

void inorderTraversal(T *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->d);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(T *root)
{
    if (root != NULL)
    {
        printf("%d ", root->d);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(T *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->d);
    }
}

int main()
{
    T *root = NULL;
    int choice, elem;

    do
    {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &elem);
            root = insertionBst(root, elem);
            break;
        case 2:
            printf("Enter the element to delete: ");
            scanf("%d", &elem);
            root = delTree(root, elem);
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
