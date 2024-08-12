#include <stdio.h>
#include <stdbool.h>
#define MAX 100 
int stack[MAX];
int top = -1; 
void initStack();
bool isEmpty();
bool isFull();
void push(int value);
int pop();
int peek();
void printStack();
void menu();
void initStack() {
 top = -1; 
}
bool isEmpty() {
 return top == -1;
}
bool isFull() {
 return top == MAX - 1;
}
void push(int value) {
 if (isFull()) {
 printf("Stack overflow\n");
 return;
 }
 stack[++top] = value; 
 printf("%d pushed to stack\n", value);
}
int pop() {
 if (isEmpty()) {
 printf("Stack underflow\n");
 return -1; 
 }
 return stack[top--]; 
}
int peek() {
 if (isEmpty()) {
 printf("Stack is empty\n");
 return -1; 
 }
 return stack[top]; 
}
void printStack() {
 if (isEmpty()) {
 printf("Stack is empty\n");
 return;
 }
 printf("Stack elements are:\n");
 for (int i = top; i >= 0; i--) {
 printf("%d\n", stack[i]);
 }
}
void menu() {
 int choice, value;
 while (1) {
 printf("\nStack Operations Menu:\n");
 printf("1. Push\n");
 printf("2. Pop\n");
 printf("3. Peek\n");
 printf("4. Display\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the value to push: ");
 scanf("%d", &value);
 push(value);
 break;
 case 2:
 value = pop();
 if (value != -1) {
 printf("%d popped from stack\n", value);
 }
 break;
 case 3:
 value = peek();
 if (value != -1) {
 printf("Top element is %d\n", value);
 }
 break;
 case 4:
 printStack();
 break;
 case 5:
 printf("Exiting...\n");
 return;
 default:
 printf("Invalid choice, please try again.\n");
 }
 }
}
int main() {
 initStack();
 menu();
 return 0;
}