#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *previo;
    Nodo *siguiente;
} *inicio = NULL;

void crear(int *elementos, int nElementos) {
    Nodo *temporal;
    Nodo *final;

    inicio = (Nodo*)malloc(sizeof(Nodo));
    inicio->dato = elementos[0];
    inicio->previo = NULL;
    inicio->siguiente = NULL;
    final = inicio;

    for(int i = 1; i < nElementos; i++) {
        temporal = (Nodo*)malloc(sizeof(Nodo));
        temporal->dato = elementos[i];
        temporal->previo = final;
        temporal->siguiente = NULL;
        final->siguiente = temporal;
        final = temporal;
    }

    final->siguiente = inicio;
    inicio->previo = final;
}

void imprimir(Nodo *lista){
    do {
        cout << lista->dato << " ";
        lista = lista->siguiente;
    } while(lista != inicio);
}

int main() {
    int arreglo[] = {3, 1, 5};
    crear(&arreglo[0], 3);
    imprimir(inicio);
    return 0;
}