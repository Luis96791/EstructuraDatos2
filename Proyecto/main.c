#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bloques.h"
#include "BloquesTablas.h"

#define TRUE    1
#define FALSE   0

void menuTablas(_listaTablas* listaTablas);

void menuTablas(_listaTablas* listaTablas)
{
    char* nombre;
    int opc;

    do
    {
        printf("\n -- Manejo Tablas --\n\n");
        printf("\t1-. Agregar Tabla\n");
        printf("\t2-. Listar Tablas\n");
        printf("\t3-. Cantidad Tablas\n");
        printf("\t4-. Salir\n\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        nombre = (char *)malloc(sizeof(char)*20);

        switch(opc)
        {
            case 1:
                printf("Nombre Tabla: ");
                scanf("%s", nombre);
                agregarTabla(nombre, listaTablas, 0, 0);
                break;
            case 2:
                listarTablas(listaTablas);
                break;
            case 3:
                printf("%d", getSizeListaTablas(listaTablas));
                break;
        }
    }while(opc != 4);
}


int main()
{
    system("color B");
    _listaTablas* listaTablas;
    listaTablas = nuevaListaTablas();

    menuTablas(listaTablas);
    return 0;
}
