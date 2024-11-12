#include <stdio.h>
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
node *curr,*new1,*start=NULL;
int ch,pos;
void main(){
while(1){
    printf("1.Create a linked list\n2.Insert at first position\n3.Insert at specific position\n4.Insert at end of linked list \n5.Display\n6.Exit\n");
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
    char ch1;
do{
    new1=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&new1->data);
    if(start==NULL){
        start=new1;
        curr=new1;
    }
    else{
        curr->link=new1;
        curr=new1;
    }
    printf("Do you want to enter more elements:(Y/N)");
    scanf(" %c",&ch1);
}while(ch1=='y'|| ch1=='Y');
curr->link=NULL;

}
void display(){
node *temp;
if(start==NULL){
    printf("Linked list is empty");
    return;
}
printf("Linked list contents:\n");
temp=start;
while(temp!=NULL){
    printf("%d ,",temp->data);
    temp=temp->link;

}
printf("\n");
}
void insert_first(){
new1=(node *)malloc(sizeof(node));
printf("Enter the element:");
scanf("%d",&new1->data);
if(start==NULL){
    start=new1;
    new1->link=NULL;
    return;
}
new1->link=start;
start=new1;
}
void insert_spos(){
new1=(node *)malloc(sizeof(node));
printf("Enter element:");
scanf("%d",&new1->data);
printf("Enter position:");
scanf("%d",&pos);
if(pos==1){
    new1->link=start;
    start=new1;
}
int i=1;
node *temp=start;
while(temp!=NULL && i<pos-1){
    temp=temp->link;
    i++;
}
if(temp==NULL){
    printf("Entered position is more than number of elements.\n");
    return;
}
new1->link=temp->link;
temp->link=new1;

}
void insert_end(){
new1=(node *)malloc(sizeof(node));
printf("Enter element:");
scanf("%d",&new1->data);
if(start==NULL){
    start=new1;
    new1->link=NULL;
}
node *temp=start;
while(temp->link!=NULL){
    temp=temp->link;
}
temp->link=new1;
new1->link=NULL;
}
