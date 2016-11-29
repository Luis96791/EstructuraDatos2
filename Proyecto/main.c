#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interprete.h"
#include "Bloques.h"
#include "Tablas.h"
#include "Campos.h"
#include "Registros.h"

#define TRUE    1
#define FALSE   0

void menuTablas(_listaTablas* listaTablas, _listaBloques* listaBloques);
void menuCampos(_tabla* tabla, _listaBloques* listaBloques);
void menuRegistros(_tabla* tabla);

void menuTablas(_listaTablas* listaTablas, _listaBloques* listaBloques)
{
    _tabla* tablaTemporal;
    char* nombre_tabla;
    int opc;

    do
    {
        printf("\n -- Manejo Tablas --\n\n");

        char* dataFile = (char *)malloc(sizeof(char)*1000);
        char* nombre_archivo = "json.txt";
        cargarJson(dataFile, nombre_archivo);

        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        nombre_tabla = (char *)malloc(sizeof(char)*20);

        switch(opc)
        {
            case 1:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                agregarTabla(nombre_tabla, listaTablas, 0, 0);
                agregarTabla_ABloque(nombre_tabla, listaBloques, 0, 0, 3);
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
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                tablaTemporal = buscarTabla(nombre_tabla, listaTablas);
                if(tablaTemporal != NULL)
                {
                    menuRegistros(tablaTemporal);
                }
                break;
            case 4:
                listarTablas(listaTablas);
                break;
            case 5:
                printf("%d", getSizeListaTablas(listaTablas));
                break;
            case 6:
                listarBloques(listaBloques);
                break;
            case 7:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                buscarTabla(nombre_tabla, listaTablas);
                break;
        }
    }while(opc != 8);
}

void menuCampos(_tabla* tabla, _listaBloques* listaBloques)
{
    char* nombre_campo;
    char* tipo_campo;
    char resp;
    int opc;

    do
    {
        printf("-- Administrar Campos para la Tabla: %s --\n\n", tabla->nombreTabla);
        printf("\t1-. Agregar Campo\n");
        printf("\t2-. Listar Campos\n");
        printf("\t3-. Salir\n\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
                if(tabla->listaCampos->inicio == NULL)
                {
                    agregarBloqueCampo(listaBloques, 15);

                    do
                    {
                        nombre_campo = (char *)malloc(sizeof(char)*20);
                        tipo_campo = (char *)malloc(sizeof(char)*20);

                        printf("Nombre Campo: ");
                        scanf("%s", nombre_campo);
                        printf("Tipo Campo: ");
                        scanf("%s", tipo_campo);
                        agregarCampo(tabla->listaCampos, nombre_campo, tipo_campo);
                        agregarCampo_ABloque(nombre_campo, tipo_campo, listaBloques, 15);
                        printf("Desea agregar otro Campo? ");
                        scanf("%s", &resp);
                    }while(resp == 'S');
                }
                else{
                    printf("\n\nNo se pueden agregar mas campos a la tabla: %s \n\n", tabla->nombreTabla);
                }
                break;
            case 2:
                listarCampos(tabla->listaCampos);
                break;
        }

    }while(opc != 3);
}

void menuRegistros(_tabla* tabla)
{
    _campo* campoTemporal;
    _registro* registroTemporal;
    char* datoCampo;
    int opc;

    do
    {

        printf("-- Administrar Registros para la Tabla: %s --\n\n", tabla->nombreTabla);
        printf("\t1-. Agregar Registro\n");
        printf("\t2-. Listar Registros\n");
        printf("\t3-. Salir\n\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
                campoTemporal = tabla->listaCampos->inicio;
                registroTemporal = agregarRegistro(tabla->listaRegistros, 1);
                while(campoTemporal != NULL)
                {
                    datoCampo = (char *)malloc(sizeof(char)*20);
                    printf("Ingresar dato para campo %s : ", campoTemporal->nombre_campo);
                    scanf("%s", datoCampo);
                    agregarCampoDato(registroTemporal->listaCampoDatos, datoCampo, campoTemporal);
                    campoTemporal = campoTemporal->siguiente;
                }
                break;
            case 2:
                listarRegistros(tabla->listaRegistros);
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
