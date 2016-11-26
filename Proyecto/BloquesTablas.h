#ifndef BLOQUESTABLAS_H
#define BLOQUESTABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tabla _tabla;
typedef struct ListaTablas _listaTablas;

struct Tabla
{
    char* nombreTabla;
    int primerBloqueCampos;
    int primerBloqueRegistros;
    _tabla* siguiente;
};

struct ListaTablas
{
    _tabla* inicio;
};

/** -------------------- Funciones ---------------------- **/
_listaTablas* nuevaListaTablas();
void agregarTabla(char* nombreTabla, _listaTablas* listaTablas, int pBC, int pBR);
void agregarTablaLista(_tabla* tabla, _listaTablas* listaTablas);
void listarTablas(_listaTablas* listaTablas);
int getSizeListaTablas(_listaTablas* listaTablas);
/** -------------------- Funciones ---------------------- **/



_listaTablas* nuevaListaTablas()
{
    _listaTablas* listaTablas;

    listaTablas = (_listaTablas *)malloc(sizeof(_listaTablas));
    listaTablas->inicio = NULL;

    return listaTablas;
}

void agregarTabla(char* nombreTabla, _listaTablas* listaTablas, int pBC, int pBR)
{
    _tabla* tabla;

    tabla = (_tabla *)malloc(sizeof(_tabla));
    tabla->nombreTabla = nombreTabla;
    tabla->primerBloqueCampos = pBC;
    tabla->primerBloqueRegistros = pBR;
    tabla->siguiente = NULL;

    agregarTablaLista(tabla, listaTablas);
}

void agregarTablaLista(_tabla* tabla, _listaTablas* listaTablas)
{
    _tabla* temporal;

    if(listaTablas->inicio == NULL)
    {
        listaTablas->inicio = tabla;
        return;
    }
    temporal = listaTablas->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = tabla;
}

void listarTablas(_listaTablas* listaTablas)
{
    _tabla* temporal = listaTablas->inicio;

    while(temporal != NULL)
    {
        printf("%s , %d , %d\n", temporal->nombreTabla, temporal->primerBloqueCampos, temporal->primerBloqueRegistros);
        temporal = temporal->siguiente;
    }
}

int getSizeListaTablas(_listaTablas* listaTablas)
{
    int contador = 0;
    _tabla* temporal = listaTablas->inicio;

    if(temporal == NULL)
    {
        return contador;
    }
    else{
        while(temporal != NULL)
        {
            contador++;
            temporal = temporal->siguiente;
        }
    }
    return contador;
}

//_tabla* getUltimotabla(_listaTablas* listaTablas)
//{
//    _tabla* temporal = listaTablas->inicio;
//
//    if(temporal == NULL)
//    {
//        return NULL;
//    }
//    else{
//        while( 1 )
//        {
//            if(temporal->siguiente == NULL)
//            {
//                return temporal;
//            }
//            else{
//                temporal = temporal->siguiente;
//            }
//        }
//    }
//}

#endif // BLOQUESTABLAS_H
