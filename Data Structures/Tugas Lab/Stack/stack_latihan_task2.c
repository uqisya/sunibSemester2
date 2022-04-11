#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cls system("cls")
#define output(a) (a == 1) ? "Ya" : "Tidak"

struct dataPesawat{
    char nomorPesawat[20];
    char maskapai[20];
    char jadwal[20];
};

struct node{
    struct dataPesawat pesawat;
    unsigned koperKg;
    
    struct node *next;
};

struct node *createNewNode(char pesawat[], char maskapai[], char jadwal[], unsigned koperKg){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    strcpy(newNode->pesawat.nomorPesawat, pesawat);
    strcpy(newNode->pesawat.maskapai, maskapai);
    strcpy(newNode->pesawat.jadwal, jadwal);

    newNode->koperKg = koperKg;
    newNode->next = NULL;

    return newNode;
};

struct node *top = NULL;

void tambahPesawat();
void pop();

void menu();
void display();
void enterToContinue();

int peek();
int totalBiaya();
int checkKapasitas();

unsigned kapasitas;

void main(){

    cls;

    printf("Kapasitas bagasi: ");
    scanf("%u", &kapasitas);    //5
    getchar();

    int exit = 0;
    do{
        cls;
        printf("Kapasitas tersedia: %d Kg\n\n", kapasitas);
        menu();

        int opsi;
        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        getchar();

        switch(opsi){
            case 1:
                cls;
                tambahPesawat();
                break;
            case 2:
                cls;
                printf("Total biaya tambahan: Rp%d\n", totalBiaya());
                enterToContinue();
                break;
            case 3:
                cls;
                printf("Berat Koper Selanjutnya [Kg]: %d\n\n", peek());
                enterToContinue();
                break;
            case 4:
                cls;
                printf("Apakah bagasi full: %s\n", output(checkKapasitas()));
                enterToContinue();
                break;
            case 5:
                cls;
                pop();
                enterToContinue();
                break;
            case 6:
                cls;
                display();
                enterToContinue();
                break;
            case 0:
                exit = 1;
                puts("Program keluar...");
                break;
            default:
                puts("Input invalid!");
                enterToContinue();
        }
    }while(!exit);


}

void menu(){
    puts("Menu");
    puts("----------------");
    puts("1. Tambah data pesawat");
    puts("2. Total biaya berlebih");
    puts("3. Display koper keluar selanjutnya");
    puts("4. Check kapasitas");
    puts("5. Keluarkan koper");
    puts("6. Display stack");
    puts("0. Exit");
    puts("----------------");
}

void tambahPesawat(){

    char nomorPesawat[20];
    printf("Nomor pesawat: ");
    scanf("%[^\n]", nomorPesawat);
    getchar();

    char maskapai[20];
    printf("Nama maskapai: ");
    scanf("%[^\n]", maskapai);
    getchar();

    char jadwal[20];
    printf("Jadwal berangkat: ");
    scanf("%[^\n]", jadwal);
    getchar();

    int exit = 0;
    do{
        cls;
        printf("Kapasitas tersedia: %d\n\n", kapasitas);
        
        int koperKg;
        puts("Masukkan 0 untuk selesai");
        printf("Masukkan berat koper [kg]: ");
        scanf("%d", &koperKg);  //2
        getchar();

        if(koperKg == 0){
            exit = 1;
        }
        else if(koperKg > kapasitas){
            puts("\nKoper tidak bisa ditambahkan...");
            puts("Kemungkinan koper tidak muat pada bagasi pesawat");
        }
        else{
            kapasitas -= koperKg;

            struct node *newNode = createNewNode(nomorPesawat, maskapai, jadwal, koperKg);

            if(top == NULL){
                top = newNode;
            }
            else{
                newNode->next = top;
                top = newNode;
            }
            
            printf("\nUpdate stack...\n");
            display();
        }

        enterToContinue();

    }while(!exit);

}

int totalBiaya(){

    struct node *curr = top;

    int charge = 0;
    while(curr != NULL){
        if(curr->koperKg > 3){
            charge += curr->koperKg*10000;
        }
        curr = curr->next;
    }

    return charge;
}

int peek(){

    if(top == NULL){
        return 0;
    }
    else{
        return top->koperKg;
    }

}

int checkKapasitas(){

    if(kapasitas == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void pop(){

    display();

    struct node *curr = top;

    if(top == NULL){
        puts("Stack Underflow");
    }
    else{
        top = top->next;
        printf("Delete value: %d\n", curr->koperKg);
        kapasitas+=curr->koperKg;
        free(curr);

        printf("\nUpdate stack...\n");
        display();
    }
}

void display(){
    
    struct node *curr = top;

    printf("Stack elements: ");

    if(curr == NULL){
        puts("Empty");
    }
    else{
        int i = 0;
        while(curr != NULL){
            printf("%d ", curr->koperKg);
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