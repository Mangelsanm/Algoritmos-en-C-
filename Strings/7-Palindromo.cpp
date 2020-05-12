/***************************************/
// Miguel Mares - mares112358@gmail.com
// 7-Palindromo.cpp
// Programa para saber si una frase es un
// palindromo.
/***************************************/
#include <iostream>
using namespace std;

bool palindromo(const char *frase);

int main() {
    char frase[] = "anita lava la tina";

    if(palindromo(&frase[0])) {
        cout << "La frase es un palindromo" << endl;
    }
    else {
        cout << "No es un palindromo" << endl;
    }

    return 0;
}
bool palindromo(const char *frase) {
    int i = 0;
    int j = 0;

    //Calcula la longitud del string
    for(j = 0; frase[j] != '\0'; j++) {}
    //Decrementa 1 ya que el indice del string es cero.
    j -= 1;

    for(i = 0; i < j; i++, j--) {
        //Si es un espacio, aumenta en 1 para tener un caracter.
        if(frase[i] == ' ') {
            i++;
        }
        //Si es un espacio, decrementa en 1 para tener un caracter.
        else if(frase[j] == ' ') {
            j--;
        }
        //Si los caracteres son diferentes, no es un palindromo.
        if(frase[i] != frase[j]){
            return 0;
            break;
        }
    }
    return 1;
}