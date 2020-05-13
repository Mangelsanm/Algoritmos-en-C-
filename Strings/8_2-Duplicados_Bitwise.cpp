/***************************************/
// Miguel Mares - mares112358@gmail.com
// 8_2-Duplicados_Bitwise.cpp
// Programa para saber si en una frase hay
// letras duplicadas.
// Esta version utiliza operaciones bit a bit.
// Este programa solo sirve para minisculas.
/***************************************/
#include <iostream>
using namespace std;

int main() {
    char frase[] = "pantalla";
    int arreglo = 0;
    int x = 0;

    for(int i = 0; frase[i] != '\0'; i++) {
        x = 1;
        //Left shift para hacer masking con la variable arreglo.
        //Restar 97 que es donde comienzan las letras minusculas.
        x = x << frase[i] - 97;
        //Masking
        if(x & arreglo) {
            cout << "La letra " << frase[i] << " esta duplicada" << endl;
        }
        else {
            //Merging
            arreglo = x | arreglo;
        }
    }

    return 0;
}