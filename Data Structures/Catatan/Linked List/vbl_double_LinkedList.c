#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define cls system("cls")

void menu();
void enterToContinue();

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
                break;
            case 2:
                cls;
                break;
            case 3:
                cls;
                break;
            case 4:
                cls;
                break;
            case 5:
                cls;
                break;
            case 6:
                cls;
                break;
            case 7:
                cls;
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
    puts("----------------");
    puts("1. Insert Head");
    puts("2. Insert Tail");
    puts("3. Insert Mid (after key)");
    puts("4. Display");
    puts("5. Delete Head");
    puts("6. Delete Tail");
    puts("7. Delete Mid");
    puts("0. Exit");
    puts("----------------");
}

void enterToContinue(){
    puts("enter to continue...");
    getchar();
}