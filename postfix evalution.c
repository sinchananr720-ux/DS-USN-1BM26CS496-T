#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[50], x;
    int a, b, i;

    printf("Enter postfix expression: ");
    scanf("%49s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        x = exp[i];

        if (isdigit((unsigned char)x))
        {
            push(x - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (x)
            {
                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}

