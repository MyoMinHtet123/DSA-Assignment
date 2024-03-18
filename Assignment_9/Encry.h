//
// Created by Lenovo on 3/5/2024.
//
#ifndef PROGRAMMING_ENCRY_H
#define PROGRAMMING_ENCRY_H
#include"stdio.h"
#include"stdlib.h"

//global var
char encrypted[10];

//function declare
int char_size(char *arr);

void encryption(char *plain,char *key){

    int size_of_plain=char_size(plain);
    printf("plain text size=%d\n",size_of_plain);
    int size_of_key=  char_size(key);
    printf("key size=%d\n",size_of_key);
    encrypted[size_of_plain];
    char c;
    for(int e=0;e<size_of_plain;e++) {
        char p = plain[e];
        for (int k = 0; k < size_of_key; k++) {
             c= p + key[k];
        }
        encrypted[e]= ~c;
    }
    for(int i=0;i<size_of_plain;i++){
        printf("%c",encrypted[i]);
    }
}
int  char_size(char arr[100]) {
    int size=0;
    for (int i = 0; i < 100; i++) {
        if (arr[i] == '\0') {
            break;

        } else {
            size++;
        }
    }
    return size;
}



#endif //PROGRAMMING_ENCRY_H
