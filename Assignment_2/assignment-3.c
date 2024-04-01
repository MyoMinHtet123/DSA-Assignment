//
// Created by Lenovo on 12/14/2023.
//
#include<stdio.h>
int total(int a,int b,int c,int d,int e,int f);
int winner(int a,int b,int c);
int pass(int a,int b,int c,int d,int e,int f);
int distinction(int a,int b,int c,int d,int e,int f);

int main(){
    int s1 [6]={85,60,70,80,40,50};
    int s2 [6]={40,87,50,30,60,68};
    int s3 [6]={20,80,78,70,67,90};

    int s1total=total(s1[0],s1[1],s1[2],s1[3],s1[4],s1[5]);
    printf("Student1 total marks:%d\n",s1total);
    pass(s1[0],s1[1],s1[2],s1[3],s1[4],s1[5]);
    distinction(s1[0],s1[1],s1[2],s1[3],s1[4],s1[5]);
    printf("\n");

    int s2total=total(s2[0],s2[1],s2[2],s2[3],s2[4],s2[5]);
    printf("Student2 total marks:%d\n",s2total);
    pass(s2[0],s2[1],s2[2],s2[3],s2[4],s2[5]);
    distinction(s2[0],s2[1],s2[2],s2[3],s2[4],s2[5]);
    printf("\n");

    int s3total=total(s3[0],s3[1],s3[2],s3[3],s3[4],s3[5]);
    printf("Student3 total marks:%d\n",s3total);
    pass(s3[0],s3[1],s3[2],s3[3],s3[4],s3[5]);
    distinction(s3[0],s3[1],s3[2],s3[3],s3[4],s3[5]);
    printf("\n");

    winner(s1total,s2total,s3total);




return 0;
}


int total(int a,int b,int c,int d,int e,int f){  //marks addition function

    return a+b+c+d+e+f;
}
int winner(int a,int b,int c){                              //marks comparing function
    if( a> b){
        if(a>c){
            printf("Student1 got the highest marks\n");
        }else if(a<c){
            printf("Student3 got the highest marks\n");
        }
    }
    if(a<b){
        if(b>c){
            printf("Student2 got the highest marks \n");
        }
        else if(b<c){
            printf("Student3 got the highest marks\n");
        }
    }
    return 0;
}
int pass(int a,int b,int c,int d,int e,int f){     //pass or fail function
    if(a<40){
      printf("You are fail at subject 1 with mark %d\n",a);
    }
    if(b<40){
        printf("You are  fail at subject2 with mark %d\n",b);
    }
    if(c<40){
        printf("You are fail at subject3 with mark %d\n",c);
    }
    if(d<40){
        printf("You are fail at subject4 with mark %d\n",d);
    }
    if(e<40){
        printf("You are fail at subject5 with mark %d\n",e);
    }
    if(f<40){
        printf("You are also fail at subject6 with mark %d\n",f);
    }

    return 0;
}
int distinction(int a,int b,int c,int d,int e,int f){//distinction function
    if (a>=80){
        printf("You have distinction at subject1 with mark %d\n",a);
    }
    if (b>=80){
        printf("You have distinction at subject2 with mark %d\n",b);
    }
    if (c>=80){
        printf("You have distinction at subject3 with mark %d\n",c);
    }
    if (d>=80) {
        printf("You have distinction at subject4 with mark %d\n", d);
    }
    if (e>=80){
        printf("You have distinction at subject5 with mark %d\n",e);
    }
    if (f>=80){
        printf("You have distinction at subject6 with mark %d \n",f);
    }


    return 0;
}

