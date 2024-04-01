//
// Created by Lenovo on 12/28/2023.
//

#include<stdio.h>
#include<stdlib.h>

//function declare
void menu();
void registration();
void login();
void copy_two_char_array(char first[30],char second[30]);
int size_of_char_array(char array[30]);
int compare_two_char_array(char first[30],char second[30]);
void login_checking(char l_email[30],char l_password[30]);

//global
int g_userCount=0;
int g_login_check=0;

//Declaring struct
struct Structure{
    char name[30];
    char email[30];
    char password[30];
    int phone;
    int id;
};

struct Structure user[5];

int main(){
    menu();

    return 0;
}
void menu(){
  while(1) {
      printf("\n");
      int op = 0;
      printf("Well come to our system.\n");
      printf("Press 1 to register\nPress 2 to login\nPress 3 to logout\nEnter:");
      scanf("%d", &op);
      if (op == 1) {
          registration();
      } else if (op == 2) {
          login();
      }else {
          exit(1);
      }

  }
}
void registration(){
    char r_name[30];
    char r_email[30];
    char r_password[30];
    int r_phone;
    printf("This is registration.\n");
    printf("Enter your name:");
    scanf(" %[^\n]",&r_name);
    printf("Enter your email:");
    scanf(" %[^\n]",&r_email);
    printf("Enter your password:");
    scanf(" %[^\n]",&r_password);
    printf("Enter your phone number:");
    scanf("%d",&r_phone);

    copy_two_char_array(user[g_userCount].name,r_name);
    printf("You name :%s\n",user[g_userCount].name);

    copy_two_char_array(user[g_userCount].email,r_email);
    printf("This is your email:%s\n",user[g_userCount].email);

    copy_two_char_array(user[g_userCount].password,r_password);
    printf("This is your password:%s\n",user[g_userCount].password);

     user[g_userCount].phone=r_phone;
     printf("This is your phone number:%d\n",user[g_userCount].phone);

     user[g_userCount].id=g_userCount;
     printf("This is your id:%d",user[g_userCount].id);

     g_userCount++;

}
void login(){
    char l_email[30];
    char l_password[30];
    printf("This is login .\n");
    printf("Enter your email:");
    scanf(" %[^\n]",&l_email);
    printf("Enter your password:");
    scanf(" %[^\n]",&l_password);

    login_checking(l_email,l_password);
    if(g_login_check!=-1){
        printf("login success!\n");
        printf("Your id is:%d\n",g_login_check);
        menu();
    }else{
        printf("login fail!\n");
        menu();
    }
}
void login_checking(char l_email[30],char l_password[30]){
     g_login_check=-1;
    for(int i=0;i<g_userCount;i++) {
        int check_email = compare_two_char_array(user[i].email,l_email);
        if(check_email==1){
            int check_password= compare_two_char_array(user[i].password,l_password);
            if(check_password==1){
               g_login_check= user[i].id;
                break;
            }
        }
    }
}
void copy_two_char_array(char first[30],char second[30]){
    for (int i=0;i<30;i++){
        if(second[i]=='\0'){
            break;
        }else{
            first[i]=second[i];
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
   }
   if(same==size1){
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
