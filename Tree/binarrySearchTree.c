#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
    int d;
    struct bst *left;
    struct bst *right;

} T;

T *createNode(int value)
{
    T *temp = (T *)malloc(sizeof(T));
    temp->d = value;
    temp->left = temp->right = NULL;
    return temp;
}

T *insertionBST(T *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->d)
    {
        root->left = insertionBST(root->left, value);
    }
    else if (value > root->d)
    {
        root->right = insertionBST(root->right, value);
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
T *deltree(T *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->d > value)
    {
        root->left = deltree(root->left, value);
    }
    else if (root->d < value)
    {
        root->right = deltree(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            T *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            T *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            T *temp = findMin(root->right);
            root->d = temp->d;
            root->right = deltree(root->right, temp->d);
        }
        return root;
    }
}
void preOrderTraversal(T *root)
{
    if (root != NULL)
    {

        printf("%d ,", root->d);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(T *root)
{
    if (root != NULL)
    {

        inOrderTraversal(root->left);
        printf("%d ,", root->d);
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(T *root)
{
    if (root != NULL)
    {

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ,", root->d);
    }
}
int main()
{
    T *root = NULL;
    int choice, value;

    printf("*** Binary Search Tree Operations ***\n");
    do
    {
        printf("\nMenu:\n");
        printf("0. Exit\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;

        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insertionBST(root, value);
            break;

        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deltree(root, value);
            break;

        case 3:
            printf("Preorder Traversal: ");
            preOrderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Inorder Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("Postorder Traversal: ");
            postOrderTraversal(root);
            printf("\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}
