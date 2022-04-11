/*
    Tinggal pikirin gimana cara stack di setiap stack array yg ada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cls system("cls")
#define size 100

struct elements{
    int data;

    struct elements *next;
};

struct stack{
    char id[10];
    int kapasitas;

    struct elements newData;

    struct stack *next;
};

struct stack *createNewStack(char id[], int data, int kapasitas){

    struct stack *newStack = (struct stack *)malloc(sizeof(struct stack));

    strcpy(newStack->id, id);
    newStack->newData.data = data;
    newStack->kapasitas = kapasitas;

    newStack->next = NULL;
    newStack->newData.next = NULL;

    return newStack;
};

struct stack *topMain = NULL;
struct stack *topElement[size];
struct stack *newStack[size];

void push();

void menu();
void displayAll();
void enterToContinue();

int list = 0;

void main(){

    int exit = 0;
    do{
        cls;
        menu();

        int opsi;
        printf("Pilih opsi:");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 1:
                cls;
                push();
                enterToContinue();
                break;
            case 2:
                break;
            case 3:
                cls;
                displayAll();
                enterToContinue();
                break;
            case 4:
                break;
            case 0:
                exit = 1;
                puts("Program selesai...");
                break;
            default:
                puts("Input invalid!");
                enterToContinue();
                break;
        }

    }while(!exit);
    
}

void menu(){
    puts("Menu");
    puts("-------------");
    puts("1. Create new stack");
    puts("2. Add data");
    puts("3. Display all stack");
    puts("4. Pop element of the stack");
    puts("0. Exit");
    puts("-------------");
}

void push(){

    displayAll();

    if(list > 100){
        puts("can't create new stack");
    }
    else{
        char id[10];
        printf("Enter id number: ");
        scanf("%s", id);
        getchar();

        int data = 0;

        int kapasitas;
        printf("Max. capacity of the stack: ");
        scanf("%d", &kapasitas);
        getchar();

        newStack[list] = createNewStack(id, data, kapasitas);

        if(topMain == NULL){
            topMain = newStack[list];
        }
        else{
            newStack[list]->next = topMain;
            topMain = newStack[list];
        }

        list++;
    }

}

void addData(){

    char number[10];
    printf("Choose id number: ");
    scanf("%s", number);
    getchar();

    struct stack *curr = topElement[list];

    while(strcmp(curr->id, number) != 0){
        curr = curr->next;
    }

    if(topElement[list] == NULL){

    }
    else{
        
    }

    if(list > 100){
        puts("can't create new stack");
    }
    else{
        char id[10];
        printf("Enter id number: ");
        scanf("%s", id);
        getchar();

        int data = 0;

        int kapasitas;
        printf("Max. capacity of the stack: ");
        scanf("%d", &kapasitas);
        getchar();

        newStack[list] = createNewStack(id, data, kapasitas);

        if(topMain == NULL){
            topMain = newStack[list];
        }
        else{
            newStack[list]->next = topMain;
            topMain = newStack[list];
        }

        list++;
    }
}

void displayAll(){

    struct stack *curr = topMain;

    puts("List all of the stack: ");

    if(curr == NULL){
        puts("Empty");
    }
    else{
        int count = 0;
        while(curr != NULL){
            printf("%d. %s\n", count+1, curr->id);
            count++;
            curr = curr->next;
        }
    }

    printf("\n");

}

void displayElements(){

    struct stack *curr = topElement[list];

    puts("List all of the stack: ");

    if(curr == NULL){
        puts("Empty");
    }
    else{
        int count = 0;
        while(curr != NULL){
            printf("%d. %s\n", count+1, curr->id);
            count++;
            curr = curr->next;
        }
    }

    printf("\n");
}

void enterToContinue(){
    puts("enter to continue...");
    getchar();
}