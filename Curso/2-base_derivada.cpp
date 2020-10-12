#include <iostream>
using namespace std;

class Base {
    protected:
    int number; 

    public:
    Base(int = 0);
    int getNumber() const;
};

inline Base::Base(int x): number(x) {}
inline int Base::getNumber() const {
    return number;
}

class Derived: public Base {
    private:
    int number;

    public:
    Derived(int = 1);
    int getNumber() const;
};

inline Derived::Derived(int y): number(y) {}
inline int Derived::getNumber() const {
    return number + 1;
}

int main() {
    Derived d;
    cout << d.getNumber() << endl;
    cout << d.Base::getNumber() << endl;
    return 0;
}