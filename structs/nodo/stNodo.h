#ifndef STNODO_H_INCLUDED
#define STNODO_H_INCLUDED

typedef struct stNodo {
    int dato;
    struct stNodo *siguienteNodo;
} Nodo;

Nodo* iniclista(void);
Nodo* crearNodo(int dato);
Nodo* agregarALista(Nodo* lista, Nodo* nuevo);
void verificarLista(Nodo** lista);
void mostrarLista(Nodo* nodo);
void liberarLista(Nodo* nodo);

#endif // STNODO_H_INCLUDED
