#include<stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE],top=-1;
void push()
{
    int n;
    if(top==MAXSIZE-1)
    {
        printf("\n stack is overflow");
    }
    else
    {
        printf("enter a element=");
        scanf("%d",&n);
        stack[++top]=n;
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty");
    }
    else 
    {
      printf(" enter of stack=");
      for(i=top;i>=0;i--)
      {
        printf("\n%d",stack[i]);
      }
    }
       
}
void pop()
{
    int n;
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
     {
      n=stack[top];
     top--;
     printf("poped element =%d",n);
    }
}
void peek()
{
    if(top==-1){
        return;
    }
    printf("the peeked element is =%d",stack[top]);
}
void main()
{
    int choice;
    do
    {        
       printf("\n           stack          \n");
       printf("\n1.push\n2.pop\n3.Display\n4.Peek\n5.Exit");
      printf("      \n         ");
      printf("  \nenter your choice=");
      scanf("%d",&choice);
        switch (choice)
      {
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3:display();
        break;
        case 4:peek();
        break;
        default:printf("not valid");
      }
    }while(choice!=5);
}