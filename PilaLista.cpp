#include <iostream>
using namespace std;

// Nodo de la lista enlazada
struct Nodo {
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class Pila {
private:
    Nodo* top;   // apunta al ultimo nodo agregado

public:
    Pila() {
        top = nullptr;
    }

    // Liberar memoria al destruir la pila
    ~Pila() {
        while (!estaVacia()) {
            Nodo* temp = top;
            top = top->siguiente;
            delete temp;
        }
    }

    bool estaVacia() {
        return top == nullptr;
    }

    // No existe estaLlena(): la pila crece dinamicamente

    void push(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = top;   // el nuevo apunta al antiguo tope
        top = nuevo;              // el nuevo pasa a ser el tope

        cout << "Se agrego: " << valor << endl;
    }

    int pop() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia." << endl;
            return -1;
        }

        Nodo* temp = top;
        int valor = temp->dato;
        top = top->siguiente;     // el tope baja al siguiente nodo
        delete temp;

        cout << "Se elimino: " << valor << endl;
        return valor;
    }

    int peek() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia." << endl;
            return -1;
        }
        return top->dato;
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La pila esta vacia." << endl;
            return;
        }

        cout << "Pila (de tope a base):" << endl;
        Nodo* actual = top;
        while (actual != nullptr) {
            cout << "  " << actual->dato << endl;
            actual = actual->siguiente;
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

    pila.pop();  // sale 10
    pila.pop();  // pila vacia -> error

    return 0;
}
