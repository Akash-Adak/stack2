#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node *next;
};
struct Stack {
 struct Node *top;
};
struct Node *createNode(int data) {
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}
void initialize(struct Stack *stack) {
 stack->top = NULL;
}
int isEmpty(struct Stack *stack) {
 return stack->top == NULL;
}

void push(struct Stack *stack, int data) {
 struct Node *newNode = createNode(data);
 newNode->next = stack->top;
 stack->top = newNode;
 printf("%d pushed to stack\n", data);
}

int pop(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack Underflow\n");
 exit(1);
 }
 struct Node *temp = stack->top;
 int data = temp->data;
 stack->top = temp->next;
 free(temp);
 return data;
}

int peek(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack is empty\n");
 exit(1);
 }
 return stack->top->data;
}

void display(struct Stack *stack) {
 if (isEmpty(stack)) {
 printf("Stack is empty\n");
 return;
 }
 struct Node *temp = stack->top;
 printf("Stack elements: ");
 while (temp != NULL) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("\n");
}
int main() {
 struct Stack stack;
 initialize(&stack);
 int choice, data;
 while (1) {
 printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data to push: ");
 scanf("%d", &data);
 push(&stack, data);
 break;
 case 2:
 data = pop(&stack);
 printf("%d popped from stack\n", data);
 break;
 case 3:
 data = peek(&stack);
 printf("Top element: %d\n", data);
 break;
 case 4:
 display(&stack);
 break;
 case 5:
 exit(0);
 default:
 printf("Invalid choice\n");
 }
 }
 return 0;
}