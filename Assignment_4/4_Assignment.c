//
// Created by Lenovo on 1/3/2024.
//


#include<stdio.h>
#include<stdlib.h>


//global
int g_userCount=0;
int g_login_check=-1;


//function declare
void login();
void menu();
void registration();
void copy_two_char_array(char first[30],char second[30]);
int size_of_char_array(char array[30]);
int compare_two_char_array(char first[30],char second[30]);
void login_checking(char l_email[30],char l_password[30]);
void my_privilege(int user_id);
void password_check(char r_password[30]);


//structure declare
struct Structure {
    char name[30];
    char email[30];
    char password[30];
    int phone_number;
    int id;
};

struct Structure user[10];

int main(){

    menu();

    return 0;
}
void menu(){
    while(1) {
        int op = 0;
        printf("\nWell come to our system!\n");
        printf("Press 1 to login\nPress 2 to registration\nPress 3 to logout\nEnter:");
        scanf("%d", &op);
        if (op == 1) {
            login();
        } else if (op == 2) {
            registration();
        } else {
            exit(1);
        }
    }

}
void login(){
    char l_email[30];
    char l_password[30];
    printf("This is login\n");
    printf("Please enter your email:");
    scanf(" %[^\n]",&l_email);
    printf("Please enter your password:");
    scanf(" %[^\n]",&l_password);

    login_checking(l_email,l_password);
    if(g_login_check!=-1){
        printf("login successful\n");
        printf("your id is :%d",g_login_check);
        my_privilege(g_login_check);
    }else{
        printf("login fail!");
        menu();
    }

}
void registration(){
    char r_name[30];
    char r_email[30];
    char r_password[30];
    int r_phone_number;
    printf("This is registration\n");
    printf("Please enter your name:");
    scanf(" %[^\n]",&r_name);

    printf("Pleas enter your email:");
    scanf(" %[^\n]",&r_email);
    for(int i=0;i<g_userCount;i++){
        int r_email_check= compare_two_char_array(user[i].email,r_email);
        if(r_email_check==1){
            printf("your email have been use by someone:\n");
            printf("please enter another email:");
            scanf(" %[^\n]",&r_email);
        }
    }
    printf("Please enter your password/password must be strong/must contain at least 6 character\n");
    printf("must contain number/capital letter/small letter/special character\n");
    scanf(" %[^\n]",&r_password);
    password_check(r_password);

    printf("Please enter your phone number:");
    scanf("%d",&r_phone_number);

    copy_two_char_array(user[g_userCount].name,r_name);
    printf("your name is:%s",user[g_userCount].name);

    copy_two_char_array(user[g_userCount].email,r_email);
    printf("your email is :%s\n",user[g_userCount].email);

    copy_two_char_array(user[g_userCount].password,r_password);
    printf("your password is :%s\n",user[g_userCount].password);

    user[g_userCount].phone_number=r_phone_number;
    printf("your phone number is:%d\n",user[g_userCount].phone_number);

    user[g_userCount].id=g_userCount;
    printf("your id is:%d\n",user[g_userCount].id);

    g_userCount++;

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
void login_checking(char l_email[30],char l_password[30]){
     g_login_check=-1;
    for (int i=0;i<g_userCount;i++){
        int email_check= compare_two_char_array(user[i].email,l_email);
        if(email_check==1){
            int password_check= compare_two_char_array(user[i].password,l_password);
            if(password_check==1){
                g_login_check=user[i].id;
                break;
            }
        }
    }

}
int compare_two_char_array(char first[30],char second[30]){
    int same=0;
    int size1= size_of_char_array(first);
    int size2= size_of_char_array(second);
    if(size1==size2){
        for(int i=0;i<size1;i++){
            if(first[i]==second[i]){
                same++;
            }
        }
    }if(same==size1){
        return 1;
    }else{
        return 0;
    }

}
int size_of_char_array(char array[30]){
    int size=0;
    for(int i=0;i<30;i++){
        if(array[i]=='\0'){
            break;
        }else{
            size++;
        }

    }
    return size;
}
void my_privilege(int user_id){
    int m_op=-1;
    printf("Well come sir:%s\n",user[user_id].name);
    printf("your phone number is :%d\n",user[user_id].phone_number);
    printf("what do you want to do\n");
    printf("Enter 0 to logout\nEnter 1 to menu\n");
    scanf("%d",&m_op);
    if(m_op==0){
        exit(1);
    }else if(m_op==1){
        menu();
    }
    else{
        printf("Wrong option!");
        my_privilege(user_id);
    }
}
void password_check(char r_password[30]){
    int size_password= size_of_char_array(r_password);
    if(size_password<6){
        printf("Password must contain at least 6 character:\n");
        printf("Enter your password:");
        scanf(" %[^\n]",r_password);

    }
    
}


