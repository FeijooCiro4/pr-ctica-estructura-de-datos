#include <stdlib.h>
#include <stdio.h>
#include "stPila.h"

#define VALOR_DIMENSIONAMIENTO_PILA 5

void inicpila(Pila *p){
    p->arreglo = (int*)malloc(VALOR_DIMENSIONAMIENTO_PILA*sizeof(int));
    p->dimension = VALOR_DIMENSIONAMIENTO_PILA;

    if(p->arreglo == NULL){
        printf("\nError al inicializar pila.\n");
        return;
    }

    p->posTope = 0;
}

void apilar(Pila *p, int dato){
    if(p->posTope >= p->dimension){
        p->arreglo = (int*)realloc(p->arreglo, (p->dimension + VALOR_DIMENSIONAMIENTO_PILA) * sizeof(int));
        p->dimension += VALOR_DIMENSIONAMIENTO_PILA;
    }
    p->arreglo[p->posTope] = dato;
    p->posTope += 1;
}

int desapilar(Pila *p){
    int aux = p->arreglo[p->posTope-1];
    p->arreglo[p->posTope-1] = 0;
    p->posTope--;

    return aux;
}

int tope(Pila *p){
    return p->arreglo[p->posTope-1];
}

int base(Pila *p){
    return p->arreglo[0];
}

void mostrar(Pila *p){
    printf("\nBase +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Tope\n\t");
    printf("| %d | ", p->arreglo[0]);
    for(int i=1; i<p->posTope-1; i++){
        printf("%d | ", p->arreglo[i]);
    }
    printf("%d |", p->arreglo[p->posTope-1]);
    printf("\nBase +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Tope\n\n");
}

void liberarpila(Pila *p){
    free(p->arreglo);
    p->arreglo = NULL;
    p->posTope = 0;
}

int pilavacia(Pila *p){
    return (p->posTope == 0);
}
