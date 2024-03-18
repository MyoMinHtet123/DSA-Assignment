//
// Created by Lenovo on 3/9/2024.
//

#include"Encry.h"
#ifndef PROGRAMMING_DECRY_H
#define PROGRAMMING_DECRY_H
#include"stdio.h"

void decryption(char encrypt[100],char *key){
    int size_of_enc= char_size(encrypt);
    int size_of_k= char_size(key);
    char c;
    printf("\n");
    for(int e=0;e<size_of_enc;e++){
        char d=~encrypt[e];
        for(int k=0;k<size_of_k;k++){
            char ke=key[k];
            c= d-ke;
        }
        printf("%c",c);
    }
}
#endif //PROGRAMMING_DECRY_H
