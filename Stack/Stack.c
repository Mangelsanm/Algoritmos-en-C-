/*********************************************************/
// Miguel Mares - mares112358@gmail.com
// Stack.c
//
/*********************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

void create(struct Stack *st) {
    printf("Enter the size of array: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->arr = (int*)malloc(st->size*sizeof(int));
}

void print(struct Stack *st) {
    for(int i = st->top; i >= 0; i--) {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int value) {
    if(st->top == st->size - 1) {
        printf("Stack Overflow");
    }
    else {
        st->top++;
        st->arr[st->top] = value;
    }
}

int pop(struct Stack *st) {
    int value = -1;
    if(st->top == -1) {
        printf("Stack Underflow");
    }
    else {
        value = st->arr[st->top];
        st->top--;
    }
    return value;
}

int peek(struct Stack *st, int position) {
    int x = -1;
    if(st->top - position + 1 < 0) {
        printf("Invalid index\n");
    }
    else {
        x = st->arr[st->top - position + 1];
    }
    return x;
}

int main() {
    struct Stack st;
    create(&st);

    /*Las siguientes lineas agregan un valor al stack*/
    push(&st, 4);
    push(&st, 1);
    push(&st, 13);
    push(&st, 7);
    push(&st, 2);
    /*Funcion para borrar un elemento*/
    pop(&st);
    /*Se impreme el contenido del Stack segun el valor de la variable top*/
    print(&st);
    /*Un Stack es LIFO, peek regresara la posicion de acuerdo este acuerdo LIFO*/
    printf("Valor de la posicion deseada: %d", peek(&st, 3));

    return 0;
}