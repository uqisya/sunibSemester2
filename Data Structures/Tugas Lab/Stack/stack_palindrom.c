#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
stacknya ada hapus

tampilkan dari yg paling terbaru
*/

#define cls system("cls");

struct node{
    char huruf[20];

    struct node *next;
};

struct node *top = NULL;

// function create new node
struct node *createNewNode(char inputData[]){
    // inisiasi new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // inisiasi value of the data
    newNode->huruf = inputData;
    // pointing pointer next ke NULL
    newNode->next = NULL;
    // return new node
    return newNode;
}

void menu();
void enterToContinue();

void insert();
void checkPalindrom(char huruf[]);

void push(char huruf[]);

void main(){

    int exit = 0;
    do{
        cls;
        menu();

        int opsi;
        printf("Enter opsi: ");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 1:
                cls;
                insert();
                break;
            case 2:
                break;
            case 0:
                exit = 1;
                puts("Program keluar...");
                break;
            default:
                puts("Input invalid");

                break;
        }

    }while(!exit);

}

char word[20];
void insert(){

    printf("Enter word: ");
    scanf("%s", word);
    getchar();

    push(word);

}

void checkPalindrom(char huruf[]){

    char str[20];
    int len = strelen(huruf);
    for(int i = 0; i < len; i++){
        str[i] = pop(huruf[i]);
        
        if(str[i] != huruf[len-1]){
            puts("It's not palindrom");
            break;
        }
    }
    
}

void push(char huruf[]){

    int len = strlen(huruf);
    for(int i = 0; i < len; i++){
        struct node *newNode = createNewNode(huruf[i]);

        if(newNode == NULL){
            puts("Stack overflow");
        }
        else if(top == NULL){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }
}

void displayPrev(){

}

void menu(){
    puts("Menu");
    puts("------------------");
    puts("1. Input word");
    puts("2. Previous list");
    puts("0. Exit");
    puts("------------------");
}

void enterToContinue(){
    puts("enter to continue");
    getchar();
}
