/* 
 * Pointer Sorter - Assignment 0 Systems Programming(CS 214)
 * Created by Arian Moslem(Section #3) and Nicholas Knight(Section #3)
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Quick C hack to get boolean type
typedef enum bool{true, false} bool;

/* Function that compares the string lexicographically
 * returns <0 if string1 < string2, 0 if string1 == string2, and >0 if string1 > string2
 */
int compstr(char *str1, char *str2){
    int i;
    for (i = 0; str1[i] == str2[i]; i++){
        if (str1[i] == '\0'){
            return 0;
        }
    }
    return str1[i] - str2[i];
}

//Main Function
int main(int argc, char *argv[]){
    return 0;
}
