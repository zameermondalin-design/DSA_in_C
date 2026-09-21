#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main() {
    char exp[100];
    char x;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    printf("Postfix expression: ");

    for (int i = 0; i < strlen(exp); i++) {

        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        }

        else if (exp[i] == '(') {
            push(exp[i]);
        }

        else if (exp[i] == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }

        else {
            while (top != -1 && priority(stack[top]) >= priority(exp[i])) {
                printf("%c", pop());
            }

            push(exp[i]);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}