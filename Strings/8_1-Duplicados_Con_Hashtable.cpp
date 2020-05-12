/***************************************/
// Miguel Mares - mares112358@gmail.com
// 8_1-Duplicados_Con_Hashtable.cpp
// Programa para saber si en una frase hay
// letras duplicadas.
// Esta version es usando una Hashtable.
// Este programa solo sirve para minisculas.
/***************************************/
#include <iostream>
using namespace std;

int main() {
    char palabra[] = "busquedas";
    //Crear la Hashtable vacia (solo para minisculas).
    int tabla[26] = {0};

    for(int i = 0; palabra[i] != '\0'; i++) {
        //Restar 97 que es donde comienzan las letras minusculas.
        tabla[palabra[i] - 97]++;
    }
    for(int i = 0; i < 26; i++) {
        if(tabla[i] > 1) {
            //Incrementar 97 para saber que letra es.
            char letra = i + 97;
            cout << "La letra " << letra << " esta duplicada" << endl;
        }
    }
    return 0;
}