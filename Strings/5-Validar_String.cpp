/***************************************/
// Miguel Mares - mares112358@gmail.com
// 5-Validar_String.cpp
// Programa para validar un nombre de usuario
// (que no contenga caracteres especiales).
/***************************************/
#include <iostream>
using namespace std;

bool validar(const char *usuario);

int main() {
    const char *usuario = "Mig*el";

    if(validar(&usuario[0])) {
        cout << "Usuario valido";
    }
    else {
        cout << "No incluir caracteres especiales";
    }
    
    return 0;
}

bool validar(const char *usuario) {
    for(int i = 0; usuario[i] != '\0'; i++) {
        // Contemplar solo las letras del alfabeto
        // y numeros.
        if( !(usuario[i] >= 65 && usuario[i] <= 90) &&
            !(usuario[i] >= 97 && usuario[i] <= 122) &&
            !(usuario[i] >= 48 && usuario[i] <= 57)) {
            return 0;
            break;
        }
    }
    return 1;
}