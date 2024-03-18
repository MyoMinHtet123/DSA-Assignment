//
// Created by Lenovo on 3/17/2024.
//

#ifndef PROGRAMMING_MYOMINHTET_H
#define PROGRAMMING_MYOMINHTET_H

#include"stdio.h"
#include"stdlib.h"

//Singly Linked List
struct S_Node{
    int data;
    struct S_Node *next;
};

struct S_Node* create_new_sll_node(int value){
    struct S_Node *new=(struct S_Node*)malloc(sizeof(struct S_Node));
    new->data=value;
    new->next=NULL;
return new;
}

void sll_insertAtBegin(struct S_Node** head,int value){
    struct S_Node *new_node= create_new_sll_node(value);
    new_node->next=*head;
    *head=new_node;
}

void sLL_show_all_data(struct S_Node *head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}
void sLL_delete_node(struct S_Node **head,int key){
    struct S_Node *temp=*head,*prev=NULL;
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
    prev->next=temp->next;
    free(temp);
}
void sLL_append(struct S_Node**head,int value){
    struct S_Node* new= create_new_sll_node(value);
    struct S_Node *temp=*head;
    if(*head==NULL){
        *head=new;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
}

//Doubly Linked list
struct D_Node{
    struct D_Node *prev;
    int data;
    struct D_Node *next;
};

void DLL_insertAtBegin(struct D_Node** head,int data){
    struct D_Node *new_node= (struct D_Node*)malloc(sizeof(struct D_Node));
    new_node->data=data;
    if(*head==NULL){
        new_node->next=NULL;
        new_node->prev=NULL;
        *head=new_node;
    }else{
        new_node->prev=NULL;
        new_node->next=*head;
        (*head)->prev=new_node;
        *head=new_node;
    }
}
void DLL_show_all_data(struct D_Node *node){
    while(node!=NULL){
        printf("%d\n",node->data);
        node=node->next;
    }

}
void DLL_deleteNode(struct D_Node** head,int key){
    struct D_Node *temp=*head;
    struct D_Node *prev_ref=(struct D_Node*)malloc(sizeof(struct D_Node));

    //for the first node
    if(temp!=NULL&& temp->data==key){
        temp->next->prev=NULL;
        *head=temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL&&temp->data!=key){
        prev_ref=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
    //last node
    if(temp->next==NULL){
        prev_ref->next=NULL;
        free(temp);
        return;
    }else {
        prev_ref->next = temp->next;
        temp->next->prev = prev_ref;
        free(temp);
    }
}
void DLL_reverseFUn(struct D_Node** head){
    struct D_Node *temp=*head;
    struct D_Node *previous=NULL;

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


//Assignment_10 data structure
#define MAX 10
struct Stack{
    int items[MAX];
    int top;
};

void initialize(struct Stack *stack){
    stack->top=-1;
}

int isFull(struct Stack *stack){
    return(stack->top==MAX-1);
}
void push(struct Stack *stack,int value){
    if(isFull(stack)){
        printf("stack is full\n");
        exit(1);
    }else{
        stack->items[++stack->top]=value;
    }
}
int isEmpty(struct Stack *stack){
    return(stack->top==-1);
}
int pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("stack is empty");
        exit(-1);
    }else{
        return stack->items[stack->top--];
    }
}
int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Assignment_10 is empty");
        return -1;
    }else{
        return stack->items[stack->top];
    }
}

void all_data_stack(struct Stack* stack){
    for(int i=stack->top;i>-1;i--){
        printf("%d\n",stack->items[i]);
    }
}


#endif //PROGRAMMING_MYOMINHTET_H
