//
// Created by Lenovo on 4/2/2024.
//
#include"Myominhtet.h"
#include"stdio.h"
#include"stdbool.h"
#include "stdlib.h"


int main(){
    enqueueQueue_arr(10);
    enqueueQueue_arr(20);
    enqueueQueue_arr(30);
    enqueueQueue_arr(40);
    enqueueQueue_arr(50);
    displayQueue_Array();
    dequeueQueue_Array();
    dequeueQueue_Array();
    dequeueQueue_Array();
    dequeueQueue_Array();
    dequeueQueue_Array();
    displayQueue_Array();

    return 0;
}