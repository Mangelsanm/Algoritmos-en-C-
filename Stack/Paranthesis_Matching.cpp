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
    bool isBalanced(char *expression);
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

void Stack::pop() {
    Nodo *temp = top;
    if(top == NULL) {
        cout << "Stack Underflow" << endl;
    }
    else {
        top = top->next;
        delete temp;
    }
}

bool Stack::isBalanced(char *expression) {
    for(int i = 0; expression[i] != '\0'; i++) {
        if(expression[i] == '(') {
            push(expression[i]);
        }
        else if(expression[i] == ')') {
            if(top == NULL) {
                return false;
            }
            else {
                pop();
            }
        }
    }
    if(top == NULL) {
        return true;
    }
    else {
        return false;
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
    st.pop();
    st.print();
    return 0;
}