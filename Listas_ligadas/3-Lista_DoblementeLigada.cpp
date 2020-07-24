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
//Funcion para imprimir la lista ligada.
void imprimir(struct Nodo *lista) {
    while(lista != NULL) {
        cout << lista->dato << " ";
        lista = lista->next;
    }
}
//Funcion para saber la longitud de la lista.
int longitud(struct Nodo *lista) {
    int contador = 0;
    while(lista != NULL) {
        contador++;
        lista = lista->next;
    }
    return contador;
}
//Funcion para insertar un nuevo nodo a la lista.
void insertar(struct Nodo *lista, int indice, int valor) {
    struct Nodo *temporal;

    if(indice < 0 || indice > longitud(lista)){
        return;
    }

    if(indice == 0) {
        temporal = (struct Nodo*)malloc(sizeof(struct Nodo));
        temporal->dato = valor;
        temporal->prev = NULL;
        temporal->next = first;
        first->prev = temporal;
        first = temporal;
    }
    else {
        for(int i = 0; i < indice - 1; i++) {
            lista = lista->next;
        }
        temporal = (struct Nodo*)malloc(sizeof(struct Nodo));
        temporal->dato = valor;
        temporal->prev = lista;
        temporal->next = lista->next;
        if(lista->next) {
            lista->next->prev = temporal;
        }
        lista->next = temporal;
    }
}

int main() {
    int elementos[] = {5, 9, 3, 7, 1};
    crear(&elementos[0], 5);
    insertar(first, 5, 4);
    cout << "Longitud: " << longitud(first) << endl;
    imprimir(first);
}