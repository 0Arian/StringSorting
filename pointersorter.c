/* 
 * Pointer Sorter - Assignment 0 Systems Programming(CS 214)
 * Created by Arian Moslem(Section #3) and Nicholas Knight(Section #3)
 */
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    int i;
    char* c = argv[1];
    for(i = 0; i<strlen(argv[1]); i++){
        printf("%c\n", c[i]);
    }
    return 0;
}
