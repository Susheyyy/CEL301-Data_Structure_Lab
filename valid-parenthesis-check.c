#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        top++;
        stack[top] = ch;
    }
}
char pop() {
    if (top >= 0) {
        char temp = stack[top];
        top--;
        return temp;
    }
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

void valid_paren(char input[]) {
    top = -1; 
    int i, length = strlen(input);
    char ch, topChar;

    for (i = 0; i < length; i++) {
        ch = input[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else {
            if (top == -1) {
                printf("%s contains invalid parentheses.\n", input);
                return;
            }
            topChar = peek();
            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                pop();
            } else {
                printf("%s contains invalid parentheses.\n", input);
                return;
            }
        }
    }

    if (top == -1) {
        printf("%s contains valid parentheses.\n", input);
    } else {
        printf("%s contains invalid parentheses.\n", input);
    }
}

int main() {
    char input[MAX];

    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    valid_paren(input);

    return 0;
}
