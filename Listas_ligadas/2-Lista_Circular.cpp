#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *next;
}*first = NULL;

void crearLista(int *elementos, int nElementos) {
    struct Nodo *ligar;
    struct Nodo *temp;

    first = (struct Nodo*)malloc(sizeof(struct Nodo));
    first->dato = elementos[0];
    first->next = NULL;
    //El puntero ligar servira para hacer el enlace entre nodos.
    ligar = first;

    for(int i = 1; i < nElementos; i++) {
        //Se crea un nodo para el elemento i-esimo del arreglo.
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = elementos[i];
        temp->next = NULL;
        //Linkea el nodo anterior (first en la primera iteracion, temp despues de la primer iteracion)
        //con el nodo creado anteriormente.
        ligar->next = temp;
        ligar = temp;
    }
}

//Funcion para imprimir la lista ligada.
void imprimir(struct Nodo *lista) {
    while(lista) {
        cout << lista->dato << " ";
        lista = lista->next;
    }
}

int main() {
    int elementos[] = {1, 5, 6, 0};
    crearLista(&elementos[0], 4);
    imprimir(first);
}