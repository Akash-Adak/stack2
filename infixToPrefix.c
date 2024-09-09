#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// Stack operations for character stack
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
void reverseString(char str[]) {
 int n = strlen(str);
 for (int i = 0; i < n / 2; i++) {
 char temp = str[i];
 str[i] = str[n - i - 1];
 str[n - i - 1] = temp;
 }
}
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
void infixToPrefix(const char* infix, char* prefix) {
 char reversedInfix[MAX];
 char postfix[MAX];

 // Reverse infix expression and replace parentheses
 strcpy(reversedInfix, infix);
 reverseString(reversedInfix);

 for (int i = 0; reversedInfix[i] != '\0'; i++) {
 if (reversedInfix[i] == '(') {
 reversedInfix[i] = ')';
 } else if (reversedInfix[i] == ')') {
 reversedInfix[i] = '(';
 }
 }

 // Convert reversed infix to postfix
 infixToPostfix(reversedInfix, postfix);

 // Reverse postfix expression to get prefix
 reverseString(postfix);
 strcpy(prefix, postfix);
}
int main() {
 char infix[MAX];
 char prefix[MAX];

 printf("Enter infix expression: ");
 fgets(infix, MAX, stdin);

 // Remove newline character from input
 infix[strcspn(infix, "\n")] = '\0';

 infixToPrefix(infix, prefix);

 printf("Prefix expression: %s\n", prefix);

 return 0;
}
