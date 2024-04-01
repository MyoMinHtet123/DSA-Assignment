//
// Created by Lenovo on 1/11/2024.
//

#include<stdio.h>
#include<stdlib.h>

//function declare
void email_valid(char to_valid_email[30]);
int email_scanner(char scan_email[30]);
void menu();
void registration();
void login();
void login_check(char l_email[30],char l_password[30]);
int compare_two_char_array(char first[30],char second[30]);
int size_of_char(char arr[30]);
void my_privilege(int user_id);
void user_info_chane(int user_id);
void transition(int user_id);

//global
int g_userCount=0;
int g_login_check=-1;
int email_validation=-1;

//declare structure
struct Structure{
    char name[30];
    char email[30];
    char password[30];
    int phone_number;
    int points;
    int id;
};
struct Structure db[10];

int main(){
    menu();

    return 0;
}
void menu(){
    while(1){
        int op=0;
        printf("Well come to our system\n");
        printf("Press 1 to login\nPress 2 to register\nPress 3 to exit\nEnter:");
        scanf("%d",&op);
        if(op==1){
            login();
        }else if(op==2){
            registration();
        }else{
            exit(1);
        }
    }
}
void registration(){

    printf("This is registration\n");
    printf("Enter your name:");
    scanf(" %[^\n]",&db[g_userCount].name);
    int exit_or_not=-1;
    while(exit_or_not==-1) {
        printf("Enter your email:");
        scanf(" %[^\n]", &db[g_userCount].email);
        exit_or_not= email_scanner(db[g_userCount].email);
        if(exit_or_not==-1){
            printf("your email already registered\n");
            printf("Enter new email address\n");
        }
    }
    printf("Enter your password:");
    scanf(" %[^\n]",&db[g_userCount].password);
    printf("Enter your phone number:");
    scanf("%d",&db[g_userCount].phone_number);
    db[g_userCount].points=500;
    db[g_userCount].id=g_userCount;

    printf("your name is:%s\n",db[g_userCount].name);
    printf("your email is:%s\n",db[g_userCount].email);
    printf("your password is:%s\n",db[g_userCount].password);
    printf("your phone number is:%d\n",db[g_userCount].phone_number);
    printf("you have asm point %d\n",db[g_userCount].points);
    printf("your id is:%d\n",db[g_userCount].id);

    g_userCount++;
}
void login(){
    char l_email[30];
    char l_password[30];
    printf("This is login function\n");
    printf("Enter your email:");
    scanf(" %[^\n]",&l_email);
    printf("Enter your password:");
    scanf(" %[^\n]",&l_password);
    login_check(l_email,l_password);
    if(g_login_check!=-1){
        printf("login successful\n");
        my_privilege(g_login_check);
    }else{
        printf("login fail!\n");
        menu();
    }


}
void login_check(char l_email[30],char l_password[30]){
    g_login_check=-1;
    for(int i=0;i<g_userCount;i++) {
        int check_email = compare_two_char_array(db[i].email,l_email);
        if(check_email==1){
            int check_password= compare_two_char_array(db[i].password,l_password);
            if(check_password==1){
                g_login_check=db[i].id;
            }
        }
    }

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
    if(same==size1){
        return 1;
    }else{
        return 0;
    }

}
int size_of_char(char arr[30]){
    int size=0;
    for(int i=0;i<30;i++){
        if(arr[i]=='\0'){
            break;
        }else{
            size++;
        }
    }
    return size;
}
void my_privilege(int user_id){
    int user_op=-1;
    printf("Well come sir %s\n",db[user_id].name);
    printf("This is your id %d\n",db[user_id].id);
    printf("Your point is %d\n",db[user_id].points);
    printf("What do you want to do\n");
    printf("Press 0 to logout\nPress 1 to menu\nPress 2 to user info change:\n");
    printf("Press 3 to transition\nEnter:");
    scanf("%d",&user_op);
    if(user_op==0){
        exit(1);
    }else if(user_op==1){
        menu();
    }else if(user_op==2){
        user_info_chane(user_id);
    }else if(user_op==3){
        transition(user_id);
    }
    else{
        printf("Wrong operation\n");
        my_privilege(user_id);
    }
}
void user_info_chane(int user_id){
    int change_op=0;

    printf("Enter 1 to change name\nEnter 2 to change email\nEnter 3 to change password\nEnter 4 to change to phone number\n");
    printf("Enter:");
    scanf("%d",&change_op);
    if(change_op==1){
        printf("This is your exist name:%s\n",db[user_id].name);
        for(int i=0;i<30;i++){
            db[user_id].name[i]='\0';
        }
        printf("Enter your new name:");
        scanf(" %[^\n]",&db[user_id].name);
        printf("This is your new name:%s\n",db[user_id].name);
    }else if(change_op==2){
        printf("This is your exist email:%s\n",db[user_id].email);
        for(int a=0;a<30;a++){
            db[user_id].email[a]='\0';
        }
        printf("Enter your new name:");
        scanf(" %[^\n]",&db[user_id].email);
        printf("This is your new name:%s",db[user_id].email);
    }
}
int email_scanner(char scan_email[30]){
    int exit_or_not=-1;
    if(g_userCount==0){
        return 1;
    }else {

        for (int i = 0; i < g_userCount; i++) {
            exit_or_not = compare_two_char_array(db[i].email, scan_email);
            if (exit_or_not == 1) {
                return -1;
            }
        }

    }
    return 1;
}
void email_valid(char to_valid_email[30]){
    int first_count=0;
    char one_char;
    int first_valid=0;
    int array_size= size_of_char(to_valid_email);
    for(int i=0;i<array_size;i++){
        if(to_valid_email[i]=='@'){
            break;
        }else{
            first_count++;
        }
    }
    for(int x=0;x<first_count;x++){
        one_char=to_valid_email[x];
        if((one_char>=48 && one_char<=57)||(one_char>=97 && one_char<=122)){
            first_valid++;
        }else{
            first_valid=-1;
        }

    }
    if(first_valid!=first_count ||first_count==array_size ||first_count==0){
        email_validation=-1;
        return;
    }else{
        email_validation=1;
    }

    char gmail[11]={'@','g','m','a','i','l','.','c','o','m'};
    char yahoo[11]={'@','y','a','h','o','o','.','c','o','m'};
    char outlook[12]={'@','o','u','t','l','o','o','k','.','c','o','m'};
    char apple[11]={'@','a','p','p','l','e','.','c','o','m'};
    char n1c[11]={'@','n','1','c','.','c','o','m'};

    int second_count=0;
    char second_char[13];
    second_count=array_size-first_count;
    int sec=0;
    for(int xxx=first_count;xxx<array_size;xxx++){
        second_char[sec]=to_valid_email[xxx];
        sec++;
    }
    int g= compare_two_char_array(second_char,gmail);
    int y= compare_two_char_array(second_char,yahoo);
    int o= compare_two_char_array(second_char,outlook);
    int a= compare_two_char_array(second_char,apple);
    int n= compare_two_char_array(second_char,n1c);
    if(g||y||o||a||n){
        email_validation=1;
        printf("second part checking complete\n");

    }else{
        printf("second email valid fail\n");
        email_validation=-1;
    }
}
void transition(int user_id){
    int transfer_op=0;
    printf("This is transition\n");
    printf("Press 1 to transfer points\nPress 2 to privilege\nEnter:");
    scanf("%d",&transfer_op);
    if(transfer_op==1) {
        char receiver_email[30];
        printf("your point is %d\n", db[user_id].points);
        printf("Enter receiver email :");
        scanf(" %[^\n]", &receiver_email);

        for (int i = 0; i < g_userCount; i++) {
            int c_email = compare_two_char_array(db[i].email, receiver_email);
            if (c_email == 1) {
                if (db[i].id == db[user_id].id) {
                    printf("Sorry!It is not allow to transfer point to your own account!\n");
                    my_privilege(user_id);
                }
                int t_point = 0;
                printf("receiver id is %d\n", db[i].id);
                printf("how many point do you want to transfer:");
                scanf("%d", &t_point);
                if ((t_point <= 0) || (t_point > db[user_id].points)) {
                    printf("wrong\n");
                    printf("!!!Point must less than point you have(or equal) and greater 0\n");
                    transition(user_id);
                } else {
                        db[i].points += t_point;
                        printf("%s now have %d point\n", db[i].email, db[i].points);
                        db[user_id].points -= t_point;
                        transition(user_id);
                }

            }
        }
    }else if(transfer_op==2){
        my_privilege(user_id);
    }else{
        my_privilege(user_id);
    }
}



