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

int Stack::pop(){
    Nodo *temp = new Nodo;
    int value = -1;
    if(top == NULL) {
        cout << "Stack Underflow";
    }
    else {
        temp = top;
        top = top->next;
        value = temp->dato;
        delete temp;
    }
    return value;
}

void Stack::print() {
    Nodo *temp = top;
    while(temp != NULL) {
        cout << temp->dato << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Stack st;
    st.push(9);
    st.push(11);
    st.push(7);
    st.print();
    return 0;
}