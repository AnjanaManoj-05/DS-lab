#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
typedef struct Node node;
int ch;
char ch1;
void create_LL1();
void create_LL2();
void concat();
void reverse();
void sort();
void display();
node *new1,*curr,*start=NULL,*start1=NULL,*start2=NULL;
void main(){
    while(1){
        printf("1.Concatenate\n2.Reversing\n3.Sorting\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            create_LL1();
            create_LL2();
             concat();
             printf("Result:\n");
             display();
             break;
            case 2:
             reverse();
             display();
             break;
            case 3:
             sort();
             break;
            case 4:
            exit(0);
        }
    }
}
void create_LL1(){
    printf("Linked List-1\n");
    do{
        new1=(node *)malloc(sizeof(node));
        printf("Enter the element:");
        scanf("%d",&new1->data);
        if(start1==NULL){
            start1=new1;
            curr=new1;
        }
        else{
            curr->link=new1;
            curr=new1;
        }
        printf("Do you want to add more elements(Y/N):");
        scanf(" %c",&ch1);
    }while(ch1=='Y'||ch1=='y');
    curr->link=NULL;
}
void create_LL2(){
    printf("Linked List-2\n");
    do{
        new1=(node *)malloc(sizeof(node));
        printf("Enter the element:");
        scanf("%d",&new1->data);
        if(start2==NULL){
            start2=new1;
            curr=new1;
        }
        else{
            curr->link=new1;
            curr=new1;
        }
        printf("Do you want to add more elements(Y/N):");
        scanf(" %c",&ch1);
    }while(ch1=='Y'||ch1=='y');
    curr->link=NULL;
}
void concat(){
    if(start1==NULL && start2==NULL){
        printf("Linked lists are enpty");
        return;
    }
    if(start1==NULL){
        start=start2;
        return;
    }
    if(start2==NULL){
        start=start1;
        return;
    }
    node *temp=start1;
    while(temp->link!=NULL){
     temp=temp->link;
    }
    temp->link=start2;
    start=start1;
    start1=NULL;
    start2=NULL;

}
void display(){
    node *temp;
    if(start==NULL){
        printf("Linked list is empty");
        return;
    }
    temp=start;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void reverse(){
    node *a=start;
    node *b=NULL;
    node *c=NULL;
    while(a!=NULL){
        c=b;
        b=a;
        a=a->link;
        b->link=c;
    }
    start=b;

}
void sort(){
    int n=0;
    node *temp=start;
    while(temp!=NULL){
        n+=1;
        temp=temp->link;
    }
    for(int i=0;i<n-1;i++){
        node *prev=start;
        node *next=start->link;
        for(int j=0;j<n-i-1;j++){
            if(prev->data>next->data){
                int x=prev->data;
                prev->data=next->data;
                next->data=x;
            }
            prev=next;
            next=next->link;
        }
    }
    printf("Sorted list:\n");
    temp=start;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");

}
