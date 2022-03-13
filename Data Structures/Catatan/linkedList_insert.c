#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct listNode{
    int data;
    struct listNode *next;
};

struct listNode *head = NULL;
void insertDepan();
struct listNode *insertDep(int num);

struct listNode *tail = NULL;
void insertBelakang();
struct listNode *insertBel(int num);

void insertTengah();
struct listNode *insertMid(int num, int key, int opsiInsert);

struct listNode *display();

void menu();
void enterToContinue();

void main(){

    int exit = 0;
    while(!exit){

        system("cls");
        menu();

        int opsi;
        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 0:
                exit = 1;
                printf("Program keluar...\n");
                break;
            case 1:
                insertDepan();
                break;
            case 2:
                insertBelakang();
                break;
            case 3:
                insertTengah();
                break;
            default:
                break;
        }
    }

}

void menu(){
    printf("Menu\n");
    printf("1. Insert Depan\n");
    printf("2. Insert Belakang\n");
    printf("3. Insert Tengah\n");
    printf("0. Exit\n");
    printf("====================\n");
}

// insert depan semua
void insertDepan(){

    system("cls");

    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    insertDep(num);
    display();

    printf("\n");

    enterToContinue();

}

struct listNode *insertDep(int num){
    // initialize atau buat node baru
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));

    // nilai num ke data/value newNode
    newNode->data = num;
    // link newNode ke head
    newNode->next = head;
    // update head jadi di newNode
    head = newNode;

    //ini agar tidak perlu traverse, ketika head ke next itu null
    if(head->next == NULL){
        //update tail jadi di newNode
        tail = newNode;
    }

    printf("\n");
}

// insert belakang
void insertBelakang(){
    
    system("cls");

    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    insertBel(num);
    display();

    printf("\n");

    enterToContinue();
}

struct listNode *insertBel(int num){
    // initialize atau buat node baru
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));

    newNode->data = num;
    // link newNode ke NULL
    newNode->next = NULL;

    //jika head itu NULL
    if(head == NULL){
        //update head dan tail jadi di newNode
        head = newNode;
        tail = newNode;
    }
    else{
        //link tail ke newNode
        tail->next = newNode;
        //update tail jadi di newNode
        tail = newNode;
    }

    //ini kalau pakai cara traverse
    // struct listNode *curr = head;
    // while(curr->next != NULL){
    //     curr = curr->next;
    // }
    // curr->next = newNode;

    printf("\n");
}

// insert tengah
void insertTengah(){
    system("cls");

    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    //key point mau ditaruh di mana value dari num
    int key;
    printf("Enter key point: ");
    scanf("%d", &key);
    getchar();

    printf("1. Insert Sebelum\n");
    printf("2. Insert Sesudah\n");

    int opsiInsert;
    do{    
        printf("Pilih insert: ");
        scanf("%d", &opsiInsert);
        getchar();

        if(opsiInsert == 1){
            insertMid(num, key, opsiInsert);
        }
        else if(opsiInsert == 2){
            insertMid(num, key, opsiInsert);
        }
        else{
            printf("Opsi invalid!\n");
        }
    }while(opsiInsert != 1 && opsiInsert != 2);
    
    display();

    printf("\n");

    enterToContinue();
}

struct listNode *insertMid(int num, int key, int opsiInsert){
    // initialize atau buat node baru
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));

    newNode->data = num;
    // link newNode ke NULL
    newNode->next = NULL;

    //curr mulai dari head
    struct listNode *curr = head;
    //nilai data dari curr di depannya apakah != key
    while(curr->next->data != key){
        //apabila tidak sama, maka curr lompat satu kali ke next
        curr = curr->next;
    }

    //opsi insert sebelumnya
    if(opsiInsert == 1){
        //link newNode ke curr ke next (alias satu langkah didepan curr)
        newNode->next = curr->next;
        //link curr ke newNode
        curr->next = newNode;
    }
    //opsi insert setelahnya
    else{
        //curr jadi lompat satu setelahnya
        curr = curr->next;
        //link newNode ke curr ke next (alias satu langkah didepan curr)
        newNode->next = curr->next;
        //link curr ke newNode
        curr->next = newNode;

        if(newNode->next == NULL){
            tail = newNode;
        }
    }
    
}

struct listNode *display(){
    
    struct listNode *ptr;
    ptr = head;
    printf("List Node:");
    
    while(ptr != NULL){
        printf(" %d", ptr->data);
        //update ptr lompat satu depannya
        ptr = ptr->next;
    }

}

void enterToContinue(){
    printf("enter to continue...");
    getchar();
}