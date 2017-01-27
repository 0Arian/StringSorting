#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* data;
    struct node *next;
} node;

node *head = NULL;

int Input_Validator(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "ERROR: Not enough parameters entered.\n");
        return 1;
    } else if(strlen(argv[1]) == 0){
        fprintf(stderr, "ERROR: There was no input Alphabetize\n");
        return 1;
    }

    return 0;
}
char* GetRidOfShit(char *argv){
    int iterator = 0;
    char* copy = strdup(argv);

    while(iterator < strlen(copy)){
        if(!(copy[iterator]>='a' && copy[iterator]<='z') && !(copy[iterator]>='A' && copy[iterator]<='Z'))
            copy[iterator] = ' ';
        iterator++;

    }
    printf("CLEAN: %s\n", copy);
    return copy;
}

void Sort(char *RD){
    int i = 0, beg = 0, end = 0;
    node *ptr = NULL;
    char *copy = strdup(RD);
    printf("STRING: %s\n", RD);
    if(RD == NULL){
        fprintf(stderr, "No alphabetic characters detected.\n");
        return;
    }

    while(i < strlen(copy)){
        while(copy[i] == ' ' && i < strlen(copy)){
            i++;
        }
        beg = i;
        while(copy[i] != ' ' && i < strlen(copy)){
            i++;
        }
        end = i;
        if(head->data == NULL){
            head->data = (char*) malloc(end-beg + 1);
            strncpy(head->data, copy + beg, end-beg);
            head->data[end-beg + 1] = '\0';
            ptr = head->next;
        }
        printf("HERE: %s\n", head->data);

        printf("Value: %d\n", RD[i]);
        i++;
    }
    return;
}

int main(int argc, char** argv){

    if(Input_Validator(argc, argv) == 1){
        return -1;
    } else {
        head = malloc(sizeof(argv[1]));
        Sort(GetRidOfShit(argv[1]));
    }

    printf("Hello world!\n");
    return 0;
}
