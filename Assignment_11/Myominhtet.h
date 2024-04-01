//
// Created by Lenovo on 3/17/2024.
//

#ifndef PROGRAMMING_MYOMINHTET_H
#define PROGRAMMING_MYOMINHTET_H

#include"stdio.h"
#include"stdlib.h"

//Singly Linked List
struct Node{
    int data;
    struct Node *next;
};

struct Node* create_new_SLL_node(int value){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=value;
    new->next=NULL;
return new;
}

void insertAtBegin_SLL(struct Node** head,int value){
    struct Node *new_node= create_new_SLL_node(value);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    new_node->next=*head;
    *head=new_node;
}
void insertEnd_SLL(struct Node** head,int d){
    struct Node *new= create_new_SLL_node(d);
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
}
int lengthOf_SLL_node(struct Node *head){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}
void insertSpecific_SLL(struct Node **head,int position,int data){
    int length= lengthOf_SLL_node(*head);
    if(position==1){
        insertAtBegin_SLL(head,data);
        return;
    }
    if(position<1 || position>length+1){
        printf("\nInvalid position");
        return;
    }
    if(position>length){
        insertEnd_SLL(head,data);
        return;
    }
    struct Node *temp=*head;
    struct Node *new= create_new_SLL_node(data);
    int i=1;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    new->next=temp->next;
    temp->next=new;
}

void show_all_dataSLL(struct Node *head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}
void deleteBegin_SLL(struct Node **head){
    if(*head==NULL){
        printf("\nLinked List is empty");
        return;
    }
    struct Node* temp=*head;
    *head=(*head)->next;
    free(temp);
}
void deleteSpecificSLL_node(struct Node **head,int position){
   int length= lengthOf_SLL_node(*head);
   if(position==1){
       deleteBegin_SLL(head);
       return;
   }
   if(position<1 || position>length){
       printf("\nInvalid position");
       return;
   }
   struct Node* temp=*head,*previous;
   int i=1;
   while(i<position){
       previous=temp;
       temp=temp->next;
       i++;
   }
   previous->next=temp->next;
   free(temp);
}
void reverseSLL(struct Node **head){
    struct Node* temp=*head,*n;
    struct Node* previous=NULL;
    while(temp!=NULL){
        n=temp->next;
        temp->next=previous;
        previous=temp;
        temp=n;
    }
    *head=previous;
}


//Doubly Linked list
struct DLL_Node{
    struct DLL_Node *prev;
    int data;
    struct DLL_Node *next;
};
struct DLL_Node* createNewDLL_node(int data){
    struct DLL_Node* new=(struct DLL_Node*)malloc(sizeof(struct DLL_Node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
int lengthOfDLL_node(struct DLL_Node* head){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}

void insertAtBegin_DLL(struct DLL_Node** head,int data){
    struct DLL_Node *new_node= createNewDLL_node(data);
    if(*head==NULL){
        *head=new_node;
        return;
    }
        new_node->next=*head;
        (*head)->prev=new_node;
        *head=new_node;
}
void insertEnd_DLL(struct DLL_Node** head,int d){
    struct DLL_Node* new= createNewDLL_node(d);
    struct DLL_Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
}
void insertSpecific_DLL(struct DLL_Node **head,int position,int data){
    int length= lengthOfDLL_node(*head);
    if(position==1){
        insertAtBegin_DLL(head,data);
        return;
    }
    if(position<1 || position>length+1){
        printf("\nInvalid position!");
        return;
    }
    if(position>length){
        insertEnd_DLL(head,data);
        return;
    }
    struct DLL_Node* temp=*head;
    struct DLL_Node* new= createNewDLL_node(data);
    int i=1;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    new->next=temp->next;
    new->prev=temp;
    temp->next->prev=new;
    temp->next=new;
}
void show_all_data_DLL(struct DLL_Node *node){
    while(node!=NULL){
        printf("\n%d",node->data);
        node=node->next;
    }
}
void deleteBeginDLL_node(struct DLL_Node **head){
    if(*head==NULL){
        printf("\nDouble Linked List is empty");
        return;
    }
    struct DLL_Node *temp=*head;
    if(temp->prev==NULL && temp->next==NULL){
        *head=NULL;
    }else {
        *head = temp->next;
        (*head)->prev = NULL;
    }
    free(temp);
}
void deleteEndDLL_node(struct DLL_Node **head){
    struct DLL_Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}
void deleteSpecificDLL_node(struct DLL_Node **head,int position){
    int length= lengthOfDLL_node(*head);
    if(position==1){
        deleteBeginDLL_node(head);
        return;
    }
    if(position<1 || position>length){
        printf("\nInvalid position");
        return;
    }
    if(position==length){
        deleteEndDLL_node(head);
        return;
    }
    struct DLL_Node* temp,*previous;
    temp=*head;
    int i=1;
    while(i<position){
        previous=temp;
        temp=temp->next;
        i++;
    }
    previous->next=temp->next;
    previous->next->prev=previous;
    free(temp);
}
void reverseDLL(struct DLL_Node** head){
    struct DLL_Node *temp=*head;
    struct DLL_Node *previous=NULL;
    while(temp!=NULL){
        temp->prev=temp->next;
        temp->next=previous;
        previous=temp;
        temp=previous->prev;
    }
    *head=previous;
}


//Stack Data Structure With Array
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
        printf("Stack over flow\n");
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
        printf("\nStack under flow");
        exit(-1);
    }else{
        return stack->items[stack->top--];
    }
}
int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("\nStack is empty");
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


//Stack Data Structure With Linked List
struct Stack_LL{
    struct Node *top;
};
void initStack_LL(struct Stack_LL *s){
    s->top=NULL;
}
void pushStack_LL(struct Stack_LL *s,int data){
    struct Node* new= create_new_SLL_node(data);
    if(s->top==NULL){
        s->top=new;
        return;
    }
    new->next=s->top;
    s->top=new;
}
void popStack_LL(struct Stack_LL *s){
    if(s->top==NULL){
        printf("\nStack underflow");
        return;
    }
    struct Node* temp=s->top;
    s->top=s->top->next;
    printf("\nPop data =%d",temp->data);
    free(temp);
}

void peekStack_LL(struct Stack_LL s){
    if(s.top==NULL){
        printf("\nStack is empty");
        return;
    }
    printf("\nPeek data=%d",s.top->data);
}
void showAll_dataStack_LL(struct Stack_LL s){
    struct Node* temp=s.top;
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }
}


//Tree Data Structure
struct T_node{
    int data;
    struct T_node* left;
    struct T_node* right;
};
struct T_node* create_new_T_node(int data){
    struct T_node* new=(struct T_node*)malloc(sizeof(struct T_node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}
struct T_node* insert(struct T_node *root,int d){
    if(root==NULL){
        struct T_node* new= create_new_T_node(d);
        root=new;
    }else if(d<root->data){
        root->left=insert(root->left,d);
    }else{
        root->right= insert(root->right,d);
    }
    return root;
}
struct T_node *findMid(struct T_node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct T_node* delete(struct T_node* root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=delete(root->left,data);
    }else if(data>root->data){
        root->right=delete(root->right,data);
    }else {
        if (root->left == NULL) {
            struct T_node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct T_node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct T_node* temp= findMid(root->right);
            root->data=temp->data;
            root->right= delete(root->right,temp->data);
        }
    }
    return root;
}
void inorder(struct T_node* root){
    if(root==NULL){
        return;
    }
        inorder(root->left);
        printf("%d-",root->data);
        inorder(root->right);

}
void preorder(struct T_node* r){
    if(r==NULL){return;}
        printf("%d-",r->data);
        preorder(r->left);
        preorder(r->right);

}
void postorder(struct T_node* r){
    if(r==NULL){
        return;
    }
    postorder(r->left);
    postorder(r->right);
    printf("%d_",r->data);
   // printf("%d_",r->data);
}


#endif //PROGRAMMING_MYOMINHTET_H
