#include <stdio.h>
#include <ctype.h>
#define MAX 100

float st[MAX];
int top = -1;

void push(float st[], float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);

int main() {
    float val;
    char exp[100];

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    val = evaluatePostfixExp(exp);

    printf("Value of the postfix expression = %d\n", val);

    return 0;
}

float evaluatePostfixExp(char exp[]) {
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0'));
        } else {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i]) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/': value = op1 / op2; break;
                case '%': value = (int)op1 % (int)op2; break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    return 0;
            }
            push(st, value);
        }
        i++;
    }

    return pop(st);
}

void push(float st[], float val) {
    if (top == MAX - 1) {
        printf("STACK OVERFLOW\n");
    } else {
        st[++top] = val;
    }
}

float pop(float st[]) {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        return -1;
    } else {
        return st[top--];
    }
}
