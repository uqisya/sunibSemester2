#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define cls system("cls")

void menu();
void insertHead();
void insertTail();
void insertMid();

void deleteHead();
void deleteTail();
void deleteNode();

void insertData();
void enterToContinue();

struct node{
    int age;
    char name[20];
    struct node *next;
};

struct inputData{
    int age;
    char name[20];
};

struct inputData data;

struct node *head = NULL;
struct node *tail = NULL;

struct node *createNewNode(int age, char *name){
// initialize atau buat node baru
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->age = age;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
};

struct node *display();

// function pertama di-run
void main(){

    data.age = 0;
    strcpy(data.name, "\0");

    int opsi;
    int exit = 0;
    do{
        cls;
        menu();

        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 1:
                cls;
                insertHead();
                break;
            case 2:
                cls;
                insertTail();
                break;
            case 3:
                cls;
                insertMid();
                break;
            case 4:
                cls;
                display();
                enterToContinue();
                break;
            case 5:
                cls;
                deleteHead();
                break;
            case 6:
                cls;
                deleteTail();
                break;
            case 7:
                cls;
                deleteNode();
                break;
            case 0:
                exit = 1;
                puts("Program keluar...");
                break;
            default:
                puts("Input invalid!");
                enterToContinue();
                break;
        }
    }while(!exit);

}

// menu
void menu(){
    puts("Menu");
    puts("----------------");
    puts("1. Insert Head");
    puts("2. Insert Tail");
    puts("3. Insert Mid");
    puts("4. Display");
    puts("5. Delete Head");
    puts("6. Delete Tail");
    puts("7. Delete a Node");
    puts("0. Exit");
    puts("----------------");
}

void insertHead(){

    insertData();

    // initialize *newNode, assign the value of age and name
    struct node *newNode = createNewNode(data.age, data.name);

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

    display();

    printf("\n");

    enterToContinue();

}

void insertTail(){

    insertData();

    // initialize *newNode, assign the value of age and name
    struct node *newNode = createNewNode(data.age, data.name);

    // jika head itu NULL
    if(head == NULL){
        // update heead dan tail jadi di newNode
        head = newNode;
        tail = newNode;
    }
    else{
        // link tail ke newNode
        tail->next = newNode;
        // update tail jadi di newNode
        tail = newNode;
    }

    // // ini kalau pakai cara traverse
    // struct listNode *curr = head;
    // while(curr->next != NULL){
    //     curr = curr->next;
    // }
    // curr->next = newNode;

    printf("\n");

    display();

    printf("\n");

    enterToContinue();

}

void insertMid(){

    display();
    printf("\n");
    
    // key point mau ditaruh di mana value-nya
    char key[20];
    printf("Enter key point: ");
    scanf("%s", key);
    getchar();

    struct node *curr = head;

    printf("\n");

    printf("head: %s\n", head->name);
    printf("tail: %s\n", tail->name);

    int flag = 0;
    if(strcmp(head->name, key) == 0){
        // flag = 2 untuk bagian head nanti
        flag = 2;
    }else{
        while(strcmp(curr->next->name, key) != 0){
            if(curr == NULL){
                flag = 1;
                break;
            }
            //apabila tidak sama, maka curr lompat satu kali ke next
            curr = curr->next;
        }
    }

    if(flag == 1){
        puts("Keypoint tidak ditemukan!");
    }
    else{
        puts("Keypoint ditemukan!\n");
        insertData();

        // initialize *newNode, assign the value of age and name
        struct node *newNode = createNewNode(data.age, data.name);

        printf("\n");

        int opsiInsert;
        do{
            puts("1. Insert sebelum");
            puts("2. Insert sesudah");
            
            printf("Pilih insert: ");
            scanf("%d", &opsiInsert);
            getchar();

            printf("\n");

            if(opsiInsert != 1 && opsiInsert != 2){
                puts("Opsi Invalid!");
            }

        }while(opsiInsert != 1 && opsiInsert != 2);

        //opsi insert sebelumnya
        if(opsiInsert == 1){
            // ketika key ada di head
            if(flag == 2){
                //link newNode ke curr
                newNode->next = curr;
                head = newNode;
            }
            // ketika key bukan di head
            else{
                //link newNode ke curr ke next (alias satu langkah didepan curr)
                newNode->next = curr->next;
                //link curr ke newNode
                curr->next = newNode;
            }
        }
        //opsi insert setelahnya
        else if(opsiInsert == 2){

            if(flag == 2){
                //link newNode ke curr ke next (alias satu langkah didepan curr)
                newNode->next = curr->next;
                //link curr ke newNode
                curr->next = newNode;

                if(newNode->next == NULL){
                    //update tail jadi di newNode
                    tail = newNode;
                }
            }
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
        display();
    }

    printf("\n");

    enterToContinue();

}

void deleteHead(){

    display();

    struct node *curr = head;

    if(head == NULL){
        puts("List sudah kosong!");
    }
    else{
        printf("head: %s\n", head->name);
        printf("tail: %s\n", tail->name);
        head = head->next;
        free(curr);

        printf("\n");

        puts("Node telah terhapus!");

        display();

        printf("\n");
    }

    enterToContinue();

}

void deleteTail(){

    display();

    if(tail == NULL){
        puts("List sudah kosong!");
    }
    else{
        printf("head: %s\n", head->name);
        printf("tail: %s\n", tail->name);

        struct node *curr = head;

        if(curr == tail){
            head = curr->next;
            tail = curr->next;

            free(curr);
        }
        else{
            // ini buat traverse dulu biar dapetin curr nya sebelum tail
            while(curr->next != tail){
                curr = curr->next;
            }

            if(curr->next == tail){
                // head = curr->next;
                // update tail jadi di curr
                tail = curr;

                free(curr->next);

                tail->next = NULL;

            }
        }

        printf("\n");

        puts("Node telah terhapus!");

        display();

        printf("\n");
    }

    enterToContinue();
}

void deleteNode(){

    display();
    printf("\n");
    
    // key point mau ditaruh di mana value-nya
    char key[20];
    printf("Enter key point: ");
    scanf("%s", key);
    getchar();

    // tempatin curr pertama kali di head
    struct node *curr = head;

    if(curr == NULL){
        puts("List sudah kosong");
    }
    else{
        if(strcmp(head->name, key) == 0){
            head = curr->next;
            free(curr);
        }
        else{
            while(strcmp(curr->next->name, key) != 0){
                curr = curr->next;
            }
            printf("\ntail: %s\n\n", tail->name);
            if(strcmp(tail->name, key) == 0){
                tail = curr;
                free(curr->next);
                curr->next = NULL;
            }
            else if(strcmp(curr->next->name, key) == 0){
                // inisiasi del jadi curr ke next (alias curr setelahnya)
                struct node *del = curr->next;

                // link curr ke del setelahnya
                curr->next = del->next;
                // delete node del
                free(del);
            }
        }

        printf("\n");

        puts("Node telah terhapus!");

        display();

        printf("\n");
    }

    enterToContinue();

}

struct node *display(){
    
    struct node *curr = head;
    printf("List Node: ");
    
    while(curr != NULL){
        printf("[%d %s] -> ", curr->age, curr->name);
        //update ptr lompat satu depannya
        curr = curr->next;
    }
    puts("NULL\n");

}

void insertData(){

    printf("Insert age: ");
    scanf("%d", &data.age);
    getchar();

    printf("Insert name: ");
    scanf("%s", data.name);
    getchar();
}

void enterToContinue(){
    puts("enter to continue...");
    getchar();
}