#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int q[10],FRONT=-1,REAR=-1,i,item,ch,element;
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
            printf("Popped element is:%d\n",item);
        }
        else{
          printf("Queue is empty\n");
        }
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
    }}
}
void insert(){
    if(REAR==(MAX-1)){
      printf("Queue is full\n");
      return;
    }
    else if(FRONT==-1 && REAR==-1){
        FRONT=0;
        REAR=0;
    }
     else{
       REAR+=1;
    }
    printf("Enter element to be inserted:");
    scanf("%d",&item);
    q[REAR]=item;
}
int delete(){
    if(FRONT==-1 && REAR==-1){
        return (-1);
    }
    element=q[FRONT];
    if(FRONT==REAR){
        FRONT=-1;
        REAR=-1;
    }
    else{
        FRONT+=1;
    }
    return element;
}
void display(){
    if(FRONT==-1 && REAR==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    for(i=FRONT;i<=REAR;i++){
        printf("%d\n",q[i]);
    }
    return;

}
