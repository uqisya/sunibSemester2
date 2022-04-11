#include <stdio.h>
#include <stdlib.h>

#define cls system("cls")

struct node{
    int num;

    struct node *left;
    struct node *right;
};

struct node *createNewNode(int num){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->num = num;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertLeft(struct node *root, int num);
void insertRight(struct node *root, int num);
void inOrder(struct node *root);

void main(){

    struct node *root = NULL;
    root = createNewNode(10);
    inOrder(root);
    printf("\n");

    insertLeft(root, 5);
    inOrder(root);
    printf("\n");

    insertRight(root, 11);
    inOrder(root);
    printf("\n");

}

void insertLeft(struct node *root, int num){
    root->left = createNewNode(num);
}

void insertRight(struct node *root, int num){
    root->right = createNewNode(num);
}

// inOrder = 
void inOrder(struct node *root){
    if(root == NULL){
        return ;
    }
    else{
        inOrder(root->left);
        printf("%d - ", root->num);
        inOrder(root->right);
    }
}
// preOrder
// postOrder