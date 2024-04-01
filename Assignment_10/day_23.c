//
// Created by Lenovo on 3/14/2024.
//
#include"stdio.h"
#include"stdlib.h"
#include"Myominhtet.h"

int main(){
   struct DLL_Node* head=NULL;
    insertSpecific_DLL(&head,1,100);
    insertSpecific_DLL(&head,1,200);
    insertSpecific_DLL(&head,1,300);
    insertSpecific_DLL(&head,1,400);
    insertSpecific_DLL(&head,1,500);
    show_all_data_DLL(head);
    deleteSpecificDLL_node(&head,1);
    deleteSpecificDLL_node(&head,4);
    deleteSpecificDLL_node(&head,2);
    deleteSpecificDLL_node(&head,2);
    deleteSpecificDLL_node(&head,1);
    printf("\n");
    show_all_data_DLL(head);


    return 0;
}