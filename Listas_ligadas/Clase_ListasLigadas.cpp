#include <iostream>
using namespace std;

class Nodo {
    public:
    int dato;
    Nodo *next;
};

class ListaLigada {
    private:
    Nodo *first;

    public:
    ListaLigada();
    ListaLigada(int *elementos, int nElementos);
    ~ListaLigada();
    void imprimir();
    int longitud();
    void insertar(int indice, int valor);
    int eliminar(int indice);
};
ListaLigada::ListaLigada() {
    first = NULL;
}
ListaLigada::ListaLigada(int *elementos, int nElementos) {
    Nodo *final;
    Nodo *temporal;

    first = new Nodo;
    first->dato = elementos[0];
    first->next = NULL;
    final = first;

    for(int i = 1; i < nElementos; i++) {
        temporal = new Nodo;
        temporal->dato = elementos[i];
        temporal->next = NULL;
        final->next = temporal;
        final = temporal;
    }
}
ListaLigada::~ListaLigada() {
    Nodo *lista = first;
    while(first != NULL) {
        first = first->next;
        delete lista;
        lista = first;
    }
}
void ListaLigada::imprimir() {
    Nodo *lista = first;
    while(lista != NULL) {
        cout << lista->dato << " ";
        lista = lista->next;
    }
}
int ListaLigada::longitud() {
    Nodo *lista = first;
    int contador = 0;
    while(lista != NULL) {
        contador++;
        lista = lista->next;
    }
    return contador;
}
void ListaLigada::insertar(int indice, int valor) {
    Nodo *lista = first;

    if(indice < 0 || indice > longitud()) {
        return;
    }

    Nodo *temporal = new Nodo;
    temporal->dato = valor;
    temporal->next = NULL;

    if(indice == 0) {
        temporal->next = first;
        first = temporal;
    }
    else {
        for(int i = 0; i < indice - 1; i++) {
            lista = lista->next;
        }
        temporal->next = lista->next;
        lista->next = temporal;
    }
}
int ListaLigada::eliminar(int indice) {
    Nodo *lista = first;
    Nodo *previo = NULL;
    int valor = 0;

    if(indice < 0 || indice > longitud()){
        return;
    }

    if(indice == 0) {
        previo = first;
        valor = lista->dato;
        first = first->next;
        delete lista;
        return valor;
    }
    else {
        for(int i = 0; i < indice - 1; i++) {
            lista = lista->next;
        }
        lista->next = 
    }
}

int main() {
    int elementos[] = {1, 3, 5, 7, 9};
    int nElements;
    ListaLigada lista(&elementos[0], 5);

    lista.insertar(1, 10);
    lista.imprimir();
    nElements = lista.longitud();

    cout << "\nNumero de nodos: " << nElements;
}