//
// Created by Lenovo on 12/13/2023.
//
#include<stdio.h>
int addition();
int subtraction();
int multiplication();
int division();
int main(){

    char op;

    printf("Enter the operation to perform(+,-,*,/):");
    scanf("%c",&op);
    if(op=='+'){
        addition();
    }
    else if(op=='-'){
        subtraction();
    }
    else if(op=='*'){
        multiplication();
    }else  if(op=='/'){
        division();
    }
    else{
        printf("Wrong operation!");
    }


    return 0;
}

int addition(){
    int num1=0;
    int num2=0;
    int total=0;
    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    total=num1+num2;
    printf("%d + %d= %d",num1,num2,total);

    return 0;
}
int subtraction(){
    int num1=0;
    int num2=0;
    int total=0;
    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    total=num1-num2;
    printf("%d - %d= %d",num1,num2,total);

    return 0;
}
int multiplication(){
    int num1=0;
    int num2=0;
    int total=0;
    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    total=num1*num2;
    printf("%d * %d= %d",num1,num2,total);

    return 0;
}
int division(){
    int num1=0;
    int num2=0;
    int total=0;
    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    total=num1/num2;
    printf("%d / %d=%d",num1,num2,total);

    return 0;
}