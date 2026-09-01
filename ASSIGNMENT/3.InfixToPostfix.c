#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char ch)
{
    if (top < SIZE - 1)
        stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';

    return stack[top];
}

int priority(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;
        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }

        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[k++] = pop();
            }

            if (top != -1)
                pop(); // Remove '('
        }

        else
        {
            while (top != -1 &&
                   peek() != '(' &&
                   (priority(peek()) > priority(ch) ||
                   (priority(peek()) == priority(ch) && ch != '^')))
            {
                postfix[k++] = pop();
            }

            push(ch);
        }
    }
    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
