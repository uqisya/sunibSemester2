#include <stdio.h>
//stdlib untuk support system("cls")
//ganti system("cls") ke system("clear") apabila menggunakan linux
#include <stdlib.h>

//2501976453

struct database{
    int date;
    float suhuC;
    float suhuK;
};

// size array 31 karena 1 bulan 31 hari
struct database data[31];

void menu();
void inputData();
void displayData();
void displayRataRata();
void inputRand();
void enterToContinue();

//1 bulan = 31 hari
int n = 31;

void main(){

    int exit = 0;
    // while akan terus berjalan, while akan berhenti ketika bertemu angka 0 karena exit akan menjadi 1, sehingga !exit = 0
    while(!exit){
        system("cls");
        // panggil menu
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
                inputData();
                break;
            case 2:
                displayData();
                break;
            case 3:
                displayRataRata();
                break;
            case 4:
                inputRand();
                break;
            default:
                printf("Input invalid!\n");
                break;
        }
    }
}

void menu(){
    printf("Menu:\n");
    printf("============\n");
    printf("1. Input Data\n");
    printf("2. Display Data by date\n");
    printf("3. Display Report (Average of temperature)\n");
    printf("4. Input Random Data Automatic for 1 month\n");
    printf("0. Exit\n");
    printf("============\n");
}

void inputData(){

    system("cls");

    int inputTanggal;
    do{
        printf("Tanggal: ");
        scanf("%d", &inputTanggal);
        getchar();

        //input harus dari range 1 - 31, jika tidak maka pesan invalid print
        if(!(inputTanggal >= 1 && inputTanggal <= 31)){
            printf("Pesan: Tanggal invalid, silahkan input kembali\n\n");
        }
    //while akan berhenti apabila input tanggal tidak pada range 1 - 31
    }while(!(inputTanggal >= 1 && inputTanggal <= 31));

    data[inputTanggal-1].date = inputTanggal;

    printf("Suhu dalam Celcius: ");
    scanf("%f", &data[inputTanggal-1].suhuC);
    getchar();

    data[inputTanggal-1].suhuK = data[inputTanggal-1].suhuC + 273.15f;
    printf("Suhu %.2f Celcius dalam Kelvin: %.2f\n\n", data[inputTanggal-1].suhuC, data[inputTanggal-1].suhuK);

    enterToContinue();
}

void displayData(){
    
    system("cls");

    int inputTanggal;
    do{
        printf("Tanggal: ");
        scanf("%d", &inputTanggal);
        getchar();

        //input harus dari range 1 - 31, jika tidak maka pesan invalid print
        if(!(inputTanggal >= 1 && inputTanggal <= 31)){
            printf("Pesan: Tanggal invalid, silahkan input kembali\n\n");
        }
    //while akan berhenti apabila input tanggal tidak pada range 1 - 31
    }while(!(inputTanggal >= 1 && inputTanggal <= 31));

    if(data[inputTanggal-1].date == 0){
        printf("Data tidak ditemukan...\n");
    }
    else{
        printf("\n| %-10s| %-10s| %-10s|\n", "Tanggal", "Celcius", "Kelvin");
        printf("-------------------------------------\n");
        printf("| %-10d| %-10.2f| %-10.2f|\n", data[inputTanggal-1].date, data[inputTanggal-1].suhuC, data[inputTanggal-1].suhuK);
    }

    enterToContinue();
}

void displayRataRata(){

    system("cls");

    printf("\n| %-10s| %-10s| %-10s|\n", "Tanggal", "Celcius", "Kelvin");
    printf("-------------------------------------\n");

    float rataRata[2] = {0.f ,0.f};
    for(int i = 0; i < n; i++){
        printf("| %-10d| %-10.2f| %-10.2f|\n", i+1, data[i].suhuC, data[i].suhuK);
        rataRata[0] += data[i].suhuC;
        rataRata[1] += data[i].suhuK;
    };
    printf("-------------------------------------\n\n");
    printf("Rata-rata suhu dalam celcius dan kelvin: %.2f dan %.2f\n", rataRata[0]/n, rataRata[1]/n);
    
    enterToContinue();
}

void inputRand(){
    
    for(int i = 0; i < n; i++){
        //random number di-mod 100 artinya tidak ada angka random yg lebih dari 100
        data[i].date = i+1;
        data[i].suhuC = rand() % 100;
        data[i].suhuK = data[i].suhuC + 273.15f;
    }

    printf("Data 1 bulan berhasil ditambahkan!\n");
    printf("Anda sekarang bisa melihatnya pada fitur 3.\n\n");

    enterToContinue();
}

void enterToContinue(){
    printf("enter to continue...");
    getchar();
}