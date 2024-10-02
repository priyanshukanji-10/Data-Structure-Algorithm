#include <stdio.h>

#define size 10
#define Esize 15

char expre[Esize]; // Input expression
char stk[size];    // Stack to store operators
int top = -1;      // Stack top pointer

// Function to pop the top element from the stack
char pop()
{
    if (top <= -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stk[top--]; // Return and decrement top
    }
}

// Function to push an element onto the stack
void push(char elem)
{
    if (top >= (size - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stk[++top] = elem; // Increment top and push element
    }
}

// Function to check the precedence of an operator
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

    // Loop through each character in the infix expression
    for (i = 0; expre[i] != '\0'; i++)
    {
        // If the character is an operand (a-z), output it directly
        if (expre[i] >= 'a' && expre[i] <= 'z')
        {

            pfix[j] = expre[i];
            j++;
        }
        // If the character is a left parenthesis, push it onto the stack
        else if (expre[i] == '(')
        {
            push('(');
        }
        // If the character is a right parenthesis, pop and output until '(' is found
        else if (expre[i] == ')')
        {
            while (stk[top] != '(' && top > -1)
            {
                pfix[j] = pop();
                j++;
            }
            pop(); // Discard the '('
        }
        // If the character is an operator
        else
        {
            while (top != -1 && chkprece(expre[i]) <= chkprece(stk[top]))
            {
                pfix[j] = pop();
                j++; // Pop operators with higher or equal precedence
            }
            push(expre[i]); // Push the current operator onto the stack
        }
    }

    // Pop and output all remaining operators in the stack
    while (top > -1)
    {
        pfix[j] = pop();
        j++;
    }
    pfix[j] = '\0';
    printf("%s", pfix);

    return 0;
}
