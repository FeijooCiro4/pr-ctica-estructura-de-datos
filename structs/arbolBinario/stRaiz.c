#include <stdio.h>
#include <stdlib.h>
#include "stRaiz.h"

Raiz* inicraiz(){
    return NULL;
}

Raiz* agragarDato(int dato){
    Raiz* raizActual = (Raiz*)malloc(sizeof(Raiz));
    raizActual->valorActual = dato;
    raizActual->raizDerecha = NULL;
    raizActual->raizIzquierda = NULL;

    return raizActual;
}

Raiz* validarEntradaDatoEnArbol(Raiz* raizActual, int dato){
    if(raizActual == NULL){
        return agragarDato(dato);
    }

    if(dato <= raizActual->valorActual){
        raizActual->raizIzquierda = validarEntradaDatoEnArbol(raizActual->raizIzquierda, dato);
    } else if(dato > raizActual->valorActual){
        raizActual->raizDerecha = validarEntradaDatoEnArbol(raizActual->raizDerecha, dato);
    }

    return raizActual;
}

void imprimirArbol(Raiz* raizActual, int espacio){
    if(raizActual == NULL){
        return;
    }

    espacio += 10;

    imprimirArbol(raizActual->raizIzquierda, espacio);

    printf("\n");
    for(int i=10; i<espacio; i++){
        printf(" ");
    }
    printf("%d\n", raizActual->valorActual);

    imprimirArbol(raizActual->raizDerecha, espacio);
}

void liberarArbol(Raiz* raizActual){
    if(raizActual != NULL){
        if(raizActual->raizDerecha != NULL) liberarArbol(raizActual->raizDerecha);
        if(raizActual->raizIzquierda != NULL) liberarArbol(raizActual->raizIzquierda);
        free(raizActual);
    }
}

void imprimirEnPreorden(Raiz* raizActual){
    printf("| %d ", raizActual->valorActual);
    if(raizActual->raizIzquierda != NULL) imprimirEnPreorden(raizActual->raizIzquierda);
    if(raizActual->raizDerecha != NULL) imprimirEnPreorden(raizActual->raizDerecha);
}

void imprimirEnInorden(Raiz* raizActual){
    if(raizActual->raizIzquierda != NULL) imprimirEnInorden(raizActual->raizIzquierda);
    printf("| %d ", raizActual->valorActual);
    if(raizActual->raizDerecha != NULL) imprimirEnInorden(raizActual->raizDerecha);
}

void imprimirEnPostorden(Raiz* raizActual){
    if(raizActual->raizIzquierda != NULL) imprimirEnPostorden(raizActual->raizIzquierda);
    if(raizActual->raizDerecha != NULL) imprimirEnPostorden(raizActual->raizDerecha);
    printf("| %d ", raizActual->valorActual);
}
