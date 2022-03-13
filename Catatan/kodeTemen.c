#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<malloc.h>

#define size 50

struct node{
	int nomor;
	char nama[size];
	char nik[size];
	char gender[size];
	char tgl[size];
	char kl[size];
	char kn[size];
	char kk[size];
	struct node *next;
};

struct node *head = NULL;
struct node *insert_beg(struct node*);
struct node *display(struct node*);

char key[size];

void menu(){
	printf("Menu Antrian Legalisir\n");
	printf("=======================\n");
	printf("1. Insert antrian\n");
	printf("2. Display antrian\n");
	printf("3. Search nomor antrian\n");
	printf("4. Exit\n");
	printf("=======================\n");
	printf("Pilih : ");	
}

struct node *insert_beg(struct node *head){
	//create a new node
	struct node *new_node;
	struct node *temp = head;
	int num;
	char nam[size];
	char Nik[size];
	char gen[size];
	char tang[size];
	char klah[size];
	char knik[size];
	char kkel[size];
	printf("Nomor : ");
	scanf("%d", &num);
	getchar();
	printf("Nama : ");
	scanf("%[^\n]", nam);
	getchar();
	printf("NIK : ");
	scanf("%s", Nik);
	getchar();
	printf("Gender : ");
	scanf("%s", gen);
	getchar();
	printf("Tanggal : ");
	scanf("%s", tang);
	getchar();
	printf("Akata lahir : ");
	scanf("%s", klah);
	getchar();
	printf("Akta Nikah : ");
	scanf("%s", knik);
	getchar();
	printf("Akta Keluarga : ");
	scanf("%s", kkel);
	getchar();
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->nomor=num;
	strcpy(new_node->nama,nam);
	strcpy(new_node->nik,Nik);
	strcpy(new_node->gender,gen);
	strcpy(new_node->tgl,tang);
	strcpy(new_node->kl,klah);
	strcpy(new_node->kn,knik);
	strcpy(new_node->kk,kkel);

	// new_node->next=NULL;
	// if(head == NULL){
	// 	head=new_node;
	// 	return head;
	// }
	// while(temp->next != NULL){
	// 	temp=temp->next;
	// }
	// temp->next=new_node;

    new_node -> next = head;
    head = new_node;

	return head;
}

struct node *display(struct node *head){
	struct node *curr;
	curr=head;
	while(curr != NULL){
		printf("-%d\t|",curr->nomor); //*ptr.data alseo means ptr->data
		printf("-%s\t|",curr->nama);
		printf("-%s\t|",curr->nik);
		printf("-%s\t|",curr->gender);
		printf("-%s\t|",curr->tgl);
		printf("-%s\t|",curr->kl);
		printf("-%s\t|",curr->kn);
		printf("-%s\t|\n",curr->kk);
		curr=curr->next;
		// if(curr==NULL){
		//    getchar(), getchar();
	    // }	
	}
	
	return head;
}

// Search a node
int searchNode(struct node* head) {
  struct node* current = head;

  while (current != NULL) {
    if (strcmp(current->nama,key)==0){
        return 1;
    }
      current = current->next;
  }
  return 0;
}

void bin(){
	struct node *cari;
	cari = head;
    int result;
	
	printf("Masukkan Nama yang ingin dicari : ");
	scanf("%[^\n]", key);
    getchar();
	result = searchNode(head);
	if(result == 1){
		printf("Nomor : %d", cari->nomor);
		printf("Nama : %s", cari->nama);
		printf("NIK : %s", cari->nik);
		printf("Gender : %s", cari->gender);
		printf("Tanggal : %s", cari->tgl);
		printf("Akta Lahir : %s", cari->kl);
		printf("Akta Nikah : %s", cari->kn);
		printf("Akata Keluarga : %s", cari->kk);
	}
	
}

void salah(){
	printf("Input yang anda berikan salah\n");
	printf("Mohon ulangi lagi!");
	getchar(), getchar();
}

int main(){
	
	int num;
	do{
//		system("cls");
		menu();
		scanf("%d", &num);
        getchar();
//		system("cls");
		switch(num){
		   case 1:
		   	  head=insert_beg(head); break;
		      break;
		   case 2:
		   	  head=display(head); break;
		   	  break;
		   case 3:
	          bin();
		   	  break;
		   default:
		      salah();
		      break;
		}
		
	}while(num!=4);
	
	
	
	return 0;
}