//
// Created by Lenovo on 12/7/2023.
//
#include<stdio.h>

int main(){
    int i=0,size=10;
    int a=0,aa=0;
    int b=0,bb=0;
    for (i=0;i<size;i++){

        for(a=0;a<size-i;a++){
            printf(" ");
        }
        for(aa=1;aa<i*2;aa++){
            printf("*");
        }
        for(b=0;b<(size-i)*2;b++){
            printf(" ");
        }
        for (bb=1;bb<i*2;bb++){
            printf("*");
        }

        printf("\n");
    }

    return 0;
}