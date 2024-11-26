#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *link;
};
void create();
void display();
void delete_first();
void delete_end();
void delete_spos();
typedef struct Node node;
node *curr,*new1,*start=NULL;
int ch,pos,ele;
void main(){
while(1){
    printf("1.Create a linked list\n2.Delete from first position\n3.Delete specific element\n4.Delete at end of linked list \n5.Display\n6.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
case 1:
    create();
    break;
case 2:
    delete_first();
    break;
case 3:
    delete_spos();
    break;
case 4:
    delete_end();
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
    printf("Linked list is empty\n");
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
void delete_first(){
if(start==NULL){
    printf("Linked list is empty\n");
    return;
}
node *temp=start;
start=start->link;
free(temp);
}
void delete_spos(){
printf("Enter element:");
scanf("%d",&ele);
if(start==NULL){
printf("The linked list is empty\n");
return;
}
if(start->data==ele){
    node *temp=start;
    start=start->link;
    free(temp);
    return;
}
node *prev=NULL;
node *next=start;
while(next->data!=ele && next->link!=NULL){
 prev=next;
 next=next->link;
}
if(next->data==ele){
    prev->link=next->link;
    free(next);
}
else{
    printf("The element does not exist\n");
}
}
void delete_end(){

if(start==NULL){
printf("The linked list is empty\n");
return;
}
if(start->link==NULL){
    node *temp=start;
    start=start->link;
    free(temp);
    return;
}
node *next=start;
node *prev=NULL;
while(next->link!=NULL){
    prev=next;
    next=next->link;
}
prev->link=NULL;
free(next);

}
