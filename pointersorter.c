/* 
 * Pointer Sorter - Assignment 0 Systems Programming(CS 214)
 * Created by Arian Moslem(Section #3) and Nicholas Knight(Section #3)
 */
#include <stdio.h>
#include <string.h>

typedef enum bool{true, false} bool;

//Main Function
int main(int argc, char *argv[]){
    int i; //Will be used to keep track of the characters in our for loop
    char* c = argv[1]; //Derefencing the given string
    for(i = 0; i<strlen(argv[1]); i++){
        printf("%c\n", c[i]); //Printing out all characters that are inputted, while always pushing to a new line
    }

    return 0;
}
