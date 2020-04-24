#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 10
#define R_BITS 3

void main() {
    while (1) {
        printf("Hello world!\n");
        char input1[MAX_SIZE];
        char input2[MAX_SIZE];
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
        input2[0] = "";
        int numberInput = atoi(input2);
        int binary[R_BITS];
        for(int i = 0; i < R_BITS;i++){
            binary[i]=numberInput%2;
            numberInput=numberInput/2;
        }
        for(int i = R_BITS-1; i>0;i--){
            printf("%d",binary[i]);
        }
    }
}