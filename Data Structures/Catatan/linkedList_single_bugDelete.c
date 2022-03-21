#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct listNode{
    int data;
    struct listNode *next;
};

// delete feature masih ada bug

struct listNode *head = NULL;
void insertHead();
struct listNode *insertDepan(int num);

struct listNode *tail = NULL;
void insertTail();
struct listNode *insertBelakang(int num);

void insertMid();
struct listNode *insertTengah(int num, int key, int opsiInsert);

void deleteNode();

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
                insertHead();
                break;
            case 2:
                insertTail();
                break;
            case 3:
                insertMid();
                break;
            case 4:
                deleteNode();
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
    printf("4. Delete Node\n");
    printf("0. Exit\n");
    printf("====================\n");
}

// insert depan semua
void insertHead(){

    system("cls");

    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    insertDepan(num);
    display();

    printf("\n");

    enterToContinue();

}

struct listNode *insertDepan(int num){
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
void insertTail(){
    
    system("cls");

    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    insertBelakang(num);
    display();

    printf("\n");

    enterToContinue();
}

struct listNode *insertBelakang(int num){
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

    // ini kalau pakai cara traverse
    // struct listNode *curr = head;
    // while(curr->next != NULL){
    //     curr = curr->next;
    // }
    // curr->next = newNode;

    printf("\n");
}

// insert tengah
void insertMid(){
    system("cls");

    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    display();

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
            insertTengah(num, key, opsiInsert);
        }
        else if(opsiInsert == 2){
            insertTengah(num, key, opsiInsert);
        }
        else{
            printf("Opsi invalid!\n");
        }
    }while(opsiInsert != 1 && opsiInsert != 2);
    
    display();

    printf("\n");

    enterToContinue();
}

struct listNode *insertTengah(int num, int key, int opsiInsert){
    // initialize atau buat node baru
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));

    newNode->data = num;
    // link newNode ke NULL
    newNode->next = NULL;

    //curr mulai dari head
    struct listNode *curr = head;

    if(head->data == key){
        if(opsiInsert == 1){
            //link newNode ke curr
            newNode->next = curr;
            head = newNode;
        }
        //opsi insert setelahnya
        else{
            //link newNode ke curr ke next (alias satu langkah didepan curr)
            newNode->next = curr->next;
            //link curr ke newNode
            curr->next = newNode;

            if(newNode->next == NULL){
                //update tail jadi di newNode
                tail = newNode;
            }
        }
    }
    else{
        //nilai data dari curr di depannya apakah != key
        int flag = 0;
        while(curr->next->data != key){
            if(curr == NULL){
                printf("haihai\n");
                flag = 1;
                break;
            }
            //apabila tidak sama, maka curr lompat satu kali ke next
            curr = curr->next;
        }

        //opsi insert sebelumnya
        if(flag == 1){
            printf("Keypoint tidak ditemukan!\n");
        }
        else{
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
                    //update tail jadi di newNode
                    tail = newNode;
                }
            }
        }
    }
    
}

void deleteNode(){

    system("cls");

    int num;
    printf("Enter data: ");
    scanf("%d", &num);
    getchar();

    // tempatin curr pertama kali di head
    struct listNode *curr = head;

    // jika num ada di head
    if(head == NULL){
        printf("List sudah kosong!\n");
    }
    else if(head->data == num){
        //update head jadi di head ke next (alias node setelah head sebelumnya)
        head = head->next;
        free(curr);
    }
    // jika num tidak ada di head (alias ada di mid atau tail)
    else{
        int flag = 0;
        while(curr->next->data != num){
            if(curr == NULL){
                printf("haihai\n");
                flag = 1;
                break;
            }
            // curr setelahnya jadi curr
            curr = curr->next;
        }
        if(flag == 1){
            printf("Keypoint tidak ditemukan!\n");
        }
        else{
            //jika num ada di tail
            if(curr->next->data == num){
                //link curr ke NULL
                curr->next = NULL;
                // delete tail
                free(curr->next);
                // update curr jadi tail
                curr = tail;
            }
            else{
                // inisiasi del jadi curr ke next (alias curr setelahnya)
                struct listNode *del = curr->next;
                // link curr ke del setelahnya
                curr->next = del->next;
                // delete node del
                free(del);
            }
        }
    }

    display();

    printf("\n");

    enterToContinue();
}

struct listNode *display(){
    
    struct listNode *curr = head;
    printf("List Node: ");
    
    while(curr != NULL){
        printf("%d -> ", curr->data);
        //update ptr lompat satu depannya
        curr = curr->next;
    }
    printf("NULL\n");

}

void enterToContinue(){
    printf("enter to continue...");
    getchar();
}

// tinggal tambahin delete kalo ga ketemu