#include <iostream>
using namespace std;

struct Nodo
{
    /* data */
    int dato;
    struct Nodo *next;
}*first = NULL;

void crearNodo(int *elementos, int nElements) {
    struct Nodo *last;
    struct Nodo *temp;

    first = (struct Nodo*)malloc(sizeof(struct Nodo));
    first->dato = elementos[0];
    first->next = NULL;
    //El puntero last servira para hacer el enlace entre nodos.
    last = first;

    for(int i = 1; i < nElements; i++) {
        //Se crea un nodo para el elemento i del arreglo.
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = elementos[i];
        temp->next = NULL;
        
        //Linkea el nodo anterior (first en la primera iteracion, temp despues de la primer iteracion)
        //con el nodo creado anteriormente.
        last->next = temp;
        last = temp;
    }
}

void imprimir(struct Nodo *lista) {
    while(lista) {
        cout << lista->dato << " ";
        lista = lista->next;
    }
}

//Funcion para imprimir de manera recursiva.
void Rimprimir(struct Nodo *lista) {
    if(lista != NULL) {
        //Se puede intercambiar el orden de las siguientes dos lineas para imprimir los valores
        //del primero al ultimo o del ultimo al primero.
        Rimprimir(lista->next);
        cout << lista->dato << " ";
    }
}

//Funcion para mostrar el numero de nodos en la lista.
void numNodos(struct Nodo *lista) {
    int cont = 0;
    while(lista != NULL) {
        cont++;
        lista = lista->next;
    }
    cout << "Numero de nodos: " << cont;
}

//funcion para mostrar el numero de nodos, de manera recursiva
int RnumNodos(struct Nodo *lista) {
    if(lista == NULL) {
        return 0;
    }
    else {
        return RnumNodos(lista->next) + 1;
    }
}

int main() {
    int elementos[] = {3, 6, 9, 12, 15, 18};
    crearNodo(&elementos[0], 6);
    imprimir(first);
    cout << endl;
    Rimprimir(first);
    cout << endl;
    numNodos(first);
    cout << endl;
    cout << "Numero de nodos: " << RnumNodos(first);
    return 0;
}