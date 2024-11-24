#include <stdio.h>
#define size 5

int stack[size];
int top = -1;

void push(int elem)
{
    if (top >= size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = elem;
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
        int temp = stack[top];
        top--;
        return temp;
    }
}

int main()
{
    int i, op1, op2, res;
    char exp[10];

    printf("Enter postfix exp: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '%')
        {
            op2 = pop();
            op1 = pop();
            switch (exp[i])
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
            case '%':
                res = op1 % op2;
                break;
            }
            push(res);
        }
        else
        {
            push(exp[i] - '0'); // Convert char to int
        }
    }

    printf("Result: %d\n", pop());
    return 0;
}
