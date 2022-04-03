#include <stdio.h>
#include <stdlib.h>

#define cls system("cls")
#define output(a) (a == 1) ? "Yes" : "No"

struct node{
    int data;
    unsigned capacity;
    struct node *next;
};

struct node *createNewNode(int data){
// initialize atau buat node baru
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
};

struct node *top = NULL;
struct node check;

void push();
void pop();

void menu();
void enterToContinue();
void display();

int peek();
int size();
int isEmpty();
int isFull();

void main(){
    
    cls;

    unsigned capacity;
    printf("Masukan kapasitas element stack: ");
    scanf("%u", &capacity);
    getchar();
    check.capacity = capacity;

    int opsi;
    int exit = 0;
    do{
        cls;

        printf("size: %u\n\n", check.capacity);

        menu();

        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 1:
                cls;
                push();
                break;
            case 2:
                cls;
                pop();
                break;
            case 3:
                cls;
                int top = peek();
                
                printf("Value of top: ");
                if(top == -1){
                    puts("Empty");
                }
                else{
                    printf("%d\n", top);
                }
                enterToContinue();
                break;
            case 4:
                cls;
                display();
                enterToContinue();
                break;
            case 5:
                cls;
                printf("Curr size: %d\n", size());
                enterToContinue();
                break;
            case 6:
                cls;
                printf("Is it empty: %s\n", output(isEmpty()));
                enterToContinue();
                break;
            case 7:
                cls;
                printf("Is it full: %s\n", output(isFull()));
                enterToContinue();
                break;
            case 0:
                exit = 1;
                puts("Program keluar...");
                break;
            default:
                puts("Input Invalid");
                enterToContinue();
                break;
        }

    }while(!exit);

}

void menu(){
    puts("Menu");
    puts("----------------");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Display top");
    puts("4. Display stack");
    puts("5. Check size of all elements in the stack");
    puts("6. Check if it's empty");
    puts("7. Check if it's full");
    puts("0. Exit");
    puts("----------------");
}

void push(){

    display();

    int number;
    printf("Insert number: ");
    scanf("%d", &number);
    getchar();

    struct node *newNode = createNewNode(number);

    if(isFull()){
        puts("The stack is full");
    }
    else if(top == NULL){
        top = newNode;
        check.capacity--;
        printf("\nUpdate stack...\n");
        display();
    }
    else{
        newNode->next = top;
        top = newNode;
        check.capacity--;
        printf("\nUpdate stack...\n");
        display();
    }

    printf("\n");

    enterToContinue();

}

void pop(){

    display();

    struct node *curr = top;

    if(isEmpty()){
        puts("Stack Underflow");
    }
    else{
        top = top->next;
        printf("Delete value: %d\n", curr->data);
        free(curr);
        check.capacity++;

        printf("\nUpdate stack...\n");
        display();
    }

    printf("\n");
    enterToContinue();

}

int peek(){

    if(top == NULL){
        return -1;
    }
    else{
        return top->data;
    }
}

int size(){

    struct node *curr = top;

    int count = 0;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }

    return count;
}

int isEmpty(){
    
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){

    if(check.capacity == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    
    struct node *curr = top;
    printf("Stack elements: ");

    if(curr == NULL){
        puts("Empty");
    }
    else{
        while(curr != NULL){
            printf("%d ", curr->data);

            curr = curr->next;
        }
        printf("\n");
    }

    printf("\n");
}

void enterToContinue(){
    puts("enter to continue...");
    getchar();
}