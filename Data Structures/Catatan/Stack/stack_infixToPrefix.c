#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define cls system("cls")

char stack[50];
int top = -1;

bool isOperand(char operand);
void push(char operator);
void pop();
int precedence(char operator);

void main(){

    cls;

    // input
    char exp[100] = {'\0'};
    printf("Input infix expression: ");
    scanf("%s", exp);

    // printf("expression: %s\n", exp);

    // reverse
    char rev_exp[100] = {'\0'};

    int i = strlen(exp) - 1;
    int j = 0;
    while(exp[i] != '\0'){

        if(exp[i] == '('){
            rev_exp[j] = ')';
        }
        else if(exp[i] == ')'){
            rev_exp[j] = '(';
        }
        else{
            // while(exp[i] != '+' || exp[i] != '-' || exp[i] != '*' || exp[i] != '/'){
            //     rev_exp[j] = exp[i];    
            // }
            rev_exp[j] = exp[i];
        }
        i--;
        j++;
    }

    printf("Reverse: %s\n", rev_exp);

    // infix to postfix
    char *curr = rev_exp;
    char postfix_exp[100] = {'\0'};

    int k = -1;
    while(*curr != '\0'){

        // case operand
        if(isOperand(*curr) == true){
            k++;
            postfix_exp[k] = *curr;
        }
        // case '(' push to stack
        else if(*curr == '('){
            push(*curr);
        }
        // case ')' pop stack until found '('
        else if(*curr == ')'){

            while(stack[top] != '('){
                k++;
                postfix_exp[k] = stack[top];
                pop();
            }
            pop();
        }
        else{
            while(precedence(stack[top]) >= precedence(*curr)){
                k++;
                postfix_exp[k] = stack[top];
                pop();
            }
            push(*curr);
        }

        curr++;
    }

    while(top != -1){
        k++;
        postfix_exp[k] = stack[top];
        pop();
    }

    printf("Infix to Postfix: %s\n", postfix_exp);

    // reverse
    char prefix_exp[100] = {'\0'};

    int m = strlen(postfix_exp) - 1;
    int n = 0;
    while(postfix_exp[m] != '\0'){

        if(postfix_exp[m] == '('){
            prefix_exp[n] = ')';
        }
        else if(postfix_exp[m] == ')'){
            prefix_exp[n] = '(';
        }
        else{
            // while(exp[i] != '+' || exp[i] != '-' || exp[i] != '*' || exp[i] != '/'){
            //     rev_exp[j] = exp[i];    
            // }
            prefix_exp[n] = postfix_exp[m];
        }
        m--;
        n++;
    }

    printf("Postfix to Prefix: %s\n", prefix_exp);

}

bool isOperand(char operand){
    if(isalnum(operand) != 0){
        return true;
    }
    else{
        return false;
    }
}

void push(char operator){
    top++;
    stack[top] = operator;
}

void pop(){
    top--;
}

int precedence(char operator){
    if(operator == '*' || operator == '/'){
        return 2;
    }
    else if(operator == '+' || operator == '-'){
        return 1;
    }
    else{
        return 0;
    }
}