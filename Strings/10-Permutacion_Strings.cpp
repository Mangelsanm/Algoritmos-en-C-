/*********************************************************/
// Miguel Mares - mares112358@gmail.com
// 10-Permutacion_Strings.cpp
// Permiutaciones de 3 caracteres usando recursividad.
// Puede incrementarse el numero de caracteres al deseado.
/*********************************************************/
#include <iostream>
using namespace std;

int permutacion(char letras[], int k) {
    //El numero de elementos para los arreglos = elementos a permutar + 1
    //Arreglo para almacenar resultados de permutacion y arreglo A para
    //saber si el elemento en cuestion se encuentra en resultado o no.
    const int nElementos = 4;
    static char resultado[nElementos] = {0};
    static int A[nElementos] = {0}; //Este arreglo solo tendra valores de 0 y 1

    //Si se llego al ultimo elemento, imprimir resultado.
    if(letras[k] == '\0') {
        resultado[k] == '\0';
        cout << resultado << endl;
    }
    else {
        //Ciclo For para almacenar los caracteres en el arreglo resultado,
        //y setear a 1 (en arreglo A) los caracteres alamcenados en resultado
        for(int i = 0; letras[i] != '\0'; i++) {
            if(A[i] == 0) {
                resultado[k] = letras[i];
                A[i] = 1; 
                permutacion(letras, k + 1);
                //Cada que termina un ciclo For, regresa al estado anterior en el stack
                //regresa a la cuenta anterior para las variables i y k.
                A[i] = 0;
            }
        }
    }
}
int main() {
    //Caracteres a permutar.
    char letras[] = "ABC";
    permutacion(letras, 0);
    return 0;
}