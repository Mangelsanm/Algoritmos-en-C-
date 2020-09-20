#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int dato;
    struct Stack *next;
}*first = NULL, *last = NULL;

void create(int nElements, int *elements) {
    struct Stack *temp;
    first = (struct Stack*)malloc(sizeof(struct Stack));
    first->dato = elements[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < nElements; i++) {
        temp = (struct Stack*)malloc(sizeof(struct Stack));
        temp->dato = elements[i];
        temp->next = last;
        last = temp;
    }
}

void print(struct Stack *lista) {
    while(lista != NULL) {
        printf("%d ", lista->dato);
        lista = lista->next;
    }
}

int main() {
    int arr[] = {19, 37, 6, 9, 12};
    create(5, &arr[0]);
    print(last);
    return 0;
}