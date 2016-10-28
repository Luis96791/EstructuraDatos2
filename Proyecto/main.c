#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "Registros.h"
#include "Opciones.h"
#include "Interprete.h"

#define TRUE    1
#define FALSE   0

int main()
{
    _listaOpciones* L;

    L = nuevaOpcion();

    int a, opc = 0;

    char* src;
    char* dest;


    do
    {
        printf("Nombre Opcion: ");
        scanf("%s",&src);
        memmove(&dest, &src, 20);
        printf("Id Opcion: ");
        scanf("%d",&a);
        printf("seguir? ");
        scanf("%d",&opc);
        insertarOpciones(L, dest, a, 0, NULL);
    }while(opc != 0);

    listarOpciones(L->inicio);

    /**
        funcion listar para debuger rectificada solo en Opciones.h
                                                                    **/

    return 0;
}
