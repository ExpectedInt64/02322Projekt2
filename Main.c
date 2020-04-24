#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 10
#define R_BITS 3

char * getBinary(int R);

void main() {
    while (1) {
        //printf("Hello world!\n");
        char input1[MAX_SIZE];
        char input2[R_BITS];
        char input3[MAX_SIZE];
        char output1[MAX_SIZE];
        char output2[MAX_SIZE];
        char output3[MAX_SIZE];
        char output4[MAX_SIZE*3];
        scanf("%s",&input1);
        scanf("%s",&input2);
        scanf("%s",&input3);
        printf("%s %s %s\n", input1,input2,input3);

        if(strcmp(input1, "ADD") == 0){
            strcat(output1,"0001");
        }
        //printf("%s",output1);
        int R = input2[1] - '0';
        strcat(output2,getBinary(R));
        printf("%s",output2);
    }
}

char * getBinary(int R){
    char R_arr[R_BITS];
    int i;
    for(i = 0; R>0; i++){
        R_arr[i] = R%2;
        R = R/2;
    }
    printf("%s", R_arr);
    return R_arr;
}