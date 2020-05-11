#include <stdbool.h>
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 50
#define R_BITS 3

int hexconvertion(char arr[], int size);
void printNumberBits(int R, int bits);
int imm(char arr[], int bits);

int findLabelPointer(char label[]);
void insertLabel(char label[], int lineNumber);
int calcLabelPointer(char label[], int currentLine);
int labelExist(char label[]);

int pointList[128];
char labels[512];
bool filemode = false;
bool fileEOF = false;
FILE *inputStream;
FILE *outputStream;
char fileN[] = "stdinpfile.txt";

void scanStream(char *arr);
void printStream(char *arr);
void ADD(); //DONE - STEP 1
void AND(); //DONE
void BR(bool n, bool z, bool p, int currentline); //DONE - STEP 1
void JMP(); //DONE
void JSR(); //DONE
void JSRR(); //DONE
void LD(); //DONE - STEP 1
void LDI(); //DONE
void LDR(); //DONE - STEP 1
void LEA(); //DONE
void NOT(); //DONE - STEP 1
void RET(); //DONE
void RTI(); //DONE
void ST(); //DONE - STEP 1
void STI(); //DONE
void STR(); //DONE
void TRAP(); //DONE
void FILL();

void main() {
    printf("write \"0\" for default file mode, \"1\" for choose file mode, \"2\" for stdin mode\n");
    int inp;
    scanf("%d", &inp);
    if (inp != 2) {
        filemode = true;
        if (inp == 1) {
            char fileN[64];
            printf("Enter file path or file name:\n");
            scanf("%s", &fileN);
            inputStream = fopen(fileN, "r");
        } else {
            inputStream = fopen(fileN, "r");
        }
        outputStream = fopen("output.txt", "w");
        if (outputStream == NULL) {
            printf("failed to create output.txt");
            exit(EXIT_FAILURE);
        }
        if (inputStream == NULL){
            printf("failed to open input file");
            exit(EXIT_FAILURE);
        }

    }

    int lineNumber = 0;
    while (1) {
        bool lineSwitch = true;
        //printf("Hello world!\n");
        char input1[MAX_SIZE];
        scanStream(input1);
        if(fileEOF){
            return;
        }
        else if (strcmp(input1, "ADD") == 0) {
            ADD();
        }
        else if (strcmp(input1, "AND") == 0) {
            AND();
        }

        else if (input1[0] == 'B' && input1[1] == 'R') {
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
            BR(n, z, p, lineNumber);
        }
        else if(strcmp(input1, "JMP") == 0){
            JMP();
        }
        else if(strcmp(input1, "JSR") == 0){
            JSR();
        }
        else if(strcmp(input1, "JSRR") == 0){
            JSRR();
        }
        else if(strcmp(input1, "LD") == 0){
            LD();
        }
        else if(strcmp(input1, "LDI") == 0){
            LDI();
        }
        else if(strcmp(input1, "LDR") == 0){
            LDR();
        }
        else if(strcmp(input1, "LEA") == 0){
            LEA();
        }
        else if(strcmp(input1, "NOT") == 0){
            NOT();
        }
        else if(strcmp(input1, "RET") == 0){
            RET();
        }
        else if(strcmp(input1, "RTI") == 0){
            RTI();
        }
        else if(strcmp(input1, "ST") == 0){
            ST();
        }
        else if(strcmp(input1, "STI") == 0){
            STI();
        }
        else if(strcmp(input1, "STR") == 0){
            STR();
        }
        else if(strcmp(input1, "TRAP") == 0){
            TRAP();
        }
        else if(strcmp(input1, ".FILL")==0){
            FILL();
        }

        else { //label
            int c;
            if (c = labelExist(input1) == -1) {
                //printf("%d\n", c); // breaks! TODO: Fix
                insertLabel(input1, lineNumber);
                lineSwitch = false;
            }
        }

        if (lineSwitch) {
            lineNumber++;
        }
    }
}

void scanStream(char *arr) {
    if (filemode) {
        if(fscanf(inputStream,"%s", arr) == EOF){
            fileEOF = true;
            return;
        }
    } else {
        scanf("%s", arr);
    }
}

void printStream(char *arr){
    if (filemode) {
        fprintf(outputStream,"%s", arr);
    } else {
        printf(arr);
    }
}

void printNumberBits(int R, int bits){
    bool negative = false;
    if (R < 0){
        negative = true;
        R =  -R - 1;
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

int hexconvertion(char arr[], int size){ // size is size of chararr
    int i = 1;
    int r = 0;
    while (i < size){
        int current = (int) arr[i] - 48;
        if (current > 9) {
            current -= 7;
        }
        int hexCount = (size - 1 - i);
        // doing pow self
        int j = 1;
        int counter = 0;
        while (counter < hexCount) {
            if (j == 1) {
                j = 16;
            } else {
                j = j * 16;
            }
            counter++;
        }

        r += current * j;
        i += 1;
    }
    return r;
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

void insertLabel(char label[], int lineNumber){
    if (labelExist(label) == -1) {
        int i = -1;
        while (labels[++i] != NULL) {}
        int size = strlen(label);
        if (size > 32) {
            printStream("Too Big label");
            exit(EXIT_FAILURE);
        }
        int j = 0;
        while (j < size) {
            labels[i + j] = label[j];
            j++;
        }
        labels[i + j] = '|';
        i = 0;
        while (pointList[i] != NULL) {
            i++;
        }
        pointList[i] = lineNumber;
    }
}

int labelExist(char label[]) {
    int labelIndex = 0;
    int pointerIndex = 0;
    while (labels[labelIndex] != NULL) {
        char tmp[] = "                                ";
        int j = 0;
        while (labels[labelIndex + j] != '|' && labels[labelIndex + j] != NULL) {
            if (j == 32) {
                printStream("Too Big label");
                exit(EXIT_FAILURE);
            }
            tmp[j] = labels[labelIndex + j];
            j++;
        }

        bool same = true;
        if (j == strlen(label)) {
            for (int i = 0; i < j; i++) {
                if (label[i] != tmp[i]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                return pointList[pointerIndex];
            }
        }
        pointerIndex++;
        labelIndex += j + 1;
    }
    return -1;
}

int findLabelPointer(char label[]){
    int foundNumber = labelExist(label);
    if (foundNumber != -1) {
        return foundNumber;
    }
    //Label not found before. search file for label:
    if (filemode) {
        FILE *tmpInputStream = fopen(fileN, "r");
        int lineNumber = 0;
        while (!feof(tmpInputStream)) {
            char line[50];
            int i = 0;
            int c;
            while (c = fgetc(tmpInputStream) != '\n') {
                line[i++] = c;
            }
            int size = strlen(label);
            char tmpLabel[size];
            i = 0;
            while (i < size) {
                tmpLabel[i] = line[i];
            }
            if (strcmp(label, tmpLabel) == 0) { // found label
                insertLabel(label, lineNumber);
                return lineNumber;
            }
            lineNumber++;
        }
    }
    printf("Error: Label not found");
    exit(EXIT_FAILURE);
}

int calcLabelPointer(char label[], int currentLine){
    int labelLineNumber = findLabelPointer(label);
    return labelLineNumber - currentLine;
}

// for implementation
void ADD() { // - STEP 1
    printStream("0001");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1], 3);
    scanStream(arr);
    printNumberBits(arr[1], 3);
    char adder[MAX_SIZE];
    scanStream(adder);
    if (adder[0] == 'R') {
        printStream("000");
        printNumberBits(adder[1] - '0', 3);
    } else if (adder[0] == '#') {
        printStream("1");
        printNumberBits(imm(adder,5),5);
    }
    printStream("\n");
    return;
}

void AND(){
    printStream("0101");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    char adder[MAX_SIZE];
    scanStream(adder);
    if (adder[0] == 'R') {
        printStream("000");
        printNumberBits(adder[1] - '0', 3);
    } else if (adder[0] == '#') {
        printStream("1");
        printNumberBits(imm(adder,5),5);
    }
    printStream("\n");
    return;
}

void BR(bool n, bool z, bool p, int currentline) {
    printStream("0000");
    if (n) { printStream("1"); } else { printStream("0"); }
    if (z) { printStream("1"); } else { printStream("0"); }
    if (p) { printStream("1"); } else { printStream("0"); }

    char input[5];
    scanStream(input);
    if (input[0] == '#') {
        printNumberBits(imm(input, 9), 9);
        printStream("\n");
    } else {
        printNumberBits(calcLabelPointer(input, currentline), 9);
        printStream("\n");
    }
    return;
}

void JMP() {
    printStream("1100000");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    printStream("000000\n");
}

void JSR(){
    printStream("01001");
    char input[6];
    scanStream(input);
    printNumberBits(imm(input,11), 11);
    printStream("\n");
}

void JSRR(){
    printStream("0100000");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    printStream("000000\n");
}

void LD(){
    printStream("0010");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);

    char input[5];
    scanStream(input);
    printNumberBits(imm(input,9), 9);
    printStream("\n");
    return;
} // - STEP 1

void LDI(){
    printStream("1010");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);

    char input[5];
    scanStream(input);
    printNumberBits(imm(input,9), 9);
    printStream("\n");
    return;
}

void LDR(){
    printStream("0110");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);

    char input[4];
    scanStream(input);
    printNumberBits(imm(input,6), 6);
    printStream("\n");
    return;
} // - STEP 1

void LEA(){
    printStream("1110");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);

    char input[5];
    scanStream(input);
    printNumberBits(imm(input,9), 9);
    printStream("\n");
    return;
}

void NOT(){
    printStream("1001");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    printStream("111111\n");

} // - STEP 1

void RET() {
    printStream("1100000111000000\n");
    return;
}

void RTI() {
    printStream("1000000000000000\n");
    return;
}

void ST(){
    printStream("0011");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);

    char input[6];
    scanStream(input);
    printNumberBits(imm(input,9), 9);
    printStream("\n");
    return;
}// - STEP 1

void STI(){
    printStream("1011");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);

    char input[6];
    scanStream(input);
    printNumberBits(imm(input,9), 9);
    printStream("\n");
    return;
}

void STR(){
    printStream("0111");
    char arr[R_BITS];
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);
    scanStream(arr);
    printNumberBits(arr[1] - '0', 3);

    char input[5];
    scanStream(input);
    printNumberBits(imm(input,6), 6);
    printStream("\n");
    return;
}

void TRAP(){
    printStream("11110000");
    char input[5];
    scanStream(input);  
    printNumberBits(hexconvertion(input, 3), 8);
    printStream("\n");
}

void FILL(){
    char hex[4];
    scanStream(hex);
    printNumberBits(hexconvertion(hex, 4), 16);
    printf("\n");


}







