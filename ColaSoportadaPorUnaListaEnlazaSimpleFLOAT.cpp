#include <iostream>

using namespace std;

struct nodo {
    float info; // Cambiamos el tipo de dato a float
    nodo* next;
};

struct cola {
    nodo* frente;
    nodo* fondo;
};

void inicializar(cola& c);
void insertar(cola& c, float x); // Cambiamos el tipo de dato a float
float borrar(cola& c); // Cambiamos el tipo de retorno a float
int verVacia(cola& c);

int main() {
    cout << "Bienvenido al IDE en línea. ¡Feliz codificación! :)" << endl;
    cola c;
    inicializar(c);
    insertar(c, 3.14); // NUMERO PI
    insertar(c, 2.718); // NUMERO DE EULER
    insertar(c, 1.618); // NUMERO AUREO

    cout << "Elemento que es numero PI borrado: " << borrar(c) << endl;
    cout << "Elemento que es numero de EULER borrado: " << borrar(c) << endl;
    cout << "Elemento  que es numero AUREO borrado: " << borrar(c) << endl;

    return 0;
}

void inicializar(cola& c) {
    c.frente = NULL;
    c.fondo = NULL;
}

void insertar(cola& c, float x) {
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

float borrar(cola& c) {
    if (verVacia(c) == 1) {
        cout << "Error: cola vacía" << endl;
        exit(1);
    } else {
        nodo* p = c.frente;
        float x = p->info;
        c.frente = c.frente->next;
        delete p;

        if (c.frente == NULL)
            c.fondo = NULL;
        return x;
    }
}
