#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "Registros.h"
#include "Opciones.h"

#define TRUE    1
#define FALSE   0

int main()
{
    _listaOpciones* L;

    L = nuevaOpcion();

    char* l[10];
    int a, opc = 0;

    do
    {
        printf("Nombre Opcion: ");
        scanf("%s",l);
        printf("Id Opcion: ");
        scanf("%d",&a);
        printf("seguir? ");
        scanf("%d",&opc);
        insertarOpciones(L,l,a,0,NULL);
    }while(opc != 0);

    listarOpciones(L->inicio);

    /**
        funcion listar para debuger rectificada solo en Opciones.h
                                                                    **/

    return 0;
}
