#include <iostream>
using namespace std;

struct Nodo
{
    int dato = 3;
    struct Nodo *dir;
}*first = NULL;

void crear_Nodo(int *A, int nElements) {
    struct Nodo *temp;
    struct Nodo *last;
    first = (struct Nodo *)malloc(sizeof(struct Nodo));
    first -> dato = A[0];
    first -> dir = NULL;
    last = first;

    for(int i = 1; i < nElements; i++) {
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = A[i];
        temp->dir = NULL;
        last->dir = temp;
        last = temp;
    }

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