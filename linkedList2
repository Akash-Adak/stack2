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

void delete_first(){
     if(start==NULL){
    printf("list is not found");
 }
 else{
    temp=start;
    start=start->add;
    printf("deleted node is %d",temp->add);
    free(temp);
 }
}
void delete_last(){
     if(start==NULL){
    printf("list is not found");
 }
 else{
    temp=start;
    while(temp->add!=NULL){
        prev=temp;
        temp=temp->add;
    }
    prev->add=NULL;
    printf("deleted node is%d",temp->data);
    free(temp);
 }
}
void delete_position(){
 if(start==NULL){
    printf("list is not found");
 }
 else{
    int pos,i=1;
    printf("enter the possition to insert=");
    scanf("%d",&pos);
    temp=start;
    while(i<pos){
        prev=next;
        temp=temp->add;
        i++;
    }
    next=temp->add;
    prev->add=next;
    printf("the deleted node is %d",temp->data);
    free(temp);
 }
}



void main(){
    int choice;
    do{
      printf("          linkdlist        ");
       printf("\n1.create\n2.display\n3.delete on first\n4.delete on last\n5.delete on position\n6.exist");
       printf("             \n         ");
      printf("\nenter your choce=");
      scanf("%d",&choice);
      switch(choice){
           case 1:create();
            break;
            case 2: display();
            break;
            case 3:delete_first();
            break;
            case 4: delete_last();
            break;
            case 5:delete_position();
            break;
           
            default: printf("not valid");
      }
    }while(choice!=6);
}
