//
// Created by Lenovo on 2/13/2024.
//

#ifndef PROGRAMMING_VALIDATIONUTIL_H
#define PROGRAMMING_VALIDATIONUTIL_H
#include"myprogram.h"
#include"transitionUtil.h"
#include"stdio.h"


void email_valid(char to_valid_email[30]){
    //check first part

    int first_count=0;
    int first_valid=0;
    int size_of_email= size_of_char(to_valid_email);
    for(int i=0;i<size_of_email;i++){
        if(to_valid_email[i]=='@'){
            break;
        }else{
            first_count++;
        }
    }
    for(int a=0;a<first_count;a++){
        char ch=to_valid_email[a];
        if((ch>=48 && ch<=57)||(ch>=97 && ch<=122)){
            first_valid++;
        }else{
            first_valid=-1;
        }
    }
    if(first_count!=first_valid || first_count==0 ||first_count==size_of_email){
        email_validation=-1;
        printf("first part is not valid\n");
        return ;
    }else{
        email_validation=1;
    }

    char second_char[30];
    for(int x=0;x<13;x++){
        second_char[x]='\0';
    }
    int s=0;
    for(int b=first_count;b<size_of_email;b++){
        second_char[s]=to_valid_email[b];
        s++;
    }

    char gmail[30]={'@','g','m','a','i','l','.','c','o','m'};
    char yahoo[30]={'@','y','a','h','o','o','.','c','o','m'};
    char outlook[30]={'@','o','u','t','l','o','o','k','.','c','o','m'};
    char apple[30]={'@','a','p','p','l','e','.','c','o','m'};
    char n1c[30]={'@','n','1','c','.','c','o','m'};

    int gm= compare_two_char_array(gmail,second_char);
    int y= compare_two_char_array(yahoo,second_char);
    int o= compare_two_char_array(outlook,second_char);
    int a= compare_two_char_array(apple,second_char);
    int n= compare_two_char_array(n1c,second_char);

    if(!(gm || y ||o || a ||n)){
        printf("second part is not valid\n");
        email_validation=-1;
        return;
    }else{
        email_validation= 1;
    }

    for(int c=0;c<g_userCount;c++){
        int exit_or_not= compare_two_char_array(data[c].email,to_valid_email);
        if(exit_or_not==1){
            printf("%s\n",data[c].email);
            printf("%s\n",to_valid_email);
            email_validation=-1;
            printf("your email already have\n");
            return;
        }else{
            email_validation=1;
        }
    }
}

void password_valid(char to_valid_password[30]){
    int size_p= size_of_char(to_valid_password);
    if(size_p<6){
        password_validation=-1;
        printf("password must be more than 6 character\n");
        return ;
    }else{
        password_validation=1;
    }
    int capital=0;
    for(int i=0;i<size_p;i++){
        if(to_valid_password[i]>=65 && to_valid_password[i]<=90){
            capital=1;
        }
    }
    int small=0;
    for(int a=0;a<size_p;a++){
        if(to_valid_password[a]>=97 && to_valid_password[a]<=122){
            small=1;
        }
    }
    int number=0;
    for(int c=0;c<size_p;c++){
        if(to_valid_password[c]>=48 && to_valid_password[c]<=57){
            number=1;
        }
    }
    int special=0;
    for(int b=0;b<size_p;b++){
        char ch=to_valid_password[b];
        if(!(ch>=48 && ch<=57)&&!(ch>=65&&ch<=90)&&!(ch>=97&&ch<=122)){
            special=1;
        }
    }
    if(!(capital && small && number && special)){
        password_validation=-1;
        printf("password is not valid\n");
        return;
    }else{
        password_validation=1;
    }

}

#endif //PROGRAMMING_VALIDATIONUTIL_H
