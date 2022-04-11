#include <stdio.h>
#include <stdlib.h>

#define cls system("cls")

// struct
struct node{
    // data
    int data;
    // pointer next
    struct node *next;
};

// pointing pointer top = NULL
struct node *top = NULL;

// function create new node
struct node *createNewNode(int inputData){
    // inisiasi new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // inisiasi value of the data
    newNode->data = inputData;
    // pointing pointer next ke NULL
    newNode->next = NULL;
    // return new node
    return newNode;
}

void menu();
void enterToContinue();

void push();
int pop();

void display();

int peek();
int isEmpty();
int size();

void main(){

    int exit = 0;
    do{
        cls;
        menu();

        int opsi;
        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 1:
                cls;
                push();
                enterToContinue();
                break;
            case 2:
                cls;
                int num = pop();
                if(num == -1){
                    puts("Stack Undeflow");
                }
                else{
                    printf("Deleted %d\n", num);
                }
                enterToContinue();
                break;
            case 3:
                cls;
                display();
                enterToContinue();
                break;
            case 4:
                cls;
                int result = peek();
                if(result == -1){
                    puts("Stack is empty");
                }
                else{
                    printf("The top is: %d\n", result);
                }
                enterToContinue();
                break;
            case 5:
                cls;
                int res = isEmpty();
                if(res == 1){
                    puts("Stack is empty");
                }
                else{
                    puts("Stack isn't empty");
                }
                enterToContinue();
                break;
            case 6:
                cls;
                printf("Size of the stack is: %d\n", size());
                enterToContinue();
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

    }while(exit != 1);

}

void menu(){
    puts("Menu");
    puts("-------------");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Display");
    puts("4. Peek");
    puts("5. Check if the stack is empty");
    puts("6. Size of the stack");
    puts("0. Exit");
    puts("-------------");
}

void enterToContinue(){
    puts("enter to continue...");
    getchar();
}

void push(){

    int inputData;
    printf("Enter data: ");
    scanf("%d", &inputData);
    getchar();

    struct node *newNode = createNewNode(inputData);

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

int pop(){

    struct node *curr = top;

    if(curr == NULL){
        return -1;
    }
    else if(curr->next == NULL){
        int value = curr->data;
        top = NULL;
        free(curr);

        return value;
    }
    else{
        int value = curr->data;
        top = top->next;
        free(curr);

        return value;
    }

}

void display(){

    struct node *curr = top;

    if(curr == NULL){
        puts("Stack is empty");
    }
    else{
        while(curr != NULL){
            printf("%d  ", curr->data);
            curr = curr->next;
        }
    }

    printf("\n");

}

int peek(){

    if(top == NULL){
        return -1;
    }
    else{
        return top->data;
    }

}

int isEmpty(){

    if(top == NULL){
        return 1;
    }
    else{
        return 0;
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