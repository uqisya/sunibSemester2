#include <stdio.h>
#include <malloc.h>
struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
} *head = NULL, *tail = NULL;

// create new node
struct Node *createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// push from tail
void pushTail(int value){
    struct Node *newNode = createNode(value);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// pop from head
void popHead(){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        head->next = NULL;
        head->prev = NULL;
        free(head);
        head = tail = NULL;
    }
    else{
        struct Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}

// print all element in linked list
void printAll(){
    struct Node *curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("null\n");
}

int main(){
    pushTail(12);
    pushTail(13);
    pushTail(14);
    popHead();
    printAll();
    return 0;
}