#include <iostream>
using namespace std;

struct Nodo
{
    struct Nodo *prev;
    int dato;
    struct Nodo *next;
} *first = NULL;

void crear(int *elementos, int nElementos) {
    struct Nodo *temporal;
    struct Nodo *final;

    first = (struct Nodo*)malloc(sizeof(struct Nodo));
    first->prev = NULL;
    first->dato = elementos[0];
    first->next = NULL;
    final = first;

    for(int i = 1; i < nElementos; i++) {
        temporal = (struct Nodo*)malloc(sizeof(struct Nodo));
        temporal->prev = final;
        temporal->dato = elementos[i];
        temporal->next = NULL;
        final->next = temporal;
        final = temporal;
    }
}