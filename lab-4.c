#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int cq[10],i,item,ch,FRONT=-1,REAR=-1;
void insert();
int delete();
void display();

void main(){
    while(1){
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert();
            break;
            case 2:
            item=delete();
            if(item!=-1){
                printf("\nPopped item is:%d\n",item);
            }
            else{
                printf("\nCircular queue is empty\n");
            }
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Wrong choice!\n");

        }
    }
}
void insert(){
 if(FRONT==(REAR+1)%MAX){
    printf("Circular queue is full\n");
    return;
 }
 if(FRONT==-1 && REAR==-1){
    FRONT=0;
    REAR=0;
 }
 else{
    REAR=(REAR+1)%MAX;
 }
 printf("Enter element:");
 scanf("%d",&item);
 cq[REAR]=item;
 return;
}
int delete(){
    if(FRONT==-1 && REAR==-1){
        return (-1);
    }
    item=cq[FRONT];
    if(FRONT==REAR){
        FRONT=-1;
        REAR=-1;
    }
    else{
        FRONT=(FRONT+1)%MAX;
    }
    return item;
}
void display(){
    if(FRONT==-1 && REAR==-1){
        printf("Circular queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    if(FRONT<=REAR){
       for(i=FRONT;i<=REAR;i++){
            printf("%d\n",cq[i]);
       }
    }
    else{
       for(i=FRONT;i<=MAX-1;i++){
            printf("%d\n",cq[i]);
       }

       for(i=0;i<=REAR;i++){
            printf("%d\n",cq[i]);
       }

}}
