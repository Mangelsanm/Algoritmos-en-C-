#include <iostream>
using namespace std;

class Nodo {
public:
    char data;
    Nodo *next;
};

class Stack {
private:
    Nodo *top;
public:
    Stack() {top = NULL;}
    void push(char character);
    void pop();
    void print();
};

void Stack::push(char character) {
    Nodo *temp = new Nodo;
    if(temp == NULL) {
        cout << "Stack Overflow" << endl;
    }
    else {
        temp->data = character;
        temp->next = top;
        top = temp;
    }
}

void Stack::print() {
    Nodo *temp = top;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Stack st;
    st.push('t');
    st.push('s');
    st.push('e');
    st.push('t');
    st.print();
    return 0;
}