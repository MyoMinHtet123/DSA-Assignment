//
// Created by Lenovo on 2/13/2024.
//

#ifndef PROGRAMMING_MYPROGRAM_H
#define PROGRAMMING_MYPROGRAM_H

#include<stdio.h>
#include<stdlib.h>

//function declare
void menu();
void registration();
void record_data();
void loading_data();
void email_valid(char to_valid_email[30]);
int compare_two_char_array(char first[30],char second[30]);
void password_valid(char to_valid_password[30]);
void login();
void login_checking(char l_email[30],char l_password[30]);
void my_privilege(int user_id);
void admin_sector(int id);
void ban_user();
void suspend();
void user_info_change(int user_id);
void copy_two_char_array(char first[30],char second[30]);
void transition_checking(int user_id);
void transaction(int sender_id , int receiver_id,double amount);
void printing_all_data();
void transition_record(int sender_id,int receiver_id,double amount);
void integer_to_charArrayFUn( double integer);
int to_check_phone(int phone);
int size_of_char(char arr[500]);
void get_t();

//Global declare
int g_userCount=0;
int email_validation=-1;
int password_validation=-1;
int login_check=-1;
char time_array[25];

typedef struct{
    char trans[100];
}t_record;

typedef struct{
    int id;
    char name [30];
    char email[30];
    char password[30];
    int phone;
    int ban;
    int suspend;
    double amount;
    int trans_counter;

    t_record trans_record[100];

}Db;
Db data[100];

void menu(){
    while(1) {
        int op=0;
        printf("Well come to our system\n");
        printf("Press 1 to registration\nPress 2 to login\nPress 3 to exit\nEnter:");
        scanf("%d",&op);
        if(op==1){
            registration();
        }else if(op==2){
            login();
        }else{
            record_data();
            exit(1);
        }
    }
}
void registration(){
    printf("This is registration!\n");
    printf("Please enter your name:");
    scanf(" %[^\n]",data[g_userCount].name);
    email_validation=-1;
    while(email_validation==-1) {
        printf("Please enter your email:");
        scanf(" %[^\n]", data[g_userCount].email);
        email_valid(data[g_userCount].email);
    }
    password_validation=-1;
    while(password_validation==-1) {
        printf("Enter your password:");
        scanf(" %[^\n]", data[g_userCount].password);
        password_valid(data[g_userCount].password);
    }
    int phone_validation=0;
    while(phone_validation!=-1) {
        printf("Enter your phone:");
        scanf("%d", &data[g_userCount].phone);
        phone_validation = to_check_phone(data[g_userCount].phone);
        if(phone_validation!=-1){
            printf("your phone number is not valid\n");
        }
    }

    data[g_userCount].amount=1000;
    data[g_userCount].id=g_userCount;
    data[g_userCount].ban=0;
    data[g_userCount].suspend=0;
    data[g_userCount].trans_counter=0;

    printf("Name:%s\n",data[g_userCount].name);
    printf("Email:%s\n",data[g_userCount].email);
    printf("Password:%s\n",data[g_userCount].password);
    printf("Phone:%d\n",data[g_userCount].phone);
    printf("Amount:%lf\n",data[g_userCount].amount);

    g_userCount++;
}
void login(){
    char l_email[30];
    char l_password[30];
    printf("This is login\n");
    printf("Enter your email to login:");
    scanf(" %[^\n]",l_email);
    printf("Enter your password to login:");
    scanf(" %[^\n]",l_password);
    login_check=-1;
    login_checking(l_email,l_password);
    if(login_check!=-1){
        if(data[login_check].ban==1 || data[login_check].suspend==1){
            printf("Your account is ban or suspend by admin\n");
            menu();
        }else {
            printf("login success\n");
            my_privilege(login_check);
        }
    }else{
        printf("login fail\n");
        menu();
    }
}
void login_checking(char l_email[30],char l_password[30]){
    int login_id=0;
    int email_check=0;
    int password_check=0;

    for(int i=0;i<g_userCount;i++) {
        email_check = compare_two_char_array(data[i].email, l_email);
        if(email_check==1) {
            login_id = data[i].id;
            break;
        }
    }
    for(int a=0;a<g_userCount;a++){
        password_check= compare_two_char_array(data[a].password,l_password);
        if(password_check==1){
            break;
        }
    }
    if(email_check && password_check){
        login_check=login_id;
    }else{
        login_check=-1;
    }
}
void my_privilege(int user_id){
    if(data[user_id].id<3){
        admin_sector(user_id);
    }else {
        int user_op = 0;
        printf("Well come sir %s\n", data[user_id].name);
        printf("Your id is %d\n", data[user_id].id);
        printf("You have point %lf\n", data[user_id].amount);
        printf("What do you want to do\n");
        printf("Press 0 to logout\nPress 1 to menu\nPress 2 to user info change\nPress 3 to transition\nEnter:");
        scanf("%d",&user_op);
        if (user_op == 0) {
            record_data();
            exit(1);
        } else if (user_op == 1) {
            menu();
        } else if (user_op == 2) {
            user_info_change(user_id);
        } else if (user_op == 3) {
            transition_checking(user_id);
        } else {
            printf("Wrong operation\n");
            my_privilege(user_id);
        }
    }

}
void admin_sector(int id){
    int admin_option=0;
    printf("This is form Admin :%s\n",data[id].name);
    printf("Admin ID:%d\n",data[id].id);
    printf("What do you want to do\n");
    printf("Enter 0 to logout\nEnter 1 to ban user \nEnter 2 to suspend user\nEnter 3 to menu\n");
    printf("Enter 4 to user info change\nEnter 5 to transition \nEnter:");
    scanf("%d",&admin_option);
    if(admin_option==0){
        record_data();
        exit(1);
    }else if(admin_option==1){
        ban_user();
    }else if(admin_option==2){
        suspend();
    }else if(admin_option==3){
        menu();
    }else if(admin_option==4){
        user_info_change(id);
    }else if(admin_option==5){
        transition_checking(id);
    }else{
        printf("Wrong operation!!\n");
        my_privilege(id);
    }
}
void ban_user(){
    int ban_id=0;
    printf("This is from banning user\n");
    printf("Enter user id to ban:");
    scanf("%d",&ban_id);
    if(ban_id<3){
        printf("wrong id\n");
        menu();
    }else {
        data[ban_id].ban = 1;
        printf("Banning user success\n");
    }
}
void suspend(){
    int suspend_id=0;
    printf("This is from suspending user\n");
    printf("Enter user id to suspend:");
    scanf("%d",&suspend_id);
    data[suspend_id].suspend=1;
    printf("Suspending user success\n");
}
int to_check_phone(int phone){

    for(int p=0; p<g_userCount; p++){

        if(data[p].phone==phone){
            return data[p].id;
        }
    }

    return -1;
}

int size_of_char(char arr[500]){
    int size=0;
    for(int i=0;i<500;i++){
        if(arr[i]=='\0'){
            break;
        }else{
            size++;
        }
    }
    return size;
}
int compare_two_char_array(char first[30],char second[30]){
    int same=0;
    int size1= size_of_char(first);
    int size2= size_of_char(second);
    if(size1==size2){
        for(int i=0;i<size1;i++){
            if(first[i]==second[i]){
                same++;
            }
        }
    }
    if(size1==same){
        return 1;
    }else{
        return 0;
    }

}
void record_data(){
    FILE *fptr;
    fptr=fopen("database.txt","w");
    if(fptr==NULL){
        perror("\n");
    }
    printf("recording data file\n");
    for(int i=0;i<g_userCount;i++) {

        fprintf(fptr, "%d %s %s %s %d %lf %d %d %d ",data[i].id, data[i].name, data[i].email, data[i].password,
                data[i].phone,data[i].amount,data[i].ban,data[i].suspend,data[i].trans_counter);
        for(int a=0;a<data[i].trans_counter;a++){
            fprintf(fptr,"%s ",data[i].trans_record[a].trans);
        }
        fprintf(fptr,"\n");
    }
    fclose(fptr);
    printf("success\n");
}
void loading_data(){
    FILE *fptr;
    fptr=fopen("database.txt","r");
    if(fptr==NULL){
        perror("\n");
        return;
    }
    for(int i=0;i<100;i++){
        fscanf(fptr,"%d%s%s%s%d%lf%d%d%d",&data[i].id,data[i].name,data[i].email,data[i].password,
               &data[i].phone,&data[i].amount,&data[i].ban,&data[i].suspend,&data[i].trans_counter);
        for(int a=0;a<data[i].trans_counter;a++){
            fscanf(fptr,"%s",data[i].trans_record[a].trans);
        }

        if(data[i].phone==0){
            break;
        }
        g_userCount++;
    }
    fclose(fptr);
    printf("retrieve data success\n");
    printf("Total user:%d\n\n",g_userCount);

}
void user_info_change(int user_id){
    int info_change=0;
    printf("Press 1 to change name\nPress 2 to change email\nPress 3 to change password");
    printf("Press 4 to change phone number:\nEnter:");
    scanf("%d",&info_change);
    if(info_change==1){
        printf("This is your name %s\n",data[user_id].name);
        for(int i=0;i<30;i++){
            data[user_id].name[i]='\0';
        }
        printf("Enter your new name:");
        scanf(" %[^\n]",data[user_id].name);
        printf("This is your new name %s\n",data[user_id].name);
        my_privilege(user_id);
    }else if(info_change==2){
        printf("This is your email %s\n",data[user_id].email);
        email_validation=-1;
        while(email_validation==-1) {
            char change_email[30];
            printf("Enter your new email:");
            scanf(" %[^\n]", change_email);
            email_valid(change_email);
            if(email_validation==1){
                for(int a=0;a<30;a++){
                    data[user_id].email[a]='\0';
                }

                copy_two_char_array(data[user_id].email,change_email);
            }
        }
        printf("This is your new email %s\n",data[user_id].email);
        my_privilege(user_id);
    }else if(info_change==3){
        printf("This is your password  %s\n",data[user_id].password);
        for(int c=0;c<30;c++){
            data[user_id].name[c]='\0';
        }
        password_validation=-1;
        while(password_validation==-1){
            printf("Enter your new password:");
            scanf(" %[^\n]",data[user_id].password);
            password_valid(data[user_id].password);
        }
        printf("This is your new password %s\n",data[user_id].password);
        my_privilege(user_id);
    }else if(info_change==4){
        printf("This is your phone number  %d\n",data[user_id].phone);
        printf("Enter your new phone number:");
        scanf("%d",&data[user_id].phone);
        printf("This is your new phone number %d\n",data[user_id].phone);
        my_privilege(user_id);
    }else{
        printf("Wrong option\n");
        my_privilege(user_id);
    }

}
void copy_two_char_array(char first[30],char second[30]){
    for(int i=0;i<30;i++){
        if(second[i]=='\0'){
            break;
        }else{
            first[i]=second[i];
        }
    }
}

void printing_all_data(){
    printf("Total user:%d\n",g_userCount);
    for(int i=0;i<g_userCount;i++){
        printf("%d_%s_%s_%s_%d_%lf_%d_%d_%d_",data[i].id,data[i].name,data[i].email,data[i].password,
               data[i].phone,data[i].amount,data[i].ban,data[i].suspend,data[i].trans_counter);
        for(int a=0;a<data[i].trans_counter;a++){
            printf("%s",data[i].trans_record[a].trans);
        }
        printf("\n");

    }

}


#endif //PROGRAMMING_MYPROGRAM_H
