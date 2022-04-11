#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
stacknya ada hapus
tampilkan dari yg paling terbaru
*/

#define cls system("cls");

struct node{
    char huruf;

    struct node *next;
    struct node *prev;
    struct node *head;
};

struct node *top = NULL;
struct node *head = NULL;

// function create new node
struct node *createNewNode(char inputData){
    // inisiasi new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // inisiasi value of the data
    newNode->huruf = inputData;
    // pointing pointer next ke NULL
    newNode->next = NULL;
    newNode->prev = NULL;
    // return new node
    return newNode;
}

void menu();
void enterToContinue();
void displayWord();
void deleteAll();

void insert();
int checkPalindrom(char huruf[]);

void push(char huruf[]);
char pop();

void main(){

    int exit = 0;
    do{
        cls;
        puts("ada bug ketika input kata setelah ke-dua dan seterusnya, masalah sudah fix, cuma kalau ketika check kata yg bukan palindrom, function deleteAll jadi ga bisa jalan, langsung keluar program");
        // printf("top: %c\nhead: %c\n", top->huruf, head->huruf);
        // deleteAll();
        menu();

        int opsi;
        printf("Enter opsi: ");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 1:
                cls;
                insert();
                enterToContinue();
                // deleteAll();
                break;
            case 2:
                cls;
                puts("fitur kedua belum");
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

    displayWord();
    enterToContinue();

    int res = checkPalindrom(word);
    if(res == 1){
        puts("It's palindrom");
    }
    else{
        puts("It's not palindrom");
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
            head = newNode;
            top = newNode;
        }
        else{
            newNode->next = top;
            top->prev = newNode;
            top = newNode;
        }
    }
}

char pop(){

    struct node *curr = top;

    if(curr == NULL){
        return '\0';
    }
    else{
        char value = curr->huruf;
        if(curr->next == NULL){
            top = NULL;
            free(curr);

            return value;
        }
        else{
            top = top->next;
            free(curr);

            return value;
        }
    }

}

int checkPalindrom(char huruf[]){
    
    // int len = strlen(huruf);
    // printf("panjang huruf: %d\n\n", len);
    // char str[len];
    // for(int i = 0; i < len; i++){
    //     str[i] = pop();

    //     printf("str[%d]: %c\n", i, str[i]);

    //     // printf("%c != %c ", str[i], huruf[len-1]);
    //     // if(str[i] != huruf[len-1]){
    //     //     puts("It's not palindrom");
    //     //     break;
    //     // }
    // }

    while(head != NULL){
        
        if(top == head){
            printf("top: %c\n", top->huruf);
            return 1;
        }
        
        char str = pop();

        printf("%c != %c \n", head->huruf, str);

        if(head->huruf != str){
            printf("hai else if\n");
            return 0;
        }

        head = head->prev;
    }

    return 1;

    // int panjang = strlen(str);
    // printf("panjang str baru: %d\n\n", panjang);

    // if(strcmp(str, huruf) == 0){
    //     printf("%s == %s, it's palindrom\n", str, huruf);
    // }
    // else{
    //     printf("%s == %s, it's not palindrom\n", str, huruf);
    // }
    
}

void displayPrev(){

}

void displayWord(){

    struct node *curr = top;

    if(curr == NULL){
        puts("Stack is empty");
    }
    else{
        while(curr != NULL){
            printf("%c", curr->huruf);
            curr = curr->next;
        }
    }

    printf("\n");

}

void deleteAll(){

    while(top != NULL){

        struct node *curr = top;
        top = top->next;
        head = head->next;

        free(curr);
    }

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
