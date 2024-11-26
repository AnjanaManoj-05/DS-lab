#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *link;
};
void create();
void display();
void insert_first();
void insert_end();
void insert_spos();
typedef struct Node node;
node *curr,*new1,*start=NULL,*last=NULL;
int ch,pos;
void main(){
while(1){
    printf("1.Create a circularly linked list\n2.Insert at first position\n3.Insert at specific position\n4.Insert at end of linked list \n5.Display\n6.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
case 1:
    create();
    break;
case 2:
    insert_first();
    break;
case 3:
    insert_spos();
    break;
case 4:
    insert_end();
    break;
case 5:
    display();
    break;
case 6:
    exit(0);
    }
}}

void create(){
 new1=(node *)malloc(sizeof(node));
 char ch1;
 printf("Enter the element:");
 scanf("%d",&new1->data);
 start=new1;
 last=new1;
 while(1){
    printf("Do you want to add more elements(Y/N):");
    scanf(" %c",&ch1);
    if(ch1=='Y'|| ch1=='y'){
        new1=(node *)malloc(sizeof(node));
        printf("Enter the element:");
        scanf("%d",&new1->data);
        last->link=new1;
        last=new1;

    }
    else if(ch1=='N'|| ch1=='n'){
        last->link=start;
        break;

    }
 }
}
void insert_first(){
    new1=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&new1->data);
    if(start==NULL){
        start=new1;
        start->link=new1;
        return;
    }
    new1->link=start;
    node *temp=start;
    while(temp->link!=start){
        temp=temp->link;
    }
    temp->link=new1;
    start=new1;


}
void insert_end(){
    new1=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&new1->data);
    if(start==NULL){
        start=new1;
        start->link=new1;
        return;
    }
    new1->link=start;
    node *temp=start;
    while(temp->link!=start){
        temp=temp->link;
    }
    temp->link=new1;
}
void insert_spos(){
   new1=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&new1->data);
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1){
        new1->link=start;
        node *temp=start;
        while(temp->link!=start){
            temp=temp->link;
        }
        temp->link=new1;
        start=new1;
        return;
    }
    int i=1;
    node *temp=start;
    while(temp->link!=start && i<pos-1){
        temp=temp->link;
        i++;
    }
    if(temp->link==start &&i!=pos-1){
        printf("Entered position is greater than the number of elements\n");
        return;
    }
    if(temp->link==start){
        temp->link=new1;
        new1->link=start;
       return;
    }
    new1->link=temp->link;
    temp->link=new1;


}
void display(){
node *temp=start;
if(start==NULL){
    printf("Circular Linked list is empty\n");
    return;
}
while(temp->link!=start){
    printf("%d->",temp->data);
    temp=temp->link;
}
printf("%d ",temp->data);
printf("\n");
}
