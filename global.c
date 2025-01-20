#include <stdio.h>
#define size 10
#define Isize 15

char ifix[Isize];
char stk[size];
int top = -1;

void push(char elem)
{
    if (top < size - 1)
    {
        top++;
        stk[top] = elem;
    }
    else
    {
        printf("Stack overflow");
    }
}

int pop()
{
    if (top <= -1)
    {
        return -1;
    }
    else
    {
        return stk[top--];
    }
}

int chkprece(char x)
{
    switch (x)
    {
    case '^':
        return 3;
    case '%':
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void main()
{
    char pfix[15];
    printf("Enter Infix exp:");
    scanf("%s", ifix);
    int j = 0;
    int i = 0;
    while (ifix[i] != 0)
    {
        if (ifix[i] >= 97 && ifix[i] <= 122)
        {
            pfix[j] = ifix[i];
            j++;
        }
        else if (ifix[i] == '(')
        {
            push('(');
        }
        else if (ifix[i] == ')')
        {
            while (top > -1 && stk[top] != '(')
            {
                pfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && chkprece(ifix[i]) < chkprece(stk[top]))
            {
                pfix[j++] = pop();
            }
            push(ifix[i]);
        }
        i++;
    }
    while (top > -1)
    {
        pfix[j++] = pop();
    }
    pfix[j] = '\0';
    printf("%s", pfix);
}
