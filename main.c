#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* data;
    struct node *next;
} node;

node *head = NULL;

//Checks for invalid input, such as not enough parameters, and a NULL input.
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
//Gets rid of all the garbage delimiters in the input, and replaces them with a consistent
// ' ' for clarity.
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
//Compares str1 to str2. If a negative number is returned, str1 is before str2
//alphabetically. If a positive number is returned, str2 comes before str1 alphabetically.
//If a 0 is returned, they are equal.
int Compare(char* str1, char* str2){
    int i;
    for(i = 0; str1[i] == str2[i]; i++){
        if (str1[i] == '\0'){
            return 0;
        } else if(str2[i] == '\0'){
            return 1;
        }
    }
    printf("NUM: %d\n", (str1[i] - str2[i]));
    return str1[i] - str2[i];
}

void Sort(char *RD){
    int i = 0, beg = 0, end = 0, cont = 0;
    node *ptr = NULL;
    char *copy = strdup(RD);
    char* word = (char*) malloc(sizeof(char));
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
            head->data = (char*) malloc(sizeof(char) * (end-beg + 1));
            strncpy(head->data, copy + beg, end-beg);
            head->data[end-beg + 1] = '\0';
            ptr = head->next;
            printf("WORD: %s\n", head->data);
        } else{
            word = malloc(sizeof(char) * (end-beg + 1));
            strncpy(word, copy + beg, end-beg);
            word[end-beg] = '\0';
            ptr = head;
            cont = 1;
            printf("WORD: %s\n", word);
            if(ptr->next == NULL){
                if(Compare(word, ptr->data) > 0){
                    ptr->next = malloc(sizeof(node) + strlen(word) + 1);
                    ptr->next->data = (char*) malloc(sizeof(char) * strlen(word) + 1);
                    ptr->next->data = word;
                    ptr->next->next = NULL;
                } else{
                    char* temp = (char*) malloc(sizeof(char) * strlen(head->data) + 1);
                    temp = head->data;
                    head->data = (char*) malloc(sizeof(char) * strlen(word) + 1);
                    head->data = word;
                    head->next = malloc(sizeof(node) + strlen(word) + 1);
                    head->next->data = (char*) malloc(sizeof(char) * strlen(temp) + 1);
                    head->next->data = temp;
                    head->next->next = NULL;
                    printf("NEW-HEAD: %s; OLD-HEAD: %s\n", head->data, head->next->data);
                }
            }else{
            while(ptr != NULL && cont == 1){
                if(Compare(word, ptr->data) <= 0){
                    ptr = malloc(sizeof(node) + strlen(word) + 1);
                    ptr->data = (char*) malloc(sizeof(char) * strlen(word) + 1);
                    ptr->data = word;
                    ptr->next = head;
                    head = ptr;
                    cont = 0;
                }else if(ptr->next == NULL){
                    node *temp = NULL;
                    ptr->next = malloc(sizeof(node) + strlen(word) + 1);
                    ptr->next->data = (char*) malloc(sizeof(char) * strlen(word) + 1);
                    ptr->next->data = word;
                    ptr->next->next = temp;
                    cont = 0;
                }else if(Compare(word, ptr->data) > 0 && (Compare(word, ptr->next->data) <= 0)){
                    node *temp = ptr->next;
                    ptr->next = malloc(sizeof(node) + strlen(word) + 1);
                    ptr->next->data = (char*) malloc(sizeof(char) * strlen(word) + 1);
                    ptr->next->data = word;
                    ptr->next->next = temp;
                    cont = 0;
                }else{
                    ptr = ptr->next;
                }
            }
            }
        }
        i++;
    }
    while(head != NULL){
        printf("%s\n", head->data);
        head = head->next;
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
