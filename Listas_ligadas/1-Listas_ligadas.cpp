#include <iostream>
using namespace std;

struct Nodo
{
    /* data */
    int dato;
    struct Nodo *next;
}*first = NULL, *second = NULL, *tercero = NULL, *final = NULL;

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

void crearNodo2(int *elementos, int nElements) {
    struct Nodo *last;
    struct Nodo *temp;

    second = (struct Nodo*)malloc(sizeof(struct Nodo));
    second->dato = elementos[0];
    second->next = NULL;
    //El puntero last servira para hacer el enlace entre nodos.
    last = second;

    for(int i = 1; i < nElements; i++) {
        //Se crea un nodo para el elemento i del arreglo.
        temp = (struct Nodo*)malloc(sizeof(struct Nodo));
        temp->dato = elementos[i];
        temp->next = NULL;
        
        //Linkea el nodo anterior (second en la primera iteracion, temp despues de la primer iteracion)
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
//Funcion para insertar un elemento nuevo a la lista, pero siempre al final.
void insertarFinal(int valor) {
    struct Nodo *temporal = (struct Nodo*)malloc(sizeof(struct Nodo));
    temporal->dato = valor;
    temporal->next = NULL;

    //Si la lista esta vacia, first y final apuntan a NULL
    if(first == NULL) {
        first = final = temporal;
    }
    //Si la lista ya tiene al menos un elemento
    else {
        final->next = temporal;
        final = temporal;
    }
}
//Funcion para insertar un elemento en una lista ordenada
void insertarOrdenada(struct Nodo *lista, int elemento) {
    //Crear un nodo temporal
    struct Nodo *temporal, *previo = NULL;
    temporal = (struct Nodo*)malloc(sizeof(struct Nodo));
    temporal->dato = elemento;
    temporal->next = NULL;

    //Si no tenemos elementos en la lista, esta sera creada con temporal (parametro elemento)
    if(first == NULL) {
        first = temporal;
    }
    //Si tenemos al menos un elemento en la lista
    else {
        while(lista && elemento > lista->dato) {
            previo = lista;
            lista = lista->next;
        }
        //Si la lista tiene solo un elemento y este es mayor al valor que sera
        //agregado en la lista.
        if(lista == first) {
            temporal->next = first;
            first = temporal;
        }
        //Si tiene mas de un elemento y ya se encontro la posicion donde colocar el nuevo
        else {
            temporal->next = previo->next;
            previo->next = temporal;
        }
    }
}
//Funcion para borrar un nodo de la lista, se regresa el valor que
//contenia el nodo eliminado
int borrar(struct Nodo *lista, int indice) {
    //Nodo para guardar el elemento previo de la lista
    struct Nodo *previo = NULL;
    int x = -1;

    //Verificar si el indice a borrar es valido
    if((indice < 1) || (indice > numNodos(lista))) {
        return -1;
    }
    //Si el indice a eliminar es el primero
    if(indice == 1) {
        previo = first;
        x = first->dato;
        first = first->next; //first se mueve al siguiente nodo
        free(previo);
        return x; 
    }
    //Si el nodo a eliminar es diferente del primero
    else {
        for(int i = 0; i < indice - 1; i++) {
            previo = lista;
            lista = lista->next; //lista se mueve al siguiente nodo
        }
        previo->next = lista->next; //previo se enlaza al nodo que apunta lista
        x = lista->dato;
        free(lista);
        return x;
    }
}
//Funcion para saber si una lista esta ordenada
bool listaOrdenada(struct Nodo *lista) {
    int valor = INT_MIN;

    while(lista != NULL) {
        //Asumimos que la lista esta ordenada, si no es asi
        //regresamos false. Usamos una condicion de fallo (inversa)
        if(lista->dato < valor) {
            return false;
        }
        valor = lista->dato;
        lista = lista->next;
    }
    return true;
}
//Funcion para remover valores duplicados en una lista ligada
void removerDuplicados(struct Nodo *lista) {
    //Crear nodo previo e igualarlo al primer nodo y
    //Adelantar el primer nodo al siguiente (lista->next)
    struct Nodo *previo = lista;
    lista = lista->next;

    while(lista != NULL) {
        if(lista->dato != previo->dato) {
            previo = lista;
            lista = lista->next;
        }
        else {
            previo->next = lista->next;
            free(lista);
            lista = previo->next;
        }
    }
}
//Funcion para invertir una lista ligada
void invertirLista(struct Nodo *lista) {
    struct Nodo *previo = NULL;
    struct Nodo *temporal = NULL;

    while(lista != NULL) {
        //Recorremos todo los nodos al siguiente
        temporal = previo;
        previo = lista;
        lista = lista->next;
        //apuntamos al nodo anterior para invertir la lista
        previo->next = temporal;
    }
    //Ahora 
    first = previo;
}
//Funcion para combinar dos listas ordenadas
void combinar(struct Nodo *primero, struct Nodo *segundo) {
    struct Nodo *ultimo;

    //Determiamos cual de las dos listas tiene el valor mas pequeño 
    if(primero->dato < segundo->dato) {
        tercero = ultimo = primero;
        primero = primero->next;
        tercero->next = NULL;
        
    }
    else {
        tercero = ultimo = segundo;
        segundo = segundo->next;
        tercero->next = NULL;
        
    }
    //Seguimos con el resto de valores para las dos listas
    while((primero != NULL) && (segundo != NULL)) {
    if(primero->dato < segundo->dato) {
        ultimo->next = primero;
        ultimo = primero;
        primero = primero->next;
        ultimo->next = NULL;
    }
    else {
        ultimo->next = segundo;
        ultimo = segundo;
        segundo = segundo->next;
        ultimo->next = NULL;
    }
    }
    if(primero)
        ultimo->next = primero;
    if(segundo)
        ultimo->next = segundo;
}
//Funcion para saber si una lista es un LOOP
int LOOP(struct Nodo *lista) {
    struct Nodo *temporal;
    struct Nodo *previo;
    temporal = previo = lista;

    do {
        temporal = temporal->next;
        previo = previo->next;
        previo = previo ? previo->next : previo;
    } while (temporal && previo && (temporal != previo));

    if(temporal == previo) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    struct Nodo *temp1, *temp2;
    int elementos[] = {4, 8, 12, 16, 20};
    crearNodo(&elementos[0], 5);

    temp1 = first->next->next;
    temp2 = first->next->next->next->next;
    temp2->next = temp1;

    cout << LOOP(first);

    /*int elementos2[] = {2, 6, 10, 14, 18};
    crearNodo(&elementos[0], 5);
    crearNodo2(&elementos2[0], 5);

    cout << "Primer lista: ";
    imprimir(first);
    cout << "\nSegunda lista: ";
    imprimir(second);
    cout << "\n";
    combinar(first, second);
    imprimir(tercero);*/

    /*invertirLista(first);
    removerDuplicados(first);
    if(listaOrdenada(first)) {
        cout << "La lista esta ordenada" << endl;
    }
    else {
        cout << "La lista no esta ordenada" << endl;
    }
    
    cout << "El nodo que se elimino tenia el dato: " << borrar(first, 3) <<endl;
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
    cout << endl;*/
    /*insertarFinal(1);
    insertarFinal(2);
    insertarFinal(3);
    insertarFinal(4);
    insertarFinal(5);
    insertarFinal(6);
    insertar(4, 10);*/
    return 0;
}