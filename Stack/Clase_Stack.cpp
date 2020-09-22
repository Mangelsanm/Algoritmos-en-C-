#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo *next;
};

class Stack {
private:
    Nodo *top;
public:
    Stack(){top = NULL;}
    void push(int value);
    int pop();
    void print();
};

void Stack::push(int value) {
    Nodo *temp = new Nodo;
    if(temp == NULL) {
        cout << "Stack Overflow";
    }
    else {
        temp->dato = value;
        temp->next = top;
        top = temp;
    }
}

int main() {
    return 0;
}