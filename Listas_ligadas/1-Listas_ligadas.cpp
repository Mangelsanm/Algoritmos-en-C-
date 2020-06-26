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
//Funcion para imprimir la lista ligada.
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
int numNodos(struct Nodo *lista) {
    int cont = 0;
    while(lista != NULL) {
        cont++;
        lista = lista->next;
    }
    return cont;
}
//Funcion para mostrar el numero de nodos, de manera recursiva
int RnumNodos(struct Nodo *lista) {
    if(lista == NULL) {
        return 0;
    }
    else {
        return RnumNodos(lista->next) + 1;
    }
}
//Funcion para sumar el dato de cada nodo.
int sumaNodos(struct Nodo *lista) {
    int suma = 0;
    while(lista) {
        suma = suma + lista->dato;
        lista = lista->next;
    }
    return suma;
}
//Funcion para sumar los datos de cada nodo de manera recursiva.
int RsumaNodos(struct Nodo *lista) {
    if(lista == NULL) {
        return 0;
    }
    else {
        return RsumaNodos(lista->next) + lista->dato;
    }
}
//Funcion para encontrar el valor maximo de una lista ligada.
int valMax(struct Nodo *lista) {
    int maximo = INT_MIN;

    while(lista) {
        if(lista->dato > maximo) {
            maximo = lista->dato;
        }
        lista = lista->next;
    }
    return maximo;
}
//Funcion para encontrar el valor maximo de manera recursiva.
int RvalMax(struct Nodo *lista) {
    int x = 0;

    if(lista == NULL) {
        return INT_MIN;;
    }
    else {
        x = RvalMax(lista->next);
        // 1er manera de calcular (comentar o descomentar para probar)
        return x > lista->dato ? x : lista->dato;
        // 2da manera de calcular (comentar o descomentar para probar)
        /*if(x > lista->dato) {
            return x;
        }
        else {
            return lista->dato;
        }*/
    }
}
//Busqueda de un elemento en la lista.
Nodo* busqueda(struct Nodo *lista, int elemento) {
    while(lista != NULL) {
        if(elemento == lista->dato) {
            return lista;
        }
        lista = lista->next;
    }
    return NULL;
}
//Busqueda de un elemento de manera recursiva
Nodo* Rbusqueda(struct Nodo *lista, int elemento) {
    if(lista == NULL) {
        return NULL;
    }
    if(elemento == lista->dato) {
        return lista;
    }
    return Rbusqueda(lista->next, elemento);
}
//Algoritmo de busqueda mejorado
Nodo* busquedaMejorada(struct Nodo *lista, int elemento) {
    struct Nodo *enlace = NULL;
    while(lista != NULL) {
        if(elemento == lista->dato) {
            enlace->next = lista->next;
            lista->next = first;
            first = lista;
            return lista;
        }
        enlace = lista;
        lista = lista->next;
    }
    return NULL;
}
//Funcion para insertar un nuevo elemento en la lista
void insertar(struct Nodo *lista, int indice, int elemento) {
    struct Nodo *temporal;
    //Condicion para asegurar que el indice es valido
    if(indice < 0 || indice > numNodos(lista)){
        return;
    }
    //Independientemente de donde se insertara el nuevo nodo
    //primero asignamos el valor al nodo temporal.
    temporal = (struct Nodo*)malloc(sizeof(struct Nodo));
    temporal->dato = elemento;

    //Si el nodo se inserta al inicio de la lista
    if(indice == 0) {
        temporal->next = first;
        first = temporal;
    }
    //Si el nodo se inserta al final o entre los nodos presentes
    //de la lista
    else {
        for (int i = 0; i < indice - 1; i++) {
            lista = lista->next;
        }
        temporal->next = lista->next;
        lista->next = temporal;
    }
}

int main() {
    int elementos[] = {3, 6, 39, 12, 115, 1};
    crearNodo(&elementos[0], 6);
    imprimir(first);
    cout << endl;
    Rimprimir(first);
    cout << endl;
    cout << "Numero de nodos: " << numNodos(first);
    cout << endl;
    cout << "Numero de nodos: " << RnumNodos(first);
    cout << endl;
    cout << "La suma de todos los nodos es: " << sumaNodos(first);
    cout << endl;
    cout << "La suma de todos los nodos es: " << RsumaNodos(first);
    cout << endl;
    cout << "El valor maximo de la lista es: " << valMax(first);
    cout << endl;
    cout << "El valor maximo de la lista es: " << RvalMax(first);
    cout << endl;
    cout << "Direccion del elemento es: " << busqueda(first, 39);
    cout << endl;
    cout << "Direccion del elemento es: " << Rbusqueda(first, 39);
    cout << endl;
    cout << "Direccion del elemento es: " << busquedaMejorada(first, 115);
    cout << endl;
    imprimir(first);
    insertar(first, 3, 95);
    cout << endl;
    imprimir(first);
    return 0;
}