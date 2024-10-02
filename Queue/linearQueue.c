#include <stdio.h>
#define size 5

int queue[size];
int f = -1, r = -1;

void enQue(int elem)
{
    if (r >= size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        r++;
        queue[r] = elem;
    }
}
int deQue()
{
    if (f >= r || r == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        f++;
        return queue[f];
    }
}
void display()
{
    int fcopy = f + 1;
    int i;
    for (i = fcopy; i <= r; i++)
    {
        printf("%d \n", queue[i]);
    }
}
int main()
{
    int sig, elem;
    do
    {
        printf("Menu:\n1 to Enqueue\n2 to Dequeue\n3 to Display\n0 to End\n");
        printf("Enter signal: ");
        scanf("%d", &sig);
        switch (sig)
        {
        case 1:
            printf("Enter elem to insert: ");
            scanf("%d", &elem);
            enQue(elem);
            break;
        case 2:
            elem = deQue();
            if (elem != -1)
                printf("Dequeued elem is: %d\n", elem);
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