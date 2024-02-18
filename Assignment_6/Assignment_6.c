//
// Created by Lenovo on 1/25/2024.
//
#include<stdio.h>
#include<stdlib.h>


//function declare
void registration();
void menu();
void record_data();
void retrieve_data();
void email_valid(char to_valid_email[30]);
int size_of_char(char arr[30]);
int compare_two_char_array(char first[30],char second[30]);
void password_valid(char to_valid_password[30]);
void login();
void login_checking(char l_email[30],char l_password[30]);
void my_privilege(int user_id);
void user_info_change(int user_id);
void copy_two_char_array(char first[30],char second[30]);
void transition(int user_id);
void printing_all_data_from_file();
void transition_record(int sender_id,int receiver_id,char who,int amount);
void integer_to_charArrayFUn( int integer);

//Global declare
int g_userCount=0;
int email_validation=-1;
int password_validation=-1;
int login_check=-1;
char int_to_charArray[15];


typedef struct{
    int id;
    char name [30];
    char email[30];
    char password[30];
    int phone;
    int point;
    char transfer[1000];


}Db;
Db data[100];

int main(){


    retrieve_data();
    printing_all_data_from_file();

    menu();


    return 0;
}
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
    printf("Please enter your name:");
    scanf(" %[^\n]",&data[g_userCount].name);
    email_validation=-1;
    while(email_validation==-1) {
        printf("Please enter your email:");
        scanf(" %[^\n]", &data[g_userCount].email);
         email_valid(data[g_userCount].email);
    }
     password_validation=-1;
    while(password_validation==-1) {
        printf("Enter your password:");
        scanf(" %[^\n]", &data[g_userCount].password);
        password_valid(data[g_userCount].password);
    }
    printf("Enter your phone:");
    scanf("%d",&data[g_userCount].phone);

    printf("Enter your opening note:");
    scanf(" %[^\n]",&data[g_userCount].transfer);

    data[g_userCount].point=500;
    data[g_userCount].id=g_userCount;


    g_userCount++;

}
void login(){
    char l_email[30];
    char l_password[30];
    printf("This is login\n");
    printf("Enter your email to login:");
    scanf(" %[^\n]",&l_email);
    printf("Enter your password to login:");
    scanf(" %[^\n]",&l_password);
    login_check=-1;
     login_checking(l_email,l_password);
    if(login_check!=-1){
        printf("login success\n");
        printf("your id is %d\n",login_check);
        my_privilege(login_check);

    }else{
        printf("login fail\n");
        menu();
    }

}
void login_checking(char l_email[30],char l_password[30]){
    int l_id=0;
    int email_check=0;
    int password_check=0;

    for(int i=0;i<g_userCount;i++) {
         email_check = compare_two_char_array(data[i].email, l_email);
    if(email_check==1) {
        l_id = data[i].id;
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
        login_check=l_id;
    }else{
        login_check=-1;
    }
}
void my_privilege(int user_id){
    int user_op=0;
    printf("Well come sir %s\n",data[user_id].name);
    printf("Your id is %d\n",data[user_id].id);
    printf("You have point %d\n",data[user_id].point);
    printf("What do you want to do\n");
    printf("Press 0 to logout\nPress 1 to menu\nPress 2 to user info change\nPress 3 to transition\nEnter:");
    scanf("%d",&user_op);
    if(user_op==0){
        record_data();
        exit(1);
    }else if(user_op==1){
        menu();
    }else if(user_op==2){
        user_info_change(user_id);
    }else if(user_op==3){
        transition(user_id);

    }else{
        printf("Wrong operation\n");
        my_privilege(user_id);
    }

}
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
    }//check second part
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

        fprintf(fptr, "%d,%s,%s,%s,%d,%d,%s\n",data[i].id, data[i].name, data[i].email, data[i].password, data[i].phone,
                data[i].point,data[i].transfer);
    }

    fclose(fptr);
    printf("success\n");
}
void retrieve_data(){
    FILE *fptr;
    fptr=fopen("database.txt","r");
    if(fptr==NULL){
        perror("\n");
        return;

    }
    int read=0;
    int record=0;
     do
     {
        read= fscanf(fptr, "%d,%29[^,],%29[^,],%29[^,],%d,%d,%[^\n]\n", &data[record].id, data[record].name,
                      data[record].email, data[record].password,
                      &data[record].phone, &data[record].point,data[record].transfer);
        if(read==7){record++;
        }
        if(read !=7 && !feof(fptr)){
            printf("reading file format incorrect\n");
            return;
        }
        if(ferror(fptr)){
            printf("reading file error\n");
            return;
        }

    }while(!feof(fptr));
    fclose(fptr);
    printf(" record read=%d\n",record);
    g_userCount=record;


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
        scanf(" %[^\n]",&data[user_id].name);
        printf("This is your new name %s\n",data[user_id].name);
        my_privilege(user_id);
    }else if(info_change==2){
        printf("This is your email %s\n",data[user_id].email);
        email_validation=-1;
        while(email_validation==-1) {
            char change_email[30];
            printf("Enter your new email:");
            scanf(" %[^\n]", &change_email);
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
            scanf(" %[^\n]",&data[user_id].password);
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
void transition(int user_id){
    char receiver_email[30];
    printf("This is your own point %d\n",data[user_id].point);
    printf("Please enter receiver email :");
    scanf(" %[^\n]",&receiver_email);
    for(int i=0;i<g_userCount;i++) {
        int receive_mail_check = compare_two_char_array(data[i].email,receiver_email);
        if(receive_mail_check==1){
            if(data[i].id==data[user_id].id) {
                printf("It is not possible to send point to your own account\n");
                my_privilege(user_id);
            }else{
                int t_point=0;
                printf("Receiver id is %d\n",data[i].id);
                printf("Enter point to transfer:");
                scanf("%d",&t_point);
                if(t_point>data[user_id].point ||t_point<=0){
                    printf("point must be less than point you have and greater than 0\n");
                    transition(user_id);
                }else{
                    data[i].point+=t_point;
                    data[user_id].point-=t_point;
                    printf("%s you have %d point \n",data[user_id].name,data[user_id].point);
                    printf("%s you have %d point \n",data[i].name,data[i].point);
                    transition_record(data[user_id].id,data[i].id,'t',t_point);
                    transition_record(data[user_id].id,data[i].id,'r',t_point);
                    my_privilege(user_id);
                }
            }
        }

    }

}

void printing_all_data_from_file(){
    for(int user=0;user<g_userCount;user++){
        printf("%d_%s_%s_%s_%d_%d_%s",data[user].id,data[user].name,data[user].email,data[user].password,
        data[user].phone,data[user].point,data[user].transfer);

        printf("\n");
    }

}
void transition_record(int sender_id,int receiver_id,char who,int amount){
    integer_to_charArrayFUn(amount);
    char temp[15];
    for(int i=0;i<15;i++){
        temp[i]='\0';
    }
    copy_two_char_array(temp,int_to_charArray);
    int size_of_temp= size_of_char(temp);

    int size_of_s_name= size_of_char(data[sender_id].name);
    int size_of_r_name= size_of_char(data[receiver_id].name);
    if(who=='t'){
        char toInsert1[5] ={'F','r','o','m',' '};
        char toInsert2[4] ={' ','t','o',' '};
        int indexPoint=size_of_char(data[sender_id].transfer);
         data[sender_id].transfer[indexPoint]='/';
         indexPoint++;
        for(int x=0; x<5; x++) {
            data[sender_id].transfer[indexPoint] = toInsert1[x];
            indexPoint++;
        }
        int nameIndex=0;
        int endPoint = indexPoint+size_of_s_name;
        for(int a=indexPoint; a<endPoint; a++){
            data[sender_id].transfer[a]=data[sender_id].name[nameIndex];
            nameIndex++;
            indexPoint++;
        }
        nameIndex=0;
        endPoint = indexPoint+4;
        for(int b=indexPoint; b<endPoint; b++){
            data[sender_id].transfer[b]=toInsert2[nameIndex];
            nameIndex++;
            indexPoint++;
        }
        nameIndex=0;
        endPoint = indexPoint+size_of_r_name;
        for(int c=indexPoint; c<endPoint; c++){
            data[sender_id].transfer[c]=data[receiver_id].name[nameIndex];
            nameIndex++;
            indexPoint++;
        }
        data[sender_id].transfer[indexPoint]=' ';
        indexPoint++;
        nameIndex=0;
        endPoint=indexPoint+size_of_temp;
        for(int f=indexPoint;f<endPoint;f++){
            data[sender_id].transfer[f]=temp[nameIndex];
            nameIndex++;
            indexPoint++;
        }


    }else{
        char receiveFrom[13] = {' ','R','e','c','e','i','v','e','F','r','o','m',' '};
        int indexPoint= size_of_char(data[receiver_id].transfer);
        data[receiver_id].transfer[indexPoint]='/';
        indexPoint++;

        int reIndex=0;
        int endpoint=indexPoint+size_of_r_name;
        for(int i=indexPoint;i<endpoint;i++){
            data[receiver_id].transfer[i]=data[receiver_id].name[reIndex];
            reIndex++;
            indexPoint++;
        }

        reIndex=0;
       endpoint=indexPoint+13;
        for(int d=indexPoint;d<endpoint;d++){
            data[receiver_id].transfer[d]=receiveFrom[reIndex];
            reIndex++;
            indexPoint++;
        }

        reIndex=0;
        endpoint=indexPoint+size_of_s_name;
        for(int e=indexPoint;e<endpoint;e++){
            data[receiver_id].transfer[e]=data[sender_id].name[reIndex];
            reIndex++;
            indexPoint++;
        }
        data[receiver_id].transfer[indexPoint]=' ';
        indexPoint++;
        reIndex=0;
        endpoint=indexPoint+size_of_temp;
        for(int k=indexPoint;k<endpoint;k++){
            data[receiver_id].transfer[k]=temp[reIndex];
            reIndex++;
            indexPoint++;
        }

    }

}
void integer_to_charArrayFUn( int integer){

    for(int i=0;i<15;i++){
        int_to_charArray[i]='\0';
    }

    int index=0;
    FILE *fptr=fopen("M.txt","w");
    if(fptr==NULL){
        printf("[-]Error at integer_to_charArrayFun\n");
    }else{
        fprintf(fptr,"%d",integer);
    }
    fclose(fptr);

    FILE *fptr2=fopen("M.txt","r");
    char c=fgetc(fptr2);

    while(!feof(fptr2)){
        int_to_charArray[index]=c;
        c=fgetc(fptr2);
        index++;
    }
    fclose(fptr2);
}