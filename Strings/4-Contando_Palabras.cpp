/***************************************/
// Miguel Mares - mares112358@gmail.com
// 4-Contando_Palabras.cpp
// Programa para contar el numero de
// palabras en una frase
/***************************************/
#include <iostream>
using namespace std;

int main() {
    char frase[] = "¿Hola como estas       amigo amigo?";
    // inicializar en 1, por que en realidad estamos contando espacios.
    int numero_palabras = 1;

    for(int i = 0; frase[i] != '\0'; i++) {
        // ¿ El indice actual de la frase es un espacio ?
        // && el indice anterior es una letra, para evitar
        // contar palabras si existe mas de un espacio entre ellas.
        if(frase[i] == ' ' && frase[i-1] != ' ') {
            numero_palabras++;
        }
    }
    cout << "Numero de palabras: " << numero_palabras << endl;
    return 0;
}