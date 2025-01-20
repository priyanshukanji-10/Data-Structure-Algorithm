#include <stdio.h>
#define size 10
int stk[size];
int top = -1;

int pop()
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

void push(int elem)
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

int main()
{
    char pfix[size];
    printf("Enter postfix expression: ");
    scanf("%s", pfix);
    int i = 0;
    int res, op2, op1;
    res = op1 = op2 = 0;
    while (pfix[i] != '\0')
    {
        if (pfix[i] == '+' || pfix[i] == '-' || pfix[i] == '*' || pfix[i] == '/' || pfix[i] == '%')
        {
            op2 = pop();
            op1 = pop();
            switch (pfix[i])
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '%':
                res = op1 % op2;
                break;
            default:
                break;
            }
            push(res);
        }
        else
        {
            push(pfix[i] - '0');
        }
        i++;
    }
    printf("Result: %d\n", pop());
    return 0;
}
