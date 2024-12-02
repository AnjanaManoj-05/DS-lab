#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};
typedef struct Node node ;
node *root=NULL,*new1,*curr,*ptr;
int ch;
char ch1;
void create();
void traverse_preorder(node *temp);
void traverse_inorder(node *temp);
void traverse_postorder(node *temp);
void main(){
      while(1){
    printf("1. Construct a binary Search tree.\n2. To traverse the tree using all the methods i.e., in-order,preorder and post order\n3.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
          create();
          break;
        case 2:
          printf("Preorder:\n");
          traverse_preorder(root);
          printf("\nInorder:\n");
          traverse_inorder(root);
          printf("\nPostorder:\n");
          traverse_postorder(root);
          printf("\n");
          break;
        case 3:
           exit(0);
         
         
          
          
    }
   }
}
void create(){
  new1=(node *)malloc(sizeof(node));
  printf("Enter the element:");
  scanf(" %c",&new1->data);
  new1->left=NULL;
  new1->right=NULL;
  root=new1;
  while(1){
    printf("Do you want to add more elements(Y/N):");
        scanf(" %c",&ch1);
        if(ch1=='Y'|| ch1=='y'){
            new1=(node *)malloc(sizeof(node));
            printf("Enter the element:");
            scanf(" %c",&new1->data);
            int item;
            item=new1->data;
            new1->left=NULL;
            new1->right=NULL;
            curr=root;
            while(curr!=NULL){
                ptr=curr;
                curr=(item>=curr->data)?curr->right:curr->left;
            }
            if(item<ptr->data){
                ptr->left=new1;
            }
            else{
                ptr->right=new1;
            }
  }
  else{
    return;
  }
}
}
void traverse_preorder(node *temp){
    if(temp!=NULL){
        printf(" %c",temp->data);
        traverse_preorder(temp->left);
        traverse_preorder(temp->right);
    }
}
void traverse_inorder(node *temp){
    if(temp!=NULL){
        traverse_inorder(temp->left);
        printf(" %c",temp->data);
        traverse_inorder(temp->right);
    }
}
void traverse_postorder(node *temp){
    if(temp!=NULL){
        traverse_postorder(temp->left);
        traverse_postorder(temp->right);
        printf(" %c",temp->data);
        
    }
}
