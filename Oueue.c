#include<stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE],rear=-1,front=0;
void insert(){
    int n;
 if (rear==MAXSIZE-1) printf(" queue is over flow");
 else{
 printf(" enter a element=");
 scanf("%d",&n);
 queue[++rear]=n;
 }
}
void Delete(){
    int n;
    if(front>rear) printf(" queue is empty");
    else{
   n=queue[front++];
   printf("deleted elkement =%d",n);
    }
}
void display(){
    if(front>rear) printf(" queue is empty");
    else {
        printf(" queue elements");
        for (int i=rear;i>=front;i--){
          printf("\n%d",queue[i]);
        }
    }
}

void main(){
  int choice;
  do
  {
      printf("          queue        ");
       printf("\n1.insert\n2.delete\n3.display\n4.exist");
      printf("\nenter your choce=");
      scanf("%d",&choice);
      switch(choice){
           case 1:insert();
           break;
           case 2:Delete();
           break;
            case 3: display();
            break;;
            default: printf("not valid");
      }
  }while(choice!=5);
}
