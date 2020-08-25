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
//Funcion para borrar un elemento de la lista.
int borrar(struct Nodo *lista, int indice) {
    int valor = 0;
    //El indice enviado es valido?
    if(indice < 1 || indice > longitud(lista)) {
        return -1;
    }
    if(indice == 1) {
        first = first->next;
        //Verificar que el nuevo puntero first es valido
        if(first != NULL){
            first->prev = NULL;
        }
        valor = lista->dato;
        free(lista);
    }
    else {
        for(int i = 0; i < indice - 1; i++) {
            lista = lista->next;
        }
        lista->prev->next = lista->next;
        //Verificar si el nodo a borrar es el ultimo.
        if(lista->next != NULL) {
            lista->next->prev = lista->prev;
        }
        valor = lista->dato;
        free(lista);
    }
    return valor;
}
//Funcion para invertir una lista doblemente ligada.
void invertir(struct Nodo *lista) {
    struct Nodo *temporal;
    while(lista != NULL) {
        temporal = lista->next;
        lista->next = lista->prev;
        lista->prev = temporal;
        lista = lista->prev;
        if(lista != NULL && lista->next == NULL) {
            first = lista;
        }        
    }
}

int main() {
    int elementos[] = {5, 9, 3, 7, 1};
    crear(&elementos[0], 5);
    insertar(first, 5, 4);
    borrar(first, 3);
    invertir(first);
    cout << "Longitud: " << longitud(first) << endl;
    imprimir(first);
}