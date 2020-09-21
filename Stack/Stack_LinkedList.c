#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int dato;
    struct Stack *next;
}*top = NULL;

void push(int value) {
    struct Stack *temp;
    temp = (struct Stack*)malloc(sizeof(struct Stack));
    
    if(temp == NULL) {
        printf("Stack Overflow\n");
    }
    else {
        temp->dato = value;
        temp->next = top;
        top = temp;
    }

}

int pop() {
    struct Stack *temp = (struct Stack*)malloc(sizeof(struct Stack));
    int value = -1;
    if(top == NULL) {
        printf("Stack Underflow");
    }
    else {
        temp = top;
        top = top->next;
        value = temp->dato;
        free(temp);
    }
    return value;
}

void print() {
    struct Stack *temp;
    temp = top;
    while(temp != NULL) {
        printf("%d ", top->dato);
        top = top->next;
    }
}

int main() {
    /*Crea una lista ligada de 7 elementos usando la funcion push*/
    push(10);
    push(31);
    push(21);
    push(87);
    push(45);
    push(6);
    push(14);
    /*Borrar uno de los nodos de la lista, usando la funcion pop*/
    pop();
    /*Imprime el stack con la lista ligada*/
    print();
    return 0;
}