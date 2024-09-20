#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Pila {
    char elementos[MAX];
    int tope;
};

void inicializarPila(struct Pila *p) {
    p->tope = -1;
}

int esVacia(struct Pila *p) {
    return p->tope == -1;
}
int esLlena(struct Pila *p) {
    return p->tope == MAX - 1;
}

void apilar(struct Pila *p, char elemento) {
    if (!esLlena(p)) {
        p->elementos[++p->tope] = elemento;
    } else {
        printf("Error: la pila está llena.\n");
    }
}

char desapilar(struct Pila *p) {
    if (!esVacia(p)) {
        return p->elementos[p->tope--];
    } else {
        printf("Error: la pila está vacía.\n");
        return '\0';
    }
}

char obtenerTope(struct Pila *p) {
    if (!esVacia(p)) {
        return p->elementos[p->tope];
    } else {
        printf("Error: la pila está vacía.\n");
        return '\0';
    }
}

void mal() {
    printf("No balanceado\n");
    exit(1);
}

void verificarCierre(struct Pila *p, char cierre) {
    if (esVacia(p)) {
        mal();
    }

    char apertura = desapilar(p);
    if ((apertura == '(' && cierre != ')') ||
        (apertura == '[' && cierre != ']') ||
        (apertura == '{' && cierre != '}')) {
        mal();
    }
}

int main() {
    struct Pila pila;
    inicializarPila(&pila);

    char cadena[MAX];
    printf("Introduce una cadena: ");
    scanf("%s", cadena);
    int tam = strlen(cadena);

    for (int i = 0; i < tam; i++) {
        if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
            apilar(&pila, cadena[i]); // Apilar si es un carácter de apertura
        } 
        else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
            verificarCierre(&pila, cadena[i]); // Verificar cierre
        }
    }

    if (!esVacia(&pila)) {
        mal();
    } else {
        printf("Balanceado\n");
    }

    return 0;
}