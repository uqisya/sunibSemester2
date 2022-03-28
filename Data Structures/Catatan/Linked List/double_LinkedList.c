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
    struct node *prev;
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
    newNode->prev = NULL;

    return newNode;
};

struct node *display();
struct node *infoNode();

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
                insertData();
                insertHead();
                break;
            case 2:
                cls;
                insertData();
                insertTail();
                break;
            case 3:
                cls;
                if(head != NULL && tail != NULL){
                    insertMid();
                }
                else{
                    puts("List Node tidak boleh kosong!");
                    enterToContinue();
                }
                break;
            case 4:
                cls;
                display();
                enterToContinue();
                break;
            case 5:
                cls;
                infoNode();
                break;
            case 6:
                cls;
                deleteHead();
                break;
            case 7:
                cls;
                deleteTail();
                break;
            case 8:
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
    puts("5. Check Info Node");
    puts("6. Delete Head");
    puts("7. Delete Tail");
    puts("8. Delete a Node");
    puts("0. Exit");
    puts("----------------");
}

void insertHead(){

    // initialize *newNode, assign the value of age and name
    struct node *newNode = createNewNode(data.age, data.name);

    if(head == NULL){
        head = tail = newNode;
    }
    else{
        // link newNode ke head
        newNode->next = head;
        //link head prev ke newNode
        head->prev = newNode;
        // update head jadi di newNode
        head = newNode;
    }

    printf("\n");
    display();
    printf("\n");

    enterToContinue();

}

void insertTail(){

    // initialize *newNode, assign the value of age and name
    struct node *newNode = createNewNode(data.age, data.name);

    // jika head itu NULL
    if(head == NULL){
        // update heead dan tail jadi di newNode
        head = tail = newNode;
    }
    else{
        // link tail ke newNode
        tail->next = newNode;
        //link newNode prev ke tail
        newNode->prev = tail;
        // update tail jadi di newNode
        tail = newNode;
    }

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

    int flag = 0;
    if(strcmp(head->name, key) == 0){
        // flag = 2 untuk bagian head nanti
        flag = 2;
    }else{
        if(curr->next == NULL){
            flag = 1;
        }
        else{
            while(strcmp(curr->next->name, key) != 0){
                if(curr->next->next == NULL){
                    flag = 1;
                    break;
                }
                //apabila tidak sama, maka curr lompat satu kali ke next
                curr = curr->next;
            }
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

        if(flag == 2){
            if(opsiInsert == 1){
                // link newNode ke head
                newNode->next = head;
                //link head prev ke newNode
                head->prev = newNode;
                // update head jadi di newNode
                head = newNode;
            }
            else{
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                newNode->prev = head;
            }
        }
        else if(flag == 0){
            if(opsiInsert == 1){
                newNode->next = curr->next;
                curr->next->prev = newNode;
                curr->next = newNode;
                newNode->prev = curr;
            }
            else{
                curr = curr->next;
                newNode->next = curr->next;
                curr->next->prev = newNode;
                curr->next = newNode;
                newNode->prev = curr;
            }
        }

        if(newNode->next == NULL){
            tail = newNode;
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
        head = head->next;
        head->prev = NULL;
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

        struct node *curr = head;

        if(curr == tail){
            head = tail = curr->next;
            free(curr);
        }
        else{
            // ini buat traverse dulu biar dapetin curr nya sebelum tail
            while(curr->next != tail){
                curr = curr->next;
            }
            // update tail jadi di curr
            tail = curr;
            free(curr->next);
            tail->next = NULL;
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

    // tempatin curr pertama kali di head
    struct node *curr = head;

    if(curr == NULL){
        puts("List sudah kosong");
    }
    else{
        // key point mau ditaruh di mana value-nya
        char key[20];
        printf("Enter key point: ");
        scanf("%s", key);
        getchar();

        int flag = 0;
        if(strcmp(head->name, key) == 0){
            flag = 2;
        }
        else{
            if(curr->next == NULL){
                flag = 1;
            }
            else{
                while(strcmp(curr->next->name, key) != 0){
                    if(curr->next->next == NULL){
                        flag = 1;
                        break;
                    }
                    curr = curr->next;
                }
            }
        }

        if(flag == 1){
            puts("Data tidak ada!");
        }
        else{
            if(flag == 2){
                head = curr->next;
                head->prev = NULL;
                free(curr);
            }
            else{
                struct node *del = curr->next;
                curr->next = del->next;
                del->next->prev = curr;

                if(del == tail){
                    tail = curr;
                }

                free(del);
            }
            
            printf("\n");
            puts("Node telah terhapus!");

            display();
            printf("\n");
        }
    }

    enterToContinue();

}

struct node *display(){
    
    struct node *curr = head;
    printf("List Node: ");

    printf("NULL <-> ");
    
    while(curr != NULL){
        if(curr == head && curr == tail){
            printf("[{Head, Tail} %d %s] <-> ", curr->age, curr->name);
        }
        else if(curr == head){
            printf("[{Head} %d %s] <-> ", curr->age, curr->name);
        }
        else if(curr == tail){
            printf("[{Tail} %d %s] <-> ", curr->age, curr->name);
        }
        else{
            printf("[%d %s] <-> ", curr->age, curr->name);
        }
        
        //update ptr lompat satu depannya
        curr = curr->next;
    }
    puts("NULL\n");

}

struct node *infoNode(){

    display();
    
    if(head == NULL){
        puts("List sudah kosong!");
    }
    else{
        char key[20];
        printf("Apa nama node nya: ");
        scanf("%s", key);
        getchar();

        struct node *curr = head;
        
        while(curr != NULL){
            if(strcmp(curr->name, key) == 0){
                printf("Head: ");
                if(curr == head){
                    puts("YES");
                }
                else{
                    puts("-");
                }

                printf("Tail: ");
                if(curr == tail){
                    puts("YES");
                }
                else{
                    puts("-");
                }

                if(curr->prev == NULL){
                    printf("NULL <-> ");
                }
                else{
                    printf("{Prev} [%s] <-> ", curr->prev->name);
                }
                
                printf("[%s] <-> ", curr->name);

                if(curr->next == NULL){
                    printf("NULL <-> ");
                }
                else{
                    printf("{Next} [%s]\n", curr->next->name);
                }
                break;
            }
            //update ptr lompat satu depannya
            curr = curr->next;
        }
    }

    enterToContinue();

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