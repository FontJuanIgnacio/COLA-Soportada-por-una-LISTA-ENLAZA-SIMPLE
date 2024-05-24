#include <iostream>
#include <string> // Agregamos la librería para usar el tipo de dato string

using namespace std;

struct nodo {
    string info; // Cambiamos el tipo de dato a string
    nodo* next;
};

struct cola {
    nodo* frente;
    nodo* fondo;
};

void inicializar(cola& c);
void insertar(cola& c, const string& x); // Usamos una referencia constante para el string
string borrar(cola& c); // Cambiamos el tipo de retorno a string
int verVacia(cola& c);

int main() {
    cout << "Bienvenido al IDE en línea. ¡Feliz codificación! :)" << endl;
    cola c;
    inicializar(c);
    insertar(c, "JUAN IGNACIO");
    insertar(c, "MIGUEL GERONIMO");
    insertar(c, "MIGUEL RAMON");

    cout << "Elemento borrado: " << borrar(c) << endl;
    cout << "Elemento borrado: " << borrar(c) << endl;
    cout << "Elemento borrado: " << borrar(c) << endl;

    return 0;
}

void inicializar(cola& c) {
    c.frente = NULL;
    c.fondo = NULL;
}

void insertar(cola& c, const string& x) {
    nodo* p = new nodo;
    if (p == NULL) {
        cout << "Error: falta de memoria" << endl;
        exit(1);
    } else {
        p->info = x;
        p->next = NULL;
        if (c.frente == NULL)
            c.frente = p;
        else
            c.fondo->next = p;
        c.fondo = p;
    }
}

// 0 = no está vacía, 1 = está vacía
int verVacia(cola& c) {
    if (c.frente == NULL)
        return 1;
    else
        return 0;
}

string borrar(cola& c) {
    if (verVacia(c) == 1) {
        cout << "Error: cola vacía" << endl;
        exit(1);
    } else {
        nodo* p = c.frente;
        string x = p->info;
        c.frente = c.frente->next;
        delete p;

        if (c.frente == NULL)
            c.fondo = NULL;
        return x;
    }
}