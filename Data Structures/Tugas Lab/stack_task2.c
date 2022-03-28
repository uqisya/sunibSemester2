#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define cls system("cls")

void menu();
void pushHead();
// void popTail();

void enterToContinue();

struct stack{
    int koperKg;
    char maskapai[20];
    char pesawat[20];
    char jadwal[20];
    struct stack *next;
    struct stack *prev;
};

struct inputData{
    int koperKg;
    char maskapai[20];
    char pesawat[20];
    char jadwal[20];
};

struct inputData data;

struct stack *head = NULL;
struct stack *tail = NULL;

struct stack *createNewNode(int koperKg, char *maskapai, char *pesawat, char *jadwal){
// initialize atau buat node baru
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));

    newNode->koperKg = koperKg;
    strcpy(newNode->maskapai, maskapai);
    strcpy(newNode->pesawat, pesawat);
    strcpy(newNode->jadwal, jadwal);
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
};

struct stack *display();

void main(){

    while(1){
        pushHead();
        cls;
    };

}

void menu(){
    puts("Menu");
    puts("--------------");
    puts("1. Charge");
    puts("2. Next koper keluar");
    puts("3. Check kapasitas");
    puts("4. Keluarkan koper");
}

void pushHead(){

    printf("Berat koper [Kg]: ");
    scanf("%d", &data.koperKg);
    getchar();

    printf("Nama maskapai: ");
    scanf("%s", data.maskapai);
    getchar();

    printf("Nama Pesawat: ");
    scanf("%s", data.pesawat);
    getchar();

    printf("Jadwal: ");
    scanf("%s", data.jadwal);
    getchar();


    struct stack *newNode = createNewNode(data.koperKg, data.maskapai, data.pesawat, data.jadwal);

    if(tail == NULL){
        tail = head = newNode;
        // tail->next = NULL;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        // newNode->next = tail;
        // tail->prev = newNode;
        tail = newNode;
    }

    printf("\n");
    display();
    printf("\n");

    enterToContinue();
}

// void popTail(){

//     display();

//     if(tail == NULL){
//         puts("List sudah kosong!");
//     }
//     else{

//         struct stack *curr = tail;

//         if(curr == tail){
//             head = tail = curr->next;
//             free(curr);
//         }
//         else{
//             // ini buat traverse dulu biar dapetin curr nya sebelum tail
//             while(curr->next != tail){
//                 curr = curr->next;
//             }
//             // update tail jadi di curr
//             tail = curr;
//             free(curr->next);
//             tail->next = NULL;
//         }

//         printf("\n");
//         puts("Node telah terhapus!");

//         display();
//         printf("\n");
//     }

//     enterToContinue();
// }

// if(data.koperKg > 3){
//     puts("Berat koper lebih dari 3kg dikenakan charge Rp10.000/kg");
// }
// else{

// }

struct stack *display(){

    struct stack *curr = tail;
    if(tail == NULL){
        puts("Stack kosong!");
    }
    else{
        int j = 0;
        while(curr != NULL){
            printf("\nData %d\n", j+1);
            printf("Berat koper: %d\n", curr->koperKg);
            printf("Nama maskapai: %s\n", curr->maskapai);
            printf("Nama pesawat: %s\n", curr->pesawat);
            printf("Jadwal: %s\n", curr->jadwal);

            curr = curr->prev;
            j++;
        }
    }
}

void enterToContinue(){
    puts("enter to continue...");
    getchar();
}