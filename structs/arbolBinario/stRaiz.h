#ifndef STRAIZ_H_INCLUDED
#define STRAIZ_H_INCLUDED

typedef struct stRaiz {
    struct stRaiz *raizIzquierda;
    int valorActual;
    struct stRaiz *raizDerecha;
} Raiz;

Raiz* inicraiz(void);
Raiz* agragarDato(int dato);
Raiz* validarEntradaDatoEnArbol(Raiz* raizActual, int dato);
void imprimirArbol(Raiz* raizActual, int espacio);
void liberarArbol(Raiz* raizActual);
void imprimirEnPreorden(Raiz* raizActual);
void imprimirEnInorden(Raiz* raizActual);
void imprimirEnPostorden(Raiz* raizActual);

#endif // STRAIZ_H_INCLUDED
