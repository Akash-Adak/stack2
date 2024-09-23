#include<stdio.h>

#define m 100
int a[m] ,front=-1,rear=-1;
 int isFull() {
 return ((front == 0 && rear == m - 1) || (front == rear + 1));
}
int isEmpty(){
    return front==-1;
}
void insertFirst(){
    if(isFull()){
        printf("\nqueue is empty");
        return;
    }
    if(isEmpty()){
        front=rear=0;
    }else{
        if(front==0){
            front=m-1;
        }else{
            front-=1;
        }
    }
    int n;
    printf("enter element tp insert=");
    scanf("%d",&n);
    a[front]=n;
 }
 void insertLast(){
    if(isFull()){
        printf("\nqueue is empty");
        return;
    }
    if(isEmpty()){
        front=rear=0;
    }else{
        if(rear==m-1){
            rear=0;
        }else{
            rear+=1;
        }
    }
    int n;
    printf("enter element tp insert=");
    scanf("%d",&n);
    a[rear]=n;
 }
  
void DeleteLast(){
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",a[rear]);
    if(front == rear) 
    {
        front = -1;
        rear=-1;
    }
    else
        if(rear == 0)
            rear=m-1;
        else
            rear=rear-1;  
}
void DeleteFirst(){
     if (isEmpty())
    {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",a[front]);
    if(front == rear) 
    {
        front = -1;
        rear=-1;
    }
    else
        if(front == m-1)
            front = 0;
        else
            front = front+1;  
}
void Display(){
    int front_pos = front,rear_pos = rear;
     
    if(isEmpty()){  
      printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( front_pos <= rear_pos ) {   
        while(front_pos <= rear_pos) {
            printf("%d ",a[front_pos]);
            front_pos++;
        }
    }
    else {
        while(front_pos <= m-1) {
               printf("%d ",a[front_pos]);
            front_pos++;    
        }
        front_pos = 0;
        while(front_pos <= rear_pos){   
            printf("%d ",a[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}
void main(){
 int choice;
 do{
 printf("\n1.insertFirst\n2.InsertLast\n3.DeleteFirst\n4.DeleteLast\n5.Display\n6.exit");
 printf("\nenter your choice=");
 scanf("%d",&choice);
 switch(choice){
    case 1:insertFirst();
     break;
     case 2:insertLast();
     break;
     case 3:DeleteFirst();
     break;
     case 4:DeleteLast();
     break;
     case 5:Display();
     break;
     default:printf("not valid");
 }
 }while(choice!=6);
}
