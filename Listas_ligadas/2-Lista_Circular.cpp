#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *next;
}*Head = NULL;

void crearLista(int *elementos, int nElementos) {
    struct Nodo *last;
    struct Nodo *temp;

    Head = (struct Nodo*)malloc(sizeof(struct Nodo));
    Head->dato = elementos[0];
    Head->next = Head;
    //El puntero last servira para hacer el enlace entre nodos.
    last = Head;

    for(int i = 1; i < nElementos; i++) {
        //Se crea un nodo para el elemento i-esimo del arreglo.
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = elementos[i];
        temp->next = last->next;
        //Linkea el nodo anterior (Head en la primera iteracion, temp despues de la primer iteracion)
        //con el nodo creado anteriormente.
        last->next = temp;
        last = temp;
    }
}

//Funcion para imprimir la lista ligada.
void imprimir(struct Nodo *lista) {
    do {
        cout << lista->dato << " ";
        lista = lista->next;
    }while(lista != Head);
}

int main() {
    int elementos[] = {1, 5, 6, 0};
    crearLista(&elementos[0], 4);
    imprimir(Head);
}