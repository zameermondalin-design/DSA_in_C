#include <stdio.h>
#include <ctype.h>

int stack[100];
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
    char postfix[100];
    int i = 0;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    while(postfix[i] != '\0')
    {
        char ch = postfix[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            int result;

            switch(ch)
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }
        i++;
    }

    printf("Result = %d", pop());

    return 0;
}