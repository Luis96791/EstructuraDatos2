#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interprete.h"
#include "Tablas.h"
#include "Campos.h"
#include "Registros.h"
#include "BloqueTablas.h"
#include "BloqueCampos.h"
#include "BloqueRegistros.h"
#include "bloqueHash.h"

#define TRUE    1
#define FALSE   0
#define HASH    10

void menuTablas(_listaTablas* listaTablas, _listaBloqueTablas* listaBloqueTablas, LBloqueHash* LBT);
void menuCampos(_tabla* tabla);
void menuRegistros(_tabla* tabla, LBloqueHash* LBT);

void menuTablas(_listaTablas* listaTablas, _listaBloqueTablas* listaBloqueTablas, LBloqueHash* LBT)
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
                tablaTemporal = agregarTabla(nombre_tabla, listaTablas, 0, 0);
                escribirTablaEnArchivo(tablaTemporal);
                break;
            case 2:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                tablaTemporal = buscarTabla(nombre_tabla, listaTablas);
                escribirTablaEnArchivo(tablaTemporal);
                if(tablaTemporal != NULL)
                {
                    menuCampos(tablaTemporal);
                }
                break;
            case 3:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                tablaTemporal = buscarTabla(nombre_tabla, listaTablas);
                if(tablaTemporal != NULL)
                {
                    menuRegistros(tablaTemporal,LBT);
                }
                break;
            case 4:
                listarTablas(listaTablas);
                break;
            case 5:
                printf("%d", getSizeListaTablas(listaTablas));
                break;
            case 6:
                listarBloqueTablas(listaBloqueTablas);
                break;
            case 7:
                printf("Nombre Tabla: ");
                scanf("%s", nombre_tabla);
                buscarTabla(nombre_tabla, listaTablas);
                break;
        }
    }while(opc != 8);
}

void menuCampos(_tabla* tabla)
{
    _campo* campoTemporal;
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
                if(tabla->listaRegistros->inicio == NULL)
                {
                    do
                    {
                        nombre_campo = (char *)malloc(sizeof(char)*20);
                        tipo_campo = (char *)malloc(sizeof(char)*20);
                        if(tabla->listaCampos->inicio==NULL){
                            campoTemporal = agregarCampo(tabla->listaCampos, "Indice", "texto");
                            agregarCamposEnBloqueCampos(campoTemporal, tabla->listaBloqueCampos, 0, 0, 3);
                        }
                        printf("Nombre Campo: ");
                        scanf("%s", nombre_campo);
                        printf("Tipo Campo: ");
                        scanf("%s", tipo_campo);
                        campoTemporal = agregarCampo(tabla->listaCampos, nombre_campo, tipo_campo);
                        agregarCamposEnBloqueCampos(campoTemporal, tabla->listaBloqueCampos, 0, 0, 3);
                        printf("Desea agregar otro Campo? ");
                        scanf("%s", &resp);
                    }while(resp == 'S');
                }
                else{
                    printf("\n\nNo se pueden agregar mas campos a la tabla ( %s ) por que ya contiene registros\n\n", tabla->nombreTabla);
                }
                break;
            case 2:
                listarCampos(tabla->listaCampos);
                listarBloqueCampos(tabla->listaBloqueCampos);
                break;
        }

    }while(opc != 3);
}

void menuRegistros(_tabla* tabla, LBloqueHash* LBT)
{
    _campo* campoTemporal;
    _campoDato* campoDatoTemporal;
    _registro* registroTemporal;
    char* datoCampo;
    int opc;
    int veces = 0;
    do
    {
        veces = 0;
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
                registroTemporal = agregarRegistro(tabla->listaRegistros, 0);
                agregarRegistroEnBloqueRegistros(registroTemporal, tabla->listaBloqueRegistros, 0, 0, 3);

                while(campoTemporal != NULL)
                {
                    datoCampo = (char *)malloc(sizeof(char)*20);
                    if(veces==1){
                        printf("Ingresar dato para campo %s : ", campoTemporal->nombre_campo);
                        scanf("%s", datoCampo);
                    }
                    while(veces==0){
                        printf("Ingresar indice(Debe ser de 5 caracteres): ");
                        scanf("%s", datoCampo);
                        agregarAlBloqueNum(LBT,Hash(datoCampo,HASH),datoCampo,tabla);
                        veces++;
                    }
                    campoDatoTemporal = agregarCampoDato(registroTemporal->listaCampoDatos, datoCampo, campoTemporal);
                    agregarCampoDatoEnBloqueCampoDatos(campoDatoTemporal, registroTemporal->listaBloqueCampoDatos, 0, 0, 3);
                    campoTemporal = campoTemporal->siguiente;
                }

                break;
            case 2:
                listarRegistros(tabla->listaRegistros);
//                listarBloqueRegistros(tabla->listaBloqueRegistros);
                break;
        }
    }while(opc != 3);
    guardarListaBloque(LBT);
}

int main()
{
    system("color A");
    _listaTablas* listaTablas;
    _listaBloqueTablas* listaBloqueTablas;
    listaTablas = nuevaListaTablas();
    listaBloqueTablas = nuevaListaBloqueTablas();

    LBloqueHash* LBT;
    LBT = nuevaListaBloqueHasgh();
    inicializarHash(LBT,HASH);
    cargarListaHash(LBT,HASH);
    menuTablas(listaTablas, listaBloqueTablas,LBT);
    return 0;
}
