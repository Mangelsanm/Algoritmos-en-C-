#include <iostream>
#include "Inferior.hpp"
using namespace std;

int main() {
    int dimension;
    cout << "Entre dimesion: ";
    cin >> dimension;

    Inferior triangular(dimension);

    int valor;
    cout << "Introducir valores" << endl;
    for(int i = 1; i <= dimension; i++) {
        for(int j = 1; j <= dimension; j++) {
            cin >> valor;
            triangular.setValue(i, j, valor);
        }
    }
    cout << endl;
    cout << "Matriz resultado" << endl;
    triangular.display();

    return 0;
}