#include <stdio.h>
#define size 5

int cQueue[size];
int f = -1, r = -1;
int count = 0;

void cEnQue(int elem)
{
    if (count >= size)
    {
        printf("cQueue is full\n");
    }
    else
    {
        r = (r + 1) % size;
        cQueue[r] = elem;
        count++;
    }
}
int cDeQue()
{
    if (count == 0 || r == -1)
    {
        printf("cQueue is empty\n");
        return -1;
    }
    else
    {
        f = (f + 1) % size;
        count--;
        return cQueue[f];
    }
}
void display()
{
    if (count <= 0)
    {
        printf("cQueue is empty \n");
    }
    else
    {
        int fcopy = f + 1;

        while (fcopy != r)
        {
            printf("%d \n", cQueue[fcopy]);
            fcopy = (fcopy + 1) % size;
        }
        printf("%d \n", cQueue[r]);
    }
}
int main()
{
    int sig, elem;
    do
    {
        printf("Menu:\n1 to EnQueue\n2 to DeQueue\n3 to Display\n0 to End\n");
        printf("Enter signal: ");
        scanf("%d", &sig);
        switch (sig)
        {
        case 1:
            printf("Enter elem to insert: ");
            scanf("%d", &elem);
            cEnQue(elem);
            break;
        case 2:
            elem = cDeQue();
            if (elem != -1)
                printf("DecQueued elem is: %d\n", elem);
            break;
        case 3:
            display();
            break;
        default:
            if (sig != 0)
            {
                printf("Invalid Signal!!\n");
            }
            break;
        }
    } while (sig != 0);
}