//
// Created by Lenovo on 2/13/2024.
//

#ifndef PROGRAMMING_TRANSITIONUTIL_H
#define PROGRAMMING_TRANSITIONUTIL_H
#include"myprogram.h"
#include"validationUtil.h"
#include"stdio.h"
#include"time.h"


void transaction(int sender_id , int receiver_id,double amount){

    data[sender_id].amount = data[sender_id].amount-amount;
    data[receiver_id].amount = data[receiver_id].amount+amount;
    printf("Transaction Complete From %s to %s : amount=%lf\n",data[sender_id].name,data[receiver_id].name,amount);
    transition_record(sender_id,receiver_id,amount);
    printing_all_data();
    my_privilege(sender_id);

}
void transition_checking(int user_id){
    double amount=0;
    int receiver_phone=0;//
    int phone_id=0;
    int option=0;
    int count_wrong=0;
    printf("Enter  to transfer amount:");
    scanf("%lf",&amount);

    while(data[user_id].amount>amount+100){

        printf("Enter receiver phone number to send money:");
        scanf("%d",&receiver_phone);
        phone_id =to_check_phone(receiver_phone);
        if(phone_id!=-1){
            if(data[phone_id].ban==1 || data[phone_id].suspend==1){
                printf("This account is ban or suspend by admin\n");
                printf("This account is not allow for transition\n");
                my_privilege(user_id);
            }else {
                transaction(user_id, phone_id, amount);
            }

        } else{
            printf("This phone number is not available in our system!\n");
            count_wrong++;
            if(count_wrong>2){
                fprintf(stderr,"Wrong Phone Number!");
                my_privilege(user_id);
            }
        }
    }

    printf("Insufficient Amount: %lf\n",data[user_id].amount);
    printf("Press 1 to continue transaction:\nPress 2 To get Privilege:\n");
    scanf("%d",&option);
    if(option==1){
        transition_checking(user_id);
    } else if(option==2){
        my_privilege(user_id);
    } else{
        fprintf(stderr,"Invalid Option\n");
        menu();
    }

}
void transition_record(int sender_id,int receiver_id,double amount){

   int sender_index=data[sender_id].trans_counter;
   int receiver_index=data[receiver_id].trans_counter;
   char *from="From_";
   char *sender=data[sender_id].name;
   char *to="_to_";
   char *receiver=data[receiver_id].name;
   char *receive="ReceiveFrom_";
   get_t();
   char *for_time=time_array;

   sprintf((char*)data[sender_id].trans_record[sender_index].trans,"%s%s%s%s%c%lf%c%s",from,sender,to,receiver,
           '_',amount,'_',for_time);
   sprintf((char*)data[receiver_id].trans_record[receiver_index].trans,"%s%s%c%lf%c%s",receive,sender,'_',amount,
           '_',for_time);

   data[sender_id].trans_counter++;
   data[receiver_id].trans_counter++;
}
void get_t(){
    time_t tm;
    time (&tm);

    printf("Current Date/Time = %s", ctime(&tm));
    FILE *fptr=fopen("mytime.txt","w");
    fprintf(fptr,"%s",ctime(&tm));
    fclose(fptr);

    for(int i=0;i<25;i++) {
        time_array[i]='\0';
    }

    int index=0;
    FILE* fptr2=fopen("mytime.txt","r");
    char c=fgetc(fptr2);
    while(!feof(fptr2)){
            time_array[index]=c;
            c=fgetc(fptr2);
            index++;
        }
    fclose(fptr2);

    for(int z=0;z<25;z++){
        if(time_array[z]==' ' || time_array[z]=='\n'){
            time_array[z]='_';
        }
    }

}


#endif //PROGRAMMING_TRANSITIONUTIL_H
