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
    ListaLigada() {first = NULL;}
    ListaLigada(int *elementos, int nElementos);
    ~ListaLigada();
    void imprimir();
    void insertar(int indice, int valor);
    int borrar(int indice);
    int longitud();
};