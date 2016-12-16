#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Arbol_B.h"

int main()
{
    _nodoArbolB* nodoArbolB;
    nodoArbolB = crearArbolB();
    int opc = 0, numero;

    do{
        printf("\n\t1-. Agregar Nodo\n");
        printf("\t2-. Buscar Nodo\n");
        printf("\t3-. Eliminar Nodo\n");
        printf("\t4-. Salir\n\n");
        printf("Escoja una opcion: ");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
                printf("Ingrese Numero: ");
                scanf("%d", &numero);
                agregarNodoEnArbolB(nodoArbolB, numero);
                break;
            case 2:
                printf("Ingrese Numero a Buscar: ");
                scanf("%d", &numero);
                buscarEnArbol(nodoArbolB, numero);
                break;
            case 3:
                printf("Ingrese Nodo a Eliminar: ");
                scanf("%d", &numero);
                eliminarNodo(nodoArbolB, numero);
                break;
        }

    }while(opc != 4);

    return 0;
}
