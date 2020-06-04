#include <iostream>
using namespace std;

// Estructura para crear un nodo
struct Nodo
{
    int dato = 3;
    struct Nodo *dir;
}*first = NULL;

void crear_Nodo(int *A, int nElements) {
    struct Nodo *temp;
    // last sirve para enlazar los nodos que seran creados
    struct Nodo *last;
    first = (struct Nodo*)malloc(sizeof(struct Nodo));
    first -> dato = A[0];
    first -> dir = NULL;
    // last y first apuntan a la misma direccion de memoria
    last = first;

    for(int i = 1; i < nElements; i++) {
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = A[i];
        temp->dir = NULL;
        // La variable dir de first/temp se actualiza con la direccion de temp, ya que last = first
        last->dir = temp;
        // Se iguala la direccion a la que apunta last para hacer el enlace en el siguiente nodo.
        last = temp;
    }
    cout << endl;
}

void display(struct Nodo *p) {
    while(p != NULL) {
        cout << p->dato << " ";
        p = p->dir;
    }
}

int main() {
    int A[] = {9, 5, 7, 1, 12};
    crear_Nodo(&A[0], 5);
    display(first);
    return 0;
}