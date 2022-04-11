//Ada bug dibagian delete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

struct localData{
	int key;
	char name[20];
	char tipe[20];
};
struct localData input;

struct node{
	int data;
	char name[20];
	char tipe[20];

	struct node *left;
	struct node *right;
};

struct node *newNode(){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data= input.key;
	strcpy(temp->name, input.name);
	strcpy(temp->tipe, input.tipe);

	temp->left=temp->right=NULL;
	return temp;
}

struct node *insert(struct node *node){
	
	if(node == NULL){
		return newNode();
	}
	
	if(input.key < node->data){
		node->left = insert(node->left);
		
	}else if(input.key > node->data){
		node->right = insert(node->right);
		
	}
	
	return node;
}

struct node *maxvaluNode(struct node *node){
	
	struct node* current = node;
	while(current && current->right !=NULL){
		current=current->right;
	}
	return current;
	
}

struct node *deletenode(struct node *node, int key){

    if(node == NULL){
    	return node;
	}
	
	if(key < node->data){
		node->left = deletenode(node->left,key);
		
	}else if(key > node->data){
		node->right = deletenode(node->right,key);
	
	//kalau dia sama dengan root/current	
	}else{
		
		//gapunya anak
		if(node->left==NULL && node->right==NULL){
			struct node* temp = node;
			node =NULL;
			free(temp);
//			//atau
//			free(node);
//			node = NULL;
			return node;
		}
		//hanya satu anak : anak kanan saja
		else if(node->left==NULL){
			struct node* temp = node;
			node = node->right;
			printf("Temp : %d\n", temp->data);
			free(temp);
			printf("Node : %d\n", node->data);
			return node;
		
		//hanya satu anak : anak kiri saja	
		}else if(node->right==NULL){
			struct node* temp = node;
			node = node->left;
			free(temp);
			return node;
			
	    }else{
		
	    //dua anak
	    struct node *temp = maxvaluNode(node->left);
	    
	    node->data=temp->data;
	    
	    node->left=deletenode(node->left,temp->data);
	    }
	    
	}
	return node;
	
}
//struct node *search(struct node *node, int key){
//	
//	
//	
//}

void inOrder(struct node *root){
	if(root == NULL){
		return;
		
	}else{
		inOrder(root->left);
		printf("%d - %s - %s\n", root->data, root->name,root->tipe);
		inOrder(root->right);
	}
}

void searchUkuran(struct node *node, int ukuran){

	while(1){
		if(node->data == ukuran){
			printf("%s - %d - %s\n", node->name, node->data, node->tipe);
			break;
		}else if(ukuran < node->data){
			node = node->left;
		}else if(ukuran > node->data){
			node = node->right;
		}
	}
}

int flag = 0;
void searchName(struct node *node, char key[]){

	if(node != NULL){
		if(strcmp(key, node->name) == 0){
			printf("%s - %d - %s\n", node->name, node->data, node->tipe);
			flag = 1;
			return ;
		}
		else{
			searchName(node->left, key);

			if(flag != 1){
				searchName(node->right, key);
			}
			else{
				return;
			}
		}
	}
	else{
		return;
	}
}

void menu(){

    printf("Menu File\n");
    printf("==============================\n");
    printf("1. Input file\n");
    printf("2. Cari file dari nama\n");
    printf("3. Cari file dari ukuran\n");
    printf("4. Delete file\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Pilih : ");
}

void inputData(){
	
    printf("enter size: ");
    scanf("%d", &input.key);
	getchar();

	printf("enter name: ");
    scanf("%s", input.name);
	getchar();

	printf("enter tipe: ");
    scanf("%s", input.tipe);
	getchar();

}

void enterToContinue(){
    puts("enter to continue");
    getchar();
}

int main(){

    struct node *root = NULL;
    int pilih;
    do{
        system("cls");
        menu();
        scanf("%d", &pilih); getchar();
        switch(pilih){
            case 1:
				inputData();
               root = insert(root);
               enterToContinue();
               break;
            case 2:;
			    flag = 0;
				char nama[20];
				printf("enter key (name): ");
				scanf("%s", nama);
				getchar();
				searchName(root, nama);
               enterToContinue();
               break;
            case 3:;
				int ukuran;
				printf("enter key (ukuran): ");
				scanf("%d", &ukuran);
				getchar();
				searchUkuran(root, ukuran);
				enterToContinue();
               break;
            case 4:;
			    int size;
				printf("enter key (ukuran): ");
				scanf("%d", &size);
				getchar();
				struct node *result = deletenode(root,size);
				inOrder(root);
                printf("\n%d - %s - %s\n", result->data, result->name, result->tipe);
				printf("Telah di hapus\n");
				getchar();
                break;
            case 5:
               exit(1);
               break;
        }


    }while(pilih != 5);


    return 0;
}

