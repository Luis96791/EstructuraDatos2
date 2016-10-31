#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"

#define TRUE    1
#define FALSE   0


void menuTablas(_listaTabla* ptr);
void menuCampos(_listaCampos* ptr, _nodoTabla* ptrNodoTabla);


void menuTablas(_listaTabla* ptr)
{
    int opc = 0, idsTablas = 0;
    char p;

    _listaRegistros* LR;

    do
    {
        printf("\n\n\t--Manejo de Tablas--\n\n");
        printf("\t1-. Crear Tabla\n");
        printf("\t2-. Listar Tablas\n");
        printf("\t3-. Listar Campos por Tabla\n");
        printf("\t4-. Agregar Registros\n");
        printf("\t5-. Listar Registros\n");
        printf("\t6-. Salir\n");
        printf("Ingrese Opcion: ");
        scanf("%d", &opc);

        char* nombreTabla = (char *)malloc(sizeof(char)*20);
        char* buscaTabla = (char *)malloc(sizeof(char)*20);
        char* ingresoTabla = (char *)malloc(sizeof(char)*20);
        char* ingresoListar = (char *)malloc(sizeof(char)*20);
        char quest;

        switch(opc)
        {
            case 1:
                printf("\tNombre Tabla: ");
                scanf("%s", nombreTabla);
                _listaCampos* LC;
                LC = nuevoCampo();
                LR = nuevoRegistro();
                do
                {
                    char* nombreCampo = (char *)malloc(sizeof(char)*20);
                    char* tipo = (char *)malloc(sizeof(char)*20);

                    printf("Desea Ingresar un Campo? ");
                    scanf("%s", &p);
                    if(p == 'S')
                    {
                        printf("Nombre Campo: ");
                        scanf("%s",nombreCampo);
                        printf("Tipo: ");
                        scanf("%s",tipo);
                        insertarCampos(LC, nombreCampo,tipo);
                    }
                }while(p == 'S');
                insertarTablas(ptr, ++idsTablas, nombreTabla, LC);
                break;
            case 2:
                printf("--Todas las Tablas--\n\n");
                listarTablas(ptr->inicio);
                break;
            case 3:
                printf("--Campos por Tabla--\n\n");
                printf("Nombre Tabla: ");
                scanf("%s", buscaTabla);
                _nodoTabla* temp = buscarTabla(ptr, buscaTabla);
                listarCampos(temp->ptrListaCampo->inicio);
                break;
            case 4:
                printf("\n--Crear Registro--\n\n");
                printf("A que tabla desea Agregar Registros? ");
                scanf("%s", ingresoTabla);
                _nodoTabla* temporal = buscarTabla(ptr, ingresoTabla);
               if(temporal != NULL)
               {
                   _listaCampos* camposTemporales = temporal->ptrListaCampo;
                   _listaDescCampos* DC;
                   DC = nuevaDesCampos();
                   _nodoCampo* campo = camposTemporales->inicio;
                   while(campo != NULL)
                   {
                       char* ingreso = (char *)malloc(sizeof(char)*20);
                       printf("Ingrese para %s\t%s: ", campo->nombre_campo, campo->tipo);
                       scanf("\n%s", ingreso);
                       insertarDesCampos(DC, ingreso);
                       campo = campo->siguiente;
                   }
                   insertarRegistros(LR, DC);
                   modificarRegistroATabla(ptr, LR, ingresoTabla);
               }
               break;
            case 5:
                printf("\n--Listar Registros--\n\n");
                printf("Ingrese Tabla para Listar Registros: ");
                scanf("%s",ingresoListar);
                _nodoTabla* tablaTemp = buscarTabla(ptr, ingresoListar);
                if(tablaTemp != NULL)
                {
                    listarRegistros(tablaTemp->ptrListaRegistro->inicio);
                }
                break;
        }
    }while(opc != 6);
}

int main()
{
    _listaTabla* T;
    T = nuevaTabla();

    menuTablas(T);
    return 0;
}
