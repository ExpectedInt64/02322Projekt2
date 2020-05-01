#include <stdbool.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 5
#define R_BITS 3


void printNumberBits(int R, int bits);
int imm(char arr[], int bits);
bool filemode = false;
FILE *inputStream;
FILE *outputStream;

void scanstream(char * arr[]);
void printstream(char arr[]);
void ADD(); //DONE - STEP 1
void AND(); //not implemented
void BR(bool n, bool z, bool p); //DONE - STEP 1
void JMP(); //not implemented
void JSR(); //not implemented
void JSRR(); //not implemented
void LD(); //not implemented - STEP 1
void LDI(); //not implemented
void LDR(); //not implemented - STEP 1
void LEA(); //not implemented
void NOT(); //not implemented - STEP 1
void RET(); //DONE
void RTI(); //DONE
void ST(); //not implemented - STEP 1
void STI(); //not implemented
void STR(); //not implemented
void TRAP(); //not implemented

void main() {
    printf("write \"0\" for default file mode, \"1\" for choose file mode, \"2\" for stdin mode");
    char inp = getchar();
    if (inp != "2") {
        filemode = true;
        char fileN[50];
        if (inp == 1) {
            printf("Enter file path or file name:");
            scanf("%s", &fileN);
            inputStream = fopen(fileN, "r");
        } else {
            inputStream = fopen("stdinpfile.txt", "r");
        }
        outputStream = fopen("output.txt", "w");
        if (outputStream == NULL) {
            printf("failed to create output.txt file");
            exit(EXIT_FAILURE);
        }

    }

    while (1) {
        //printf("Hello world!\n");
        char input1[MAX_SIZE];
        scanstream(*input1);
        if (strcmp(input1, "ADD") == 0) {
            ADD();
        }
        if (strcmp(input1, "AND") == 0) {
            //AND();
        }

        if (input1[0] == 'B' && input1[1] == 'R') {
            bool n = false;
            bool z = false;
            bool p = false;
            for (int i = 0; i < MAX_SIZE; i++) {
                if (input1[i]) {
                    if (input1[i] == 'n') { n = true; }
                    if (input1[i] == 'z') { z = true; }
                    if (input1[i] == 'p') { p = true; }
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

void scanstream(char * arr[]) {
    if (filemode) {
        fscanf(inputStream, "%s", &arr);
    } else {
        scanf("%s", &arr);
    }
}

void printstream(char arr[]){
    if (filemode) {
        fprintf(outputStream, arr);
    } else {
        printf(arr);
    }
}

void printNumberBits(int R, int bits){
    bool negative = false;
    if (R < 0){
        negative = true;
        R =  -R + 1;
    }
    int R_arr[bits] ;
    int i;
    for (int j = 0; j < bits; j++) {
        R_arr[j] = 0;
    }
    for (i = 0; R > 0; i++) {
        R_arr[i] = R % 2;
        R = R / 2;
    }

    if (filemode) {
        for (i = bits - 1; i >= 0; i--) {
            if (negative) {
                fprintf(outputStream, "%d", 1 - R_arr[i]);
            } else {
                fprintf(outputStream, "%d", R_arr[i]);
            }
        }
    } else {
        for(i = bits-1; i>=0;i--){
            if (negative) {
                printf("%d", 1 - R_arr[i]);
            } else {
                printf("%d", R_arr[i]);
            }
        }
    }
    return;

}

int imm(char arr[], int bits){
    char temp_arr[bits];
    for(int i = 1; i < bits; i++){
        temp_arr[i-1] = arr[i];
    }
    int i;
    sscanf(temp_arr,"%d",&i);
    return i;
}

// for implementation
void ADD() { // - STEP 1
    printstream("0001");
    char arr[R_BITS];
    scanf("%s", &arr);
    printNumberBits(arr[1] - '0', 3);
    scanf("%s", &arr);
    printNumberBits(arr[1] - '0', 3);
    char adder[MAX_SIZE];
    scanf("%s", &adder);
    if (adder[0] == 'R') {
        printstream("000");
        printNumberBits(adder[1] - '0', 3);
    } else if (adder[0] == '#') {
        printstream("1");
        printNumberBits(imm(adder,5),5);
    }
    printstream("\n");
    return;
}

void AND();

void BR(bool n, bool z, bool p) {
    printstream("0000");
    if (n) { printstream("1"); } else { printstream("0"); }
    if (z) { printstream("1"); } else { printstream("0"); }
    if (p) { printstream("1"); } else { printstream("0"); }

    char * input[5];
    scanf("%s", &input);
    printNumberBits(imm(input,9), 9);
    printstream("\n");
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
    printstream("1100000111000000\n");
    return;
}

void RTI() {
    printstream("1000000000000000\n");
    return;
}

void ST();// - STEP 1

void STI();

void STR();

void TRAP();







