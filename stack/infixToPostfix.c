#include <stdio.h>

#define size 10
#define Esize 15

char expre[Esize];
char stk[size];
int top = -1;

char pop()
{
    if (top <= -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stk[top--];
    }
}

void push(char elem)
{
    if (top >= (size - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stk[++top] = elem;
    }
}

int chkprece(char opr)
{
    switch (opr)
    {
    case '+':
    case '-':
        return 1;
    case '%':
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main()
{
    int i;
    char pfix[15];
    int j = 0;
    printf("Enter an infix expression: ");
    scanf("%s", expre);

    for (i = 0; expre[i] != '\0'; i++)
    {
        if (expre[i] >= 'a' && expre[i] <= 'z')
        {
            pfix[j] = expre[i];
            j++;
        }
        else if (expre[i] == '(')
        {
            push('(');
        }
        else if (expre[i] == ')')
        {
            while (stk[top] != '(' && top > -1)
            {
                pfix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while (top != -1 && chkprece(expre[i]) <= chkprece(stk[top]))
            {
                pfix[j] = pop();
                j++;
            }
            push(expre[i]);
        }
    }

    while (top > -1)
    {
        pfix[j] = pop();
        j++;
    }
    pfix[j] = '\0';
    printf("%s", pfix);

    return 0;
}
