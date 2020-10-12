#include <string.h>
#include <iostream>
using namespace std;

class Estudiante {
    int num_alm;
    float promedio;
    char *nombre;

    public:
    Estudiante(int = 0, float = 0.0, const char* = " ");
    Estudiante(const Estudiante &other);
    ~Estudiante();
    void set_nombre(char *);
    int get_num_alm() const;
    float get_promedio() const;
    const char *get_name() const;
};

inline Estudiante::Estudiante(int num_alm, float promedio, const char *nombre) {
    cout << "Llamada a Constructor" << endl;
    this->num_alm = num_alm;
    this->promedio = promedio;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

inline Estudiante::Estudiante(const Estudiante &other) {
    cout << "Constructor copia" << endl;
    num_alm = other.num_alm;
    promedio = other.promedio;
    /*nombre = new char[strlen(other.nombre) + 1];
    strcpy(this->nombre, other.nombre);*/
}

inline Estudiante::~Estudiante() {
    cout << "Llamada al destructor" << endl;
    delete [] nombre;
}

inline void Estudiante::set_nombre(char *nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

inline int Estudiante::get_num_alm() const {
    return num_alm;
}

inline float Estudiante::get_promedio() const {
    return promedio;
}

inline const char* Estudiante::get_name() const {
    return nombre;
}

int main() {
    Estudiante diego(510, 8.9, "Diego");    
    Estudiante felipe(diego);
    
    char nombre[] = "felipe";
    felipe.set_nombre(nombre);

    cout << "Diego: " << diego.get_num_alm() << " " << diego.get_promedio() << " " << diego.get_name() << endl;
    cout << "felipe: " << felipe.get_num_alm() << " " << felipe.get_promedio() << " " << felipe.get_name() << endl;
    return 0;
}