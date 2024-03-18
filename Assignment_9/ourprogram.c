//
// Created by Lenovo on 3/5/2024.
//

#include"Encry.h"
#include"Decry.h"
#include"stdio.h"


int main(){
    char *plainText="This is plain text";
    char *keys="n1c321";
    encryption(plainText,keys);
    int size_of_en= char_size(encrypted);
    printf("\nencrypted char size=%d",size_of_en);

    decryption(encrypted,keys);
    printf("\n");

    return 0;
}