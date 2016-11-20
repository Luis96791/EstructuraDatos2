#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "Interprete.h"
#include "Bloques.h"
#include "ManejoBloques.h"

#define TRUE    1
#define FALSE   0

void menuTablas(_listaTabla* ptr);
void menuCampos(_nodoTabla* ptrNodoTabla);

void menuTablas(_listaTabla* ptr)
{
    _listaTabla* LT;
    _nodoTabla* temp;
    LT = nuevaTabla();

    int opc = 0, idsTablas = 0;
    char* nombre;
    char* cadena;
    cadena = (char *)malloc(sizeof(char)*2000);

    do
    {
        printf("\n\n\t--Manejo de Tablas--\n\n");
        printf("\t1-. Crear Tabla\n");
        printf("\t2-. Listar Tablas\n");
        printf("\t3-. Escribir en Archivo\n");
        printf("\t4-. Salir\n\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        nombre = (char *)malloc(sizeof(char)*20);

        switch(opc)
        {
            case 1:
                printf("Nombre Tabla: ");
                scanf("%s", nombre);
                insertarTablas(LT, ++idsTablas, nombre, NULL);
                break;
            case 2:
                listarTablas(LT);
                break;
            case 3:
                printf("%s", cadena);
        }
    }while(opc != 4);
    free(nombre);
    free(cadena);
}

menuCampos(_nodoTabla* ptrNodoTabla)
{
    _listaCampos* LC;

    if(ptrNodoTabla->ptrListaCampo == NULL)
    {
        LC = nuevoCampo();
    }
    else{
        LC = ptrNodoTabla->ptrListaCampo;
    }


    char *nombre, *tipo;
    char respuesta;
    int opc = 0;

    do
    {
        printf("\n\n\t--Manejo de Campos--\n\n");
        printf("\t1-. Agregar Campo\n");
        printf("\t2-. Listar Campos\n");
        printf("\t3-. Salir\n\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
                do
                {
                    nombre = (char *)malloc(sizeof(char)*30);
                    tipo = (char *)malloc(sizeof(char)*30);

                    printf("Nombre Campo: ");
                    scanf("%s", nombre);
                    printf("Tipo: ");
                    scanf("%s", tipo);
                    insertarCampos(LC, nombre, tipo);
                    printf("Desea ingresar otro Campo?: ");
                    scanf("%s", &respuesta);
                }while(respuesta == 'S');
                agregarCamposTabla(ptrNodoTabla, LC);
                free(&nombre);
                free(&tipo);
                break;
            case 2:
                listarCampos(ptrNodoTabla->ptrListaCampo);
                break;
        }
    }while(opc != 3);
}

//void menuTablas(_listaTabla* ptr)
//{
//    int opc = 0, idsTablas = 0;
//    char p;
//
//    _listaRegistros* LR;
//
//    do
//    {
//        printf("\n\n\t--Manejo de Tablas--\n\n");
//        printf("\t1-. Crear Tabla\n");
//        printf("\t2-. Listar Tablas\n");
//        printf("\t3-. Listar Campos por Tabla\n");
//        printf("\t4-. Agregar Registros\n");
//        printf("\t5-. Listar Registros\n");
//        printf("\t6-. Salir\n");
//        printf("Ingrese Opcion: ");
//        scanf("%d", &opc);
//
//        char* nombreTabla = (char *)malloc(sizeof(char)*20);
//        char* buscaTabla = (char *)malloc(sizeof(char)*20);
//        char* ingresoTabla = (char *)malloc(sizeof(char)*20);
//        char* ingresoListar = (char *)malloc(sizeof(char)*20);
//        char quest;
//
//        switch(opc)
//        {
//            case 1:
//                printf("\tNombre Tabla: ");
//                scanf("%s", nombreTabla);
//                _listaCampos* LC;
//                LC = nuevoCampo();
//                LR = nuevoRegistro();
//                do
//                {
//                    char* nombreCampo = (char *)malloc(sizeof(char)*20);
//                    char* tipo = (char *)malloc(sizeof(char)*20);
//
//                    printf("Desea Ingresar un Campo? ");
//                    scanf("%s", &p);
//                    if(p == 'S')
//                    {
//                        printf("Nombre Campo: ");
//                        scanf("%s",nombreCampo);
//                        printf("Tipo: ");
//                        scanf("%s",tipo);
//                        insertarCampos(LC, nombreCampo,tipo);
//                    }
//                }while(p == 'S');
//                insertarTablas(ptr, ++idsTablas, nombreTabla, LC);
//                break;
//            case 2:
//                printf("--Todas las Tablas--\n\n");
//                listarTablas(ptr->inicio);
//                break;
//            case 3:
//                printf("--Campos por Tabla--\n\n");
//                printf("Nombre Tabla: ");
//                scanf("%s", buscaTabla);
//                _nodoTabla* temp = buscarTabla(ptr, buscaTabla);
//                listarCampos(temp->ptrListaCampo->inicio);
//                break;
//            case 4:
//                printf("\n--Crear Registro--\n\n");
//                printf("A que tabla desea Agregar Registros? ");
//                scanf("%s", ingresoTabla);
//                _nodoTabla* temporal = buscarTabla(ptr, ingresoTabla);
//               if(temporal != NULL)
//               {
//                   _listaCampos* camposTemporales = temporal->ptrListaCampo;
//                   _listaDescCampos* DC;
//                   DC = nuevaDesCampos();
//                   _nodoCampo* campo = camposTemporales->inicio;
//                   while(campo != NULL)
//                   {
//                       char* ingreso = (char *)malloc(sizeof(char)*20);
//                       printf("Ingrese para %s\t%s: ", campo->nombre_campo, campo->tipo);
//                       scanf("\n%s", ingreso);
//                       insertarDesCampos(DC, ingreso);
//                       campo = campo->siguiente;
//                   }
//                   insertarRegistros(LR, DC);
//                   modificarRegistroATabla(ptr, LR, ingresoTabla);
//               }
//               break;
//            case 5:
//                printf("\n--Listar Registros--\n\n");
//                printf("Ingrese Tabla para Listar Registros: ");
//                scanf("%s",ingresoListar);
//                _nodoTabla* tablaTemp = buscarTabla(ptr, ingresoListar);
//                if(tablaTemp != NULL)
//                {
//                    listarRegistros(tablaTemp->ptrListaRegistro->inicio);
//                }
//                break;
//        }
//    }while(opc != 6);
//}

int main()
{
    _listaTabla* T;
    T = nuevaTabla();
    menuTablas(T);
    return 0;
}
