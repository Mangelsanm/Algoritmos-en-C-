#include <iostream>
#include "Inferior.hpp"
using namespace std;

Inferior::Inferior(int dimension): dimension(dimension) {
    matriz = new int [dimension * (dimension + 1) / 2];
}

Inferior::~Inferior() {
    delete [] matriz;
}

void Inferior::setValue(int renglon, int columna, int valor) {
    if(renglon >= columna) {
        matriz[(renglon * (renglon - 1)/2) + (columna - 1)] = valor;
    }
}

void Inferior::getValue(int renglon, int columna) {
    if(renglon >= columna) {
        cout << matriz[(renglon * (renglon - 1)/2) + (columna - 1)] << endl;
    }
}

void Inferior::display() {
    for(int i = 1; i <= dimension; i++) {
        for(int j = 1; j <= dimension; j++) {
            if(i >= j) {
                cout << matriz[(i * (i - 1)/2) + (j - 1)] << " " << flush;
            }
            else {
                cout << 0 << " " << flush;
            }
        }
        cout << endl;
    }
}