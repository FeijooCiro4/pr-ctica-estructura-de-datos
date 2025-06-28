#include <stdio.h>
#include <stdlib.h>

#include "structs/pila/stPila.h"
#include "structs/nodo/stNodo.h"
#include "structs/arbolBinario/stRaiz.h"

void limpiarPantalla(void);
void printMenu(void);
void opcMenu(int opc);
void gestionPilas(void);
void gestionLista(void);
void gestionArbol(void);

int main() {
    int opc;

    do {
        printMenu();
        scanf("%d", &opc);
        opcMenu(opc);
    } while(opc != 0);

    return 0;
}

void limpiarPantalla(){
    system("pause");
    system("cls");
}

void printMenu(void){
    printf("OPCIONES DE GESTION\n"
           "\t1. Gestionar pilas.\n"
           "\t2. Gestionar lista.\n"
           "\t3. Gestionar arbol binario.\n"
           "\t0. Salir.\n"
           "Ingrese una opcion: ");
}

void opcMenu(int opc){
    switch(opc){
    case 1:
        gestionPilas();
        limpiarPantalla();
        break;
    case 2:
        gestionLista();
        limpiarPantalla();
        break;
    case 3:
        gestionArbol();
        limpiarPantalla();
        break;
    case 0:
        printf("Saliendo...\n");
        break;
    default:
        printf("Opcion invalida.\n");
        limpiarPantalla();
        break;
    }
}

void gestionPilas(){
    Pila pilaPrueba;
    int cantValores;

    inicpila(&pilaPrueba);

    printf("Ingrese la cantidad de valores a ingresar en una pila: \n");
    scanf("%d", &cantValores);

    for(int i=0; i<cantValores; i++){
        int valor;

        printf("\nIngrese el valor Nro %d: ", i);
        fflush(stdin);
        scanf("%d", &valor);

        apilar(&pilaPrueba, valor);
    }

    mostrar(&pilaPrueba);

    system("pause");

    printf("Valor tope: %d\nValor base: %d\n", tope(&pilaPrueba), base(&pilaPrueba));
    printf("Desapilado: %d", desapilar(&pilaPrueba));

    mostrar(&pilaPrueba);

    liberarpila(&pilaPrueba);
}

void gestionLista(){
    Nodo* lista = iniclista();
    int cantValores;

    printf("Ingrese la cantidad de valores a ingresar en la lista enlazada: ");
    scanf("%d", &cantValores);

    for(int i=0; i<cantValores; i++){
        verificarLista(&lista);
    }

    limpiarPantalla();
    printf("\t\t\tMUESTRA DE LA LISTA RESULTANTE.\n\n");
    mostrarLista(lista);
    liberarLista(lista);
}

void gestionArbol(){
    Raiz* arbol = inicraiz();

    int cantValores;

    printf("Ingrese la cantidad de valores a ingresar en el arbol binario: ");
    scanf("%d", &cantValores);

    for(int i=0; i<cantValores; i++){
        int valor;
        printf("Ingrese un valor: ");
        scanf("%d", &valor);
        arbol= validarEntradaDatoEnArbol(arbol, valor);
    }

    limpiarPantalla();

    printf("\t\t\tMUESTRA DEL ARBOL BINARIO.\n\n");
    imprimirArbol(arbol, 0);

    printf("\nPost-orden: \n");
    imprimirEnPreorden(arbol);

    printf("\nIn-orden: \n");
    imprimirEnInorden(arbol);

    printf("\nPre-orden: \n");
    imprimirEnPostorden(arbol);

    printf("\n\n");

    liberarArbol(arbol);
}
