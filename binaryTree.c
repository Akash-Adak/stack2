#include<stdio.h>
#include<stdlib.h>
struct node{
     struct node *ladd;
    int data;
    struct node *radd;
}; struct node *root=NULL,*new1;
void create( struct node *r, struct node *new1){
  if(new1->data<r->data){
    if(r->ladd==NULL){
        r->ladd=new1;
    }
    else{
        create(r->ladd,new1);
    }
  }
  else if(new1->data>r->data){
  if(r->radd==NULL){
    r->radd=new1;
  }
  else{
    create(r->radd,new1);
  }
  }
 else if(r->data==new1->data){
    printf("duplicate element not allow");
 }
}
void inorder(struct node *p){
 if(p!=NULL){
    inorder(p->ladd);
    printf("%d\t",p->data);
    inorder(p->radd);
 }
}
void preorder(struct node *p){
 if(p!=NULL){
    printf("%d\t",p->data);
     preorder(p->ladd);
    preorder(p->radd);
 }
}
void postorder(struct node *p){
 if(p!=NULL){
   
     postorder(p->ladd);
    postorder(p->radd);
     printf("%d\t",p->data);
 }
}
void main(){
      int choice,n;
      char ch;
    do
    {        
       printf("            binary Tree          \n");
       printf("\n1.create\n2.inorder\n3.preorder\n4.postorder\n5.exist");
      printf("      \n         ");
      printf("  \nenter your choice=");
      scanf("%d",&choice);
        switch (choice)
      {
        case 1:  
        
        do{ 
          printf("enter an element=");
          scanf("%d",&n);
          new1=(struct node*)malloc(sizeof(struct node));
          new1->ladd=new1->radd=NULL;
          new1->data=n;
          if(root==NULL){
            root=new1;
          }
          else{
            create(root,new1);
          
            printf("want to continue....\n");
            ch=getch();
          }
        }while(ch=='y'||ch=='Y');
        case 2: inorder(root);
        break;
        case 3:preorder(root);
        break;
        case 4:postorder(root);
        break;
        default:printf("not valid");
      }
    }while(choice!=5);
}