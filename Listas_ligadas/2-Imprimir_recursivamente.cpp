#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *direccion;
}*first = NULL;

void crearNodo(int *elementos, int nElementos) {
    struct Nodo *last;
    struct Nodo *temp;
    first = (struct Nodo*)malloc(sizeof(struct Nodo));
    first->dato = elementos[0];
    first->direccion = NULL;
    last = first;

    for(int i = 1; i < nElementos; i++) {
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = elementos[i];
        temp->direccion = NULL;
        last->direccion = temp;
        last = temp; 
    }
}

void imprimir_lista(struct Nodo *p) {
    if(p != NULL) {
        imprimir_lista(p->direccion);
        cout << p->dato << " ";
    }
}

int main() {
    int elementos[] = {9, 5, 7, 1, 12};
    crearNodo(&elementos[0], 5);
    imprimir_lista(first);
    return 0;
}