#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 10
#define R_BITS 3

void printBinary(int R);

void main() {
    while (1) {
        //printf("Hello world!\n");
        char input1[MAX_SIZE];
        char input2[MAX_SIZE];
        char input3[MAX_SIZE];
        scanf("%s",&input1);
        scanf("%s",&input2);
        scanf("%s",&input3);
        printf("%s %s %s\n", input1,input2,input3);

        if(strcmp(input1, "ADD") == 0){

        }
        int R = input2[1] - '0';
        printBinary(R);
    }
}

void printBinary(int R){
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
