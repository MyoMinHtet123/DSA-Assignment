//
// Created by Lenovo on 2/21/2024.
//

#include"stdio.h"
#include"stdlib.h"


//struct
struct Node{

    int data;
    struct Node *prev;
    struct Node *next;
};

//reverse function
void reverseFUn(struct Node** head){
    struct Node *temp;
    struct Node *previous;
    previous=NULL;
    temp=(*head);
    while(temp!=NULL){
        if(temp->next==NULL){
            temp->prev=NULL;
        }
        temp->prev=temp->next;
        temp->next=previous;
        previous=temp;
        temp=previous->prev;

    }
    *head=previous;
}

void insertBeginning(struct Node **head,int value){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=value;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL) {
        (*head)=new;
        return;
    }else{
        (*head)->prev = new;
         new->next=(*head);
        (*head)=new;
        return;
    }
}
void showData(struct Node *node){

    while(node!=NULL){
        printf("%d ",node->data);
        node=(node)->next;
    }
    printf("\n");
}

void deleteNode(struct Node** head,int key){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    struct Node *prev_ref=(struct Node*)malloc(sizeof(struct Node));
    temp=*head;

    //for the first node
    if(temp!=NULL&& temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL&&temp->data!=key){
        prev_ref=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
        if(temp->next==NULL){
            prev_ref->next=NULL;
            free(temp);
            return;
        }

        prev_ref->next = temp->next;
        temp->next->prev = prev_ref;
        free(temp);

}
int main(){
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    head=NULL;
    insertBeginning(&head,100);
    insertBeginning(&head,200);
    insertBeginning(&head,300);
    insertBeginning(&head,400);
    insertBeginning(&head,500);
    insertBeginning(&head,600);
    insertBeginning(&head,700);

    printf("\nInsert\n");
    showData(head);

    deleteNode(&head,100);
    deleteNode(&head,300);
    printf("Delete\n");
    showData(head);

    reverseFUn(&head);
    printf("\nReverse\n");
    showData(head);

    deleteNode(&head,500);
    deleteNode(&head,700);
    printf("After reverse and delete\n");
    showData(head);

    return 0;
}