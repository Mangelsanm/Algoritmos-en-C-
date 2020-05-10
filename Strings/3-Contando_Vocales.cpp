/****************************/
// Miguel Mares - mares112358@gmail.com
// 3-Contando_Vocales.cpp
// Programa para contar el numero de vocales 
// y consonantes, en una oracion.
/****************************/
#include <iostream>
using namespace std;

int main() {
    const char *nombre = "Hola como estas";
    int numero_vocales = 0;
    int numero_consonantes = 0;

    for(int i = 0; nombre[i] != '\0'; i++) {
        if( nombre[i] == 'A' || nombre[i] == 'E' ||
            nombre[i] == 'I' || nombre[i] == 'O' ||
            nombre[i] == 'U' || nombre[i] == 'a' ||
            nombre[i] == 'e' || nombre[i] == 'i' ||
            nombre[i] == 'o' || nombre[i] == 'u') {
                numero_vocales++;
            }
        //Incluye todas las letras del alfabeto
        else if(nombre[i] >= 65 && nombre[i] <= 90 ||
                nombre[i] >= 97 && nombre[i] <= 122) {
                numero_consonantes++;
            }
    }
    cout << "Numero de vocales: " << numero_vocales << endl;
    cout << "Numero de consonantes: " << numero_consonantes << endl;

    return 0;
}