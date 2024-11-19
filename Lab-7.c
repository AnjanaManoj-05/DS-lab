#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *top=NULL,*new1,*front=NULL,*rear=NULL;
int ch,ch1,ch2,item;
void push();
int pop();
void display1();
void insert();
int delete();
void display2();
void main(){
    while(1){
        printf("1.Stacks\n2.Queues\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
               do{
                     printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
                     printf("Enter your choice:");
                     scanf("%d",&ch1);
                     switch(ch1){
                        case 1:
                          push();
                          break;
                        case 2:

                          item=pop();
                          if(item==-1){
                            printf("Stack is empty\n");
                          }
                          else{
                            printf("Popped item %d\n",item);
                          }
                          break;
                        case 3:
                         display1();
                         break;
                        case 4:
                            break;
                     }
                     }while(ch1!=4);



               break;
            case 2:
               while(1){
                     printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
                     printf("Enter your choice:");
                     scanf("%d",&ch2);
                     switch(ch2){
                        case 1:
                          insert();
                          break;
                        case 2:
                          item=delete();
                          if(item==-1){
                            printf("Queue is empty\n");
                          }
                          else{
                            printf("Popped item %d\n",item);
                          }
                          break;
                        case 3:
                         display2();
                         break;
                        case 4:
                         exit(0);
                     }
               }
               break;
            case 3:
            exit(0);
        }
    }
}
void push(){
    new1=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&new1->data);
    if(top==NULL){
        top=new1;
        new1->link=NULL;
        return;
    }
    new1->link=top;
    top=new1;
}
int pop(){
    if(top==NULL){
        return (-1);
    }
    node *temp=top;
    top=top->link;
    int item=temp->data;
    free(temp);
    return item;
}
void display1(){
    node *temp;
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void insert(){
    new1=(node *)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&new1->data);
    if(front==NULL && rear==NULL){
        front=new1;
        rear=new1;
        new1->link=NULL;
        return;
    }
    rear->link=new1;
    rear=new1;
    rear->link=NULL;
}
int delete(){
    if(front==NULL && rear==NULL){
        return (-1);
    }
    node *del=front;
    front=front->link;
    int item=del->data;
    if (front==NULL){
        rear=NULL;
    }
    free(del);
    return item;
}
void display2(){
    if(rear==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    node *temp=front;
    while(temp!=rear->link){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
