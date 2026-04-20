#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000000

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    stack[++top] = c;
}

// Pop function
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Check matching brackets
bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Check balanced expression
bool isBalanced(char* s) {
    top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        // Opening bracket
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // Closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) return false;

            char top_char = pop();

            if (!isMatch(top_char, ch))
                return false;
        }
    }

    return isEmpty();
}

// Main function
int main() {

    printf("Devarsh Gupta , 25070521139 , SECTION C(1)\n\n");

    char* tests[] = {"[{()}]", "[()(){}", "([)", "[{()})"};
    int n = 4;

    for (int i = 0; i < n; i++) {
        printf("Input:  \"%s\"\n", tests[i]);
        printf("Output: %s\n\n", isBalanced(tests[i]) ? "true" : "false");
    }

    return 0;
}
