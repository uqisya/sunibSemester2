#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define cls system("cls")

void insertHead(int age, char *name);
void insertTail(int age, char *name);
void insertMid(int age, char *name);

void deleteHead();

struct node{
    int age;
    char name[20];
    struct node *next;
    struct node *prev;
};

// struct inputData{
//     int age;
//     char name[20];
// };

// struct inputData data;

struct node *head = NULL;
struct node *tail = NULL;

struct node *createNewNode(int age, char *name){
// initialize atau buat node baru
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->age = age;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
};

struct node *display();

void main(){

    insertHead(18, "Budi");
    insertHead(20, "Abiu");
    display();

    insertTail(19, "Abdu");
    insertTail(21, "Jehan");
    display();

    insertMid(17, "Fira");
    insertMid(22, "Hana");
    insertMid(21, "Haris");
    display();

    deleteHead();
    display();

}

void insertHead(int age, char *name){

    // insertData();

    struct node *newNode = createNewNode(age, name);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

}

void insertTail(int age, char *name){

    // insertData();

    struct node *newNode = createNewNode(age, name);

    if(head == NULL){
        head == newNode;
        tail == newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

}

void insertMid(int age, char *name){

    // insertData();

    struct node *newNode = createNewNode(age, name);

    // ketika head == null
    if(head == NULL){
        head == newNode;
        tail == newNode;
    }
    // ketika age < head
    else if(age < head->age){
        insertHead(age, name);
    }
    // ketika age > tail
    else if(age > tail->age){
        insertTail(age, name);
    }
    else{
        struct node *curr = head;

        while(curr->next != NULL && curr->next->age <= age){
            curr = curr->next;
        }

        if(curr->next != NULL){
            newNode->next = curr->next;
            curr->next->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
    }

}

void deleteHead(){

    // display();

    struct node *curr = head;

    if(head == NULL){
        puts("List sudah kosong!");
    }
    else{
        head = head->next;
        free(curr);

        printf("\n");

        puts("Node telah terhapus!");

        // display();

        printf("\n");
    }

    // enterToContinue();

}

// void insertData(){

//     printf("Insert age: ");
//     scanf("%d", &data.age);
//     getchar();

//     printf("Insert name: ");
//     scanf("%s", data.name);
//     getchar();
// }

struct node *display(){
    
    struct node *curr = head;
    printf("List Node: ");

    printf("NULL <-> ");
    
    while(curr != NULL){
        printf("[%d %s] <-> ", curr->age, curr->name);
        //update ptr lompat satu depannya
        curr = curr->next;
    }
    puts("NULL\n");

}