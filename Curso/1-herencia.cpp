#include <iostream>
using namespace std;

class Base {
private:
    int numero;
};

class Derivada: public Base {
public:
    Derivada(){
        numero = 1;
    }
    void incrementa() {
        numero++;
        cout << numero << endl;
    }
};

int main() {
    Derivada suma;
    suma.incrementa();
    return 0;
}