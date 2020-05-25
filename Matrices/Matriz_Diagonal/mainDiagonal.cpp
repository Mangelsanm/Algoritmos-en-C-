#include <iostream>
#include "Diagonal.hpp"
using namespace std;

int main() {
    Diagonal diagonal(4);
    diagonal.setValue(1, 1, 2); diagonal.setValue(2, 2, 4);
    diagonal.setValue(3, 3, 6); diagonal.setValue(4, 4, 8);

    diagonal.mostrar();
    diagonal.getValue(3, 3);

    return 0;
}