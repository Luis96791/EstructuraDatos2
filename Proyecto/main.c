#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bloques.h"
#include "Tablas.h"
#include "Campos.h"

#define TRUE    1
#define FALSE   0

void menuTablas(_listaTablas* listaTablas, _listaBloques* listaBloques);
void menuCampos(_tabla* tabla, _listaBloques* listaBloques);

void menuTablas(_listaTablas* listaTablas, _listaBloques* listaBloques)
{
    _tabla* tablaTemporal;
    char* nombre_tabla;
    int opc;

    do
    {
        printf("\n -- Manejo Tablas --\n\n");
        printf("\t1-. Agregar Tabla\n");
        printf("\t2-. Administrar Campos\n");
        printf("\t3-. Listar Tablas\n");
        printf("\t4-. Cantidad Tablas\n");
        printf("\t5-. Listar Bloques\n");
        printf("\t6-. Buscar Tabla\n");
        printf("\t7-. Salir\n\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        nombre_tabla = (char *)malloc(sizeof(char)*20);

        switch(opc)
        {
            case 1:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                agregarTabla(nombre_tabla, listaTablas, 0, 0);
                agregarTabla_ABloque(nombre_tabla, listaBloques, 0, 0, 2);
                break;
            case 2:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                tablaTemporal = buscarTabla(nombre_tabla, listaTablas);
                if(tablaTemporal != NULL)
                {
                    menuCampos(tablaTemporal, listaBloques);
                }
                break;
            case 3:
                listarTablas(listaTablas);
                break;
            case 4:
                printf("%d", getSizeListaTablas(listaTablas));
                break;
            case 5:
                listarBloques(listaBloques);
                break;
            case 6:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                buscarTabla(nombre_tabla, listaTablas);
                break;
        }
    }while(opc != 7);
}

void menuCampos(_tabla* tabla, _listaBloques* listaBloques)
{
    char* nombre_campo;
    char* tipo_campo;
    int opc;

    do
    {
        printf("-- Administrar Campos para la Tabla: %s --\n\n", tabla->nombreTabla);
        printf("\t1-. Agregar Campo\n");
        printf("\t2-. Listar Campos\n");
        printf("\t3-. Salir\n\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        nombre_campo = (char *)malloc(sizeof(char)*20);
        tipo_campo = (char *)malloc(sizeof(char)*20);

        switch(opc)
        {
            case 1:
                printf("Nombre Campo: ");
                scanf("%s", nombre_campo);
                printf("Tipo Campo: ");
                scanf("%s", tipo_campo);
                agregarCampo(tabla->listaCampos, nombre_campo, tipo_campo);
                agregarCampo_ABloque(nombre_campo, tipo_campo, listaBloques, 3);
                break;
            case 2:
                listarCampos(tabla->listaCampos);
                break;
        }

    }while(opc != 3);
}

int main()
{
    system("color A");
    _listaTablas* listaTablas;
    _listaBloques* listaBloques;
    listaTablas = nuevaListaTablas();
    listaBloques = nuevaListaBloques();

    menuTablas(listaTablas, listaBloques);
    return 0;
}
