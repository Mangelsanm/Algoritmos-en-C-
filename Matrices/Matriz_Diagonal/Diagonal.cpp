#include <iostream>
#include "Diagonal.hpp"
using namespace std;

Diagonal::Diagonal(int dimension): dimension(dimension) {
    matriz = new int[dimension];
}

Diagonal::~Diagonal() {
    delete [] matriz;
}

void Diagonal::setValue(int renglon, int columna, int valor) {
    if(renglon == columna) {
        matriz[renglon - 1] = valor;
    }
}

void Diagonal::getValue(int renglon, int columna) {
    if(renglon == columna) {
        cout << matriz[renglon-1];
    }
}

void Diagonal::mostrar() {
    for(int i = 0; i < dimension; i++) {
        for(int j = 0; j < dimension; j++) {
            if(i == j) {
                cout << matriz[i] << "  " << flush;
            }
            else {
                cout << 0 << "  " << flush;
            }
        }
        cout << endl;
    }
}