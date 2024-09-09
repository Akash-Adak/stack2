#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// Stack operations
void push(char stack[], int *top, char c) {
 if (*top < MAX - 1) {
 stack[++(*top)] = c;
 } else {
 printf("Stack overflow\n");
 exit(EXIT_FAILURE);
 }
}
char pop(char stack[], int *top) {
 if (*top == -1) {
 printf("Stack underflow\n");
 exit(EXIT_FAILURE);
 }
 return stack[(*top)--];
}
char peek(char stack[], int top) {
 if (top == -1) {
 printf("Stack is empty\n");
 exit(EXIT_FAILURE);
 }
 return stack[top];
}
int precedence(char op) {
 switch (op) {
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 return 2;
 default:
 return 0;
 }
}
// Function to convert infix expression to postfix expression
void infixToPostfix(const char* infix, char* postfix) {
 char stack[MAX];
 int top = -1;
 int k = 0;

 for (int i = 0; infix[i] != '\0'; i++) {
 char c = infix[i];

 if (isspace(c)) {
 continue; // Skip whitespace
 }

 if (isalnum(c)) {
 postfix[k++] = c; // Append operand to postfix expression
 } else if (c == '(') {
 push(stack, &top, c); // Push '(' onto stack
 } else if (c == ')') {
 while (top != -1 && peek(stack, top) != '(') {
 postfix[k++] = pop(stack, &top); // Pop and append until '(' is found
 }
 if (top != -1 && peek(stack, top) == '(') {
 pop(stack, &top); // Pop '('
 }
 } else { // Operator
 while (top != -1 && precedence(peek(stack, top)) >= precedence(c)) {
 postfix[k++] = pop(stack, &top); // Pop operators with higher or equal precedence
 }
 push(stack, &top, c); // Push current operator onto stack
 }
 }

 // Pop any remaining operators in the stack
 while (top != -1) {
 postfix[k++] = pop(stack, &top);
 }

 postfix[k] = '\0'; // Null-terminate the output string
}
int main() {
 char infix[MAX];
 char postfix[MAX];

 printf("Enter infix expression: ");
 fgets(infix, MAX, stdin);

 // Remove newline character from input
 infix[strcspn(infix, "\n")] = '\0';

 infixToPostfix(infix, postfix);

 printf("Postfix expression: %s\n", postfix);

 return 0;
}