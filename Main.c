#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 10
#define R_BITS 3


void printRegister(int R);
void ADD(); //not implemented - STEP 1
void AND(); //not implemented
void BR(); //not implemented - STEP 1
void JMP(); //not implemented
void JSR(); //not implemented
void JSRR(); //not implemented
void LD(); //not implemented - STEP 1
void LDI(); //not implemented
void LDR(); //not implemented - STEP 1
void LEA(); //not implemented
void NOT(); //not implemented - STEP 1
void RET(); //Done
void RTI(); //Done
void ST(); //not implemented - STEP 1
void STI(); //not implemented
void STR(); //not implemented
void TRAP(); //not implemented

void main() {
    while (1) {
        //printf("Hello world!\n");
        char input1[MAX_SIZE];
        scanf("%s",&input1);
        if(strcmp(input1, "ADD") == 0){
            ADD();
        }
    }
}


void printRegister(int R){
    int R_arr[R_BITS] ;
    int i;
    for(int j = 0; j < R_BITS; j++){
        R_arr[j] = 0;
    }
    for(i = 0; R>0; i++){
        R_arr[i]=R%2;
        R = R/2;
    }

    for(i = R_BITS-1; i>=0;i--){
        printf("%d", R_arr[i]);
    }
}


// for implementation
void ADD(){ // - STEP 1
    printf("0001");
    char arr[R_BITS];
    scanf("%s",&arr);
    printRegister(arr[1]-'0');

    return;
}

void AND();

void BR(); // - STEP 1

void JMP();

void JSR();

void JSRR();

void LD(); // - STEP 1

void LDI();

void LDR(); // - STEP 1

void LEA();

void NOT(); // - STEP 1

void RET() {
    printf("1100000111000000\n");
    return;
}

void RTI(){
    printf("1000000000000000\n");
    return;
}

void ST();// - STEP 1

void STI();

void STR();

void TRAP();







