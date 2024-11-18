#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *add;
}; struct node *start=NULL,*temp,*new1,*next,*prev; 
void create(){
    int n;
    char ch;
    printf("enter a num=");
    scanf("%d",&n);
    start=(struct node*)malloc(sizeof(struct node));
    start->data=n;
    start->add=NULL;
    temp=start;
    printf("want to continue=\n");
    ch=getch();
    while(ch=='y'|| ch=='Y'){
     printf("enter a element=");
     scanf("%d",&n);
     new1=(struct node*)malloc(sizeof(struct node));
     new1->data=n;
     new1->add=NULL;
     temp->add=new1;
     temp=temp->add;
     printf("want to continue=\n");
     ch=getch();
    }
}
void display(){
    if(start==NULL){
        printf("list not created");
    }
    else{
        temp=start;
        while(temp!=NULL){
            printf("\n%d",temp->data);
            temp=temp->add;
        }
    }
}
void insert_first(){
 if(start==NULL){
    printf("list is not found");
 }
 else{
    int n;
    printf("enter the insert element");
    scanf("%d",&n);
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=start;
    start=new1;
 }
}
void insert_last(){
 if(start==NULL){
    printf("list is not found");
 }
 else{
    int n;
    printf("enter the insert element");
    scanf("%d",&n);
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;
    temp=start;
    while(temp->add!=NULL){
        temp=temp->add;
    }
    temp->add=new1;
 }
}
void insert_Any_position(){
 if(start==NULL){
    printf("list is not found");
 }
 else{
    int n,pos,i=1;
    printf("enter the insert element");
    scanf("%d",&n);
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;
    printf("enter the possition to insert=");
    scanf("%d",&pos);
    next=start;
    while(i<pos){
        prev=next;
        next=next->add;
        i++;
    }
    prev->add=new1;
    new1->add=next;
 }
}



void main(){
    int choice;
    do{
      printf("          linkdlist        ");
       printf("\n1.create\n2.display\n3.insert on first\n4.insert on last\n5.insert on position\n6.exist");
       printf("             \n         ");
      printf("\nenter your choce=");
      scanf("%d",&choice);
      switch(choice){
           case 1:create();
            break;
            case 2: display();
            break;
            case 3:insert_first();
            break;
            case 4: insert_last();
            break;
            case 5:insert_Any_position();
            break;
           
            default: printf("not valid");
      }
    }while(choice!=6);
}