#include <stdio.h>
#include <stdlib.h>

#define cls system("cls")
#define MAX 10

// struct queue{
//     int data;

//     struct queue *next;
// };

int queue[MAX];

// struct queue *front = NULL;
// struct queue *rear = NULL;

int *front = NULL;
int *rear = NULL;

void push();
int pop();
int peek();

void display();

void main(){

    push(10);
    push(55);
    push(31);
    push(6);
    push(2);

    display();

    printf("Deleted %d\n", pop());
    printf("Deleted %d\n", pop());

    display();

}

void push(){

    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    getchar();

    if(rear == MAX-1){
        puts("\nOverflow, can't add new data");
    }
    else{
        if(front == -1 && rear == -1){
            front = rear = NULL;
        }
        else{
            rear++;
        }
        queue[rear] = number;
    }

}

int pop(){

    int value;
    if(front == -1 || front > rear){
        puts("\nUnderflow");
        return -1;
    }
    else{
        front++;
        val = queue[front];
        return val;
    }
}

void display(){
    
    for(int i = front; i <= rear; rear++){
        printf("%d  ", queue[i]);
    }
}

int peek(){
    return queue[front];
}