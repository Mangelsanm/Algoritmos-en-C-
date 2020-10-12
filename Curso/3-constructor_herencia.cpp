#include <iostream>
using namespace std;

class Base {
    protected:
    int base_number;

    public:
    Base(int = 0);
    ~Base();
    int getBaseNumber() const;
};

inline Base::Base(int x) : base_number(x) {
    cout << "Constructor base" << endl;
}

inline Base::~Base() {
    cout << "Destructor base" << endl;
}

inline int Base::getBaseNumber() const {
    return base_number;
}

class Derivada : public Base {
    private:
    int derivada_number;
    
    public:
    Derivada(int = 0, int = 0);
    ~Derivada();
    int getDerivadaNumber() const;
};

inline Derivada::Derivada(int x, int y)
                    : Base(x), derivada_number(y) {
                        cout << "Constructor derivada" << endl;
                    }

inline Derivada::~Derivada() {
    cout << "Destructor derivada" << endl;
}

inline int Derivada::getDerivadaNumber() const {
    return derivada_number;
}

int main() {
    Derivada d(8, 7);
    cout << "d = (" << d.getBaseNumber()
         << ", " << d.getDerivadaNumber() << ")" << endl;
    return 0;
}
