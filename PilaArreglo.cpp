#include <iostream>
using namespace std;

const int MAX = 5;

class Pila {
private:
    int datos[MAX];
    int top;

public:
    Pila() {
        top = -1;
    }

    bool estaVacia() {
        return top == -1;
    }

    bool estaLlena() {
        return top == MAX - 1;
    }

    void push(int valor) {
        if (estaLlena()) {
            cout << "Error: la pila esta llena." << endl;
            return;
        }

        top++;
        datos[top] = valor;

        cout << "Se agrego: " << valor << endl;
    }

    int pop() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia." << endl;
            return -1;
        }

        int valor = datos[top];
        top--;

        cout << "Se elimino: " << valor << endl;
        return valor;
    }

    int peek() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia." << endl;
            return -1;
        }
        return datos[top];
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La pila esta vacia." << endl;
            return;
        }

        cout << "Pila (de tope a base):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "  " << datos[i] << endl;
        }
    }
};

int main() {
    Pila pila;

    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.mostrar();

    cout << "Tope actual: " << pila.peek() << endl;

    pila.pop();  // sale 30 (el ultimo en entrar es el primero en salir)
    pila.pop();  // sale 20
    pila.mostrar();

    // Probar desbordamiento (pila llena)
    for (int i = 1; i <= 6; i++) {
        pila.push(i * 100);
    }

    // Vaciar la pila y probar pila vacia
    while (!pila.estaVacia()) {
        pila.pop();
    }
    pila.pop();

    return 0;
}
