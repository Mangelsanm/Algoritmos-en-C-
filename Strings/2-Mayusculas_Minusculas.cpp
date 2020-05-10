/****************************/
// Miguel Mares - mares112358@gmail.com
// Mayusculas_Minusculas.cpp
// Programa para cambiar de minusculas a mayusculas 
// y viceversa. Si la palabra esta en minusculas la
// salida estara en mayusculas y lo opuesto.
// Si la palabra contiene tanto mayusculas como minu-
// culas alternara cada letra por su opuesto.
/****************************/

#include <iostream>
using namespace std;

int main() {
    char palabra[] = "bienvenido";
    int i = 0;
    
    //Ciclo for hasta encontrar el delimitador
    for(i = 0; palabra[i] != '\0'; i++) {
        //Condicion para las letras Mayusculas
        if(palabra[i] >= 65 && palabra[i] <= 90) {
            palabra[i] += 32;
        }
        //Condicion para las letras Minusculas
        else if(palabra[i] >= 97 && palabra[i] <= 122) {
            palabra[i] -= 32;
        }
    }
    cout << "\n" << palabra << "\n" << endl;
    return 0;
}