#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
typedef struct Node node;
node *start=NULL,*curr,*new1;
int pos,ch,ele;
char ch1;
void create();
void insert();
void delete();
void display();

void main(){
   while(1){
    printf("1. Create a doubly linked list.\n2. Insert a new node to the left of the node.\n3. Delete the node based on a specific value.\n4. Display the contents of the list\n5. Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
          create();
          break;
        case 2:
          insert();
          break;
        case 3:
          delete();
          break;
        case 4:
          display();
          break;
        case 5:
          exit(0);
    }
   }

    
    
}

void create(){
    new1=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&new1->data);
    new1->prev=NULL;
    start=new1;
    curr=new1;
    while(1){
        printf("Do you want to add more elements(Y/N):");
        scanf(" %c",&ch1);
        if(ch1=='Y'|| ch1=='y'){
            new1=(node *)malloc(sizeof(node));
            printf("Enter the element:");
            scanf("%d",&new1->data);
            new1->prev=curr;
            curr->next=new1;
            curr=new1;
        }
        else{
            curr->next=NULL;
            return;
        }
    }
}
void insert(){
    new1=(node *)malloc(sizeof(node));
    printf("Enter the element to insert:");
    scanf("%d",&new1->data);
    printf("Enter the node value:");
    scanf("%d",&pos);
    if(start->data==pos){
        new1->next=start;
        start->prev=new1;
        new1->prev=NULL;
        start=new1;
        return;

    }
    node *temp=start;
    while(temp->data!=pos && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL){
      printf("Element could not be found\n");
      return;
    }
    temp->prev->next=new1;
    new1->prev=temp->prev;
    new1->next=temp;
    temp->prev=new1;

}
void delete(){
    if(start==NULL){
        printf("Linked list is empty\n");
        return;
    }
    printf("Enter the element:");
    scanf("%d",&ele);
    if(start->data==ele && start->next==NULL){
        free(start);
        start=NULL;
        return;
    }
    if(start->data==ele){
       node *temp1=start;
       start=start->next;
       start->prev=NULL;
       free(temp1);
       return;
    }
    node *temp=start;
    while( temp!=NULL && temp->data!=ele ){
       temp=temp->next;
       }
    if(temp==NULL){
    printf("Element cannot be found");
  }

  if(temp->data==ele){
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
  }
  

}
void display(){
    if(start==NULL){
        printf("Linked list is empty\n");
        return;
    }
    printf("Linked list contents:\n");
    node *temp=start;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
