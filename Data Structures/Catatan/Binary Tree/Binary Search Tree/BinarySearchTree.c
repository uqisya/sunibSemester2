#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int key){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data= key;
	temp->left=temp->right=NULL;
	return temp;
}

struct node *insert(struct node *node, int key){
	
	if(node == NULL){
		return newNode(key);
	}
	
	if(key < node->data){
		node->left = insert(node->left,key);
		
	}else if(key > node->data){
		node->right = insert(node->right,key);
		
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
			free(temp);
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
		printf("%d - ", root->data);
		inOrder(root->right);
	}
}

int main(){
	
	struct node *root = NULL;
	root = insert(root,10);
	root = insert(root,11);
	root = insert(root,9);
	inOrder(root);
	
	return 0;
}