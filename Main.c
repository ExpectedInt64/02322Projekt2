#include <stdbool.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 5
#define R_BITS 3


void printNumberBits(int R, int bits);
void ADD(); //not implemented - STEP 1
void AND(); //not implemented
void BR(bool n, bool z, bool p); //Done - STEP 1
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
        if(strcmp(input1, "AND") == 0){
            //AND();
        }
        if(input1[0] == 'B' && input1[1] == 'R'){
            bool n = false;
            bool z = false;
            bool p = false;
            for (int i = 0; i < MAX_SIZE; i++) {
                if (input1[i]){
                    if (input1[i] == 'n'){n = true;}
                    if (input1[i] == 'z'){z = true;}
                    if (input1[i] == 'p'){p = true;}
                }
            }
            BR(n, z, p);
        }
        if(strcmp(input1, "JMP") == 0){
            //JMP();
        }
        if(strcmp(input1, "JSR") == 0){
            //JSR();
        }
        if(strcmp(input1, "JSRR") == 0){
            //JSRR();
        }
        if(strcmp(input1, "LD") == 0){
            //LD();
        }
        if(strcmp(input1, "LDI") == 0){
            //LDI();
        }
        if(strcmp(input1, "LDR") == 0){
            //LDR();
        }
        if(strcmp(input1, "LEA") == 0){
            //LEA();
        }
        if(strcmp(input1, "NOT") == 0){
            //NOT();
        }
        if(strcmp(input1, "RET") == 0){
            RET();
        }
        if(strcmp(input1, "RTI") == 0){
            RTI();
        }
        if(strcmp(input1, "ST") == 0){
            //ST();
        }
        if(strcmp(input1, "STI") == 0){
            //STI();
        }
        if(strcmp(input1, "STR") == 0){
            //STR();
        }
        if(strcmp(input1, "TRAP") == 0){
            //TRAP();
        }

    }
}


void printNumberBits(int R, int bits){
    int R_arr[bits] ;
    int i;
    for(int j = 0; j < bits; j++){
        R_arr[j] = 0;
    }
    for(i = 0; R>0; i++){
        R_arr[i]=R%2;
        R = R/2;
    }

    for(i = bits-1; i>=0;i--){
        printf("%d", R_arr[i]);
    }
    return;

}


// for implementation
void ADD(){ // - STEP 1
    printf("0001");


    return;
}

void AND();

void BR(bool n, bool z, bool p){
    printf("0000");
    if(n){printf("1");} else{printf("0");}
    if(z){printf("1");} else{printf("0");}
    if(p){printf("1");} else{printf("0");}

    int input;
    scanf("%d",&input);
    printNumberBits(input, 9);
    printf("\n");
    return;
}

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







