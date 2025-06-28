#ifndef STPILA_H_INCLUDED
#define STPILA_H_INCLUDED

typedef struct stPila {
    int *arreglo;
    int posTope;
} Pila;

void inicpila(Pila *p);
void apilar(Pila *p, int dato);
int desapilar(Pila *p);
int tope(Pila *p);
int base(Pila *p);
void mostrar(Pila *p);
void liberarpila(Pila *p);

#endif // STPILA_H_INCLUDED
