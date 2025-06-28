#include <stdio.h>
#include <stdlib.h>
#include "stNodo.h"

Nodo* iniclista(void){
    return NULL;
}

Nodo* crearNodo(int dato){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->siguienteNodo = NULL;
    aux->dato = dato;

    return aux;
}

Nodo* agregarALista(Nodo* lista, Nodo* nuevo){
    nuevo->siguienteNodo = lista;
    return nuevo;
}

void verificarLista(Nodo** lista){
    int valor;

    printf("Ingrse un dato: ");
    scanf("%d", &valor);

    Nodo *nodoAuxiliar = crearNodo(valor);
    *lista = agregarALista(*lista, nodoAuxiliar);
}

void mostrarLista(Nodo* nodo){
    if(nodo != NULL){
        printf("Direccion nodo: %p\n"
               "Valor dato: %d\n"
               "Direccion siguiente nodo: %p\n", (void*)nodo, nodo->dato, (void*)nodo->siguienteNodo);
        printf("----------------------------------------------------------------------------\n");

        mostrarLista(nodo->siguienteNodo);
    } else {
        printf("Fin de la lista.\n");
    }
}

void liberarLista(Nodo* lista){
    Nodo* actual = lista;
    Nodo* siguiente;

    while(actual != NULL){
        siguiente = actual->siguienteNodo;
        free(actual);
        actual = siguiente;
    }
}
