/***************************************/
// Miguel Mares - mares112358@gmail.com
// 6-Invertir_String.cpp
// Programa para invertir una frase.
/***************************************/
#include <iostream>
using namespace std;

int main() {
    char frase[] = "implementar";
    int temporal = 0;
    int i = 0;
    int j = 0;

    //Debemos saber la longitud del string.
    for(j = 0; frase[j] != '\0'; j++) {}
    //Restamos 1 a j debido a que, el string
    //comienza en el indice 0.
    j -= 1;

    //Se hace el intercambio de caracteres.
    for(i = 0; i < j; i++, j--) {
        temporal = frase[i];
        frase[i] = frase[j];
        frase[j] = temporal;
    }

    cout << frase << endl;

    return 0;
}