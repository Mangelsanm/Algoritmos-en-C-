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
//Funcion para contar el numero de nodos en una lista circular.
int longitud(struct Nodo *lista) {
    int contador = 0;
    do {
        contador++;
        lista = lista->next;
    } while(lista != Head);
    return contador;
}
//Funcion para insertar un elemento en la lista.
void insertar(struct Nodo *lista, int indice, int valor) {
    struct Nodo *temp;

    if(indice < 0 || indice > longitud(Head)) {
        return;
    }

    //Insertar antes de Head, indice igual a cero.
    if(indice == 0) {
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = valor;
        //Si no existe ningun nodo en la lista, crear el primero y
        //apuntar a si mismo.
        if(Head == NULL) {
            Head = temp;
            Head->next = Head;
        }
        else {
            while(lista->next != Head){
                lista = lista->next;
            }
            lista->next = temp;
            temp->next = Head;
            Head = temp;
        }
    }
    //Si el indice es diferente de cero.
    else {
        for(int i = 0; i < indice - 1; i++) {
            lista = lista->next;
        }
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = valor;
        temp->next = lista->next;
        lista->next = temp;
    }
}

int main() {
    int elementos[] = {1, 5, 6, 0};
    crearLista(&elementos[0], 4);
    insertar(Head, 10, 9);
    imprimir(Head);
}